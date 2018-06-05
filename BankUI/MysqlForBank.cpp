#include "StdAfx.h"
#include "MysqlForBank.h"
#include "Transfer.h"
#include "BankUIDlg.h"
//------静态变量声明
Mysql_Op CMysqlForBank::DB;
//
CMysqlForBank::CMysqlForBank(void)
{
}
CMysqlForBank::~CMysqlForBank(void)
{
}
//专门的登陆sql函数
//传入账号密码，若正确则初始化card类型，返回true ，否则返回false
//  status 1冻结 status 2 密码错误 账号正确
//  status 3 账号都不存在
bool CMysqlForBank::Login(CString Cardnumber,CString CardPwd,int &status){
		status=-1;
		CString sql;
		sql.Format(_T("select * from card where cardNum='%s' and cardPwd='%s'"),Cardnumber,CardPwd);
		
		CString sql1;
		sql1.Format(_T("select * from card where cardNum='%s'"),Cardnumber);


		if(DB.ExeSqlWithoutRes(ConvertCStringToString(sql))) {
			//登陆成功 此时将DB里面所有的值都赋给card
			DB.result=DB.ExeSqlWithRes(ConvertCStringToString(sql));
			DB.sql_row=mysql_fetch_row(DB.result);
			CBankUIDlg::CurrentCard.id=DB.sql_row[0];
			CBankUIDlg::CurrentCard.cardNum=DB.sql_row[1];
			CBankUIDlg::CurrentCard.cardPwd=DB.sql_row[2];
			CBankUIDlg::CurrentCard.balance=DB.sql_row[3];
			CBankUIDlg::CurrentCard.userName=DB.sql_row[4];
			CBankUIDlg::CurrentCard.idNum=DB.sql_row[5];
			CBankUIDlg::CurrentCard.cardType=DB.sql_row[6];
			CBankUIDlg::CurrentCard.credit=DB.sql_row[7];
			CBankUIDlg::CurrentCard.status=DB.sql_row[8];
			CBankUIDlg::CurrentCard.add_time=DB.sql_row[9];
			//保存到UI的card静态类里面！！
			//判断是不是冻结状态
			if(CBankUIDlg::CurrentCard.status=="1"){
				//正常登陆			
				return true;
			}else{
				//冻结错误
				status=1;
				return false;
			}
			
		}else if(DB.ExeSqlWithoutRes(ConvertCStringToString(sql1))){
			//到这一步肯定 密码错误 账号正确
			//登陆次数加一 达到一定次数就冻结
			status=2;
			CBankUIDlg::m_LogInTimes +=1;
			return false;
		}else{
			//到这一步账号也不存在
			status=3;
			return false;
		
		}		
}

//专门的存款sql语句
//输入存款金额，返回bool
bool CMysqlForBank::Deposite(double money){
	//存入金额不符合规范	
	if(money <= 0) return false;
	//当前卡的id
	CString currentid=CBankUIDlg::CurrentCard.id;
	CString sql;
	CString s=CBankUIDlg::CurrentCard.balance;
	sql.Format(_T("update card set balance = balance + %f where id = %s"),money,currentid);
		if(DB.Update(ConvertCStringToString(sql))){
			//改Card的余额值
			CBankUIDlg::CurrentCard.balance=AddCStringAnddouble(CBankUIDlg::CurrentCard.balance,money,0);
			CString sql2;
			//交易记录的sql语句
			sql2.Format(_T("insert into atm (cardId,money,type) values(%s,%f,%d)"),CBankUIDlg::CurrentCard.id
				,money,1);
			if(DB.Update(ConvertCStringToString(sql2))){
				//成功	
				return true;
			}else{
				return false;
			}
			
		}else{
			return false;
		}

		

}
//专门的取款sql语句
//返回bool 
bool CMysqlForBank::WithDraw(double Money){

	//余额和取款金额比较 取款数大于0小于余额
	CString CurrentBalance=CBankUIDlg::CurrentCard.balance;
	//转为double类型
	double DoubleBalacne=_ttof(CurrentBalance);
	//取款比存款多 或小于0
	if(Money <=0 || DoubleBalacne < Money)  return false;
	CString Currentid=CBankUIDlg::CurrentCard.id;
	CString sql;
	sql.Format(_T("update card set balance = balance - %f where id = %s"),Money,Currentid);
		if(DB.Update(ConvertCStringToString(sql))){
			//更新成功
			CBankUIDlg::CurrentCard.balance=AddCStringAnddouble(CurrentBalance,Money,1);
			
			CString sql2;
			//交易记录的sql语句
			sql2.Format(_T("insert into atm (cardId,money,type) values(%s,%f,%d)"),CBankUIDlg::CurrentCard.id,Money,2);
			if(DB.Update(ConvertCStringToString(sql2))){
				//成功	
				return true;
			}else{
				return false;
			}


			return true;
		}else{
			return false;
		}

}

//提供销毁当前卡信息的作用
void CMysqlForBank::ExitCard(){
	
		//销毁card类里面的保存信息
			CBankUIDlg::CurrentCard.id="";
			CBankUIDlg::CurrentCard.cardNum="";
			CBankUIDlg::CurrentCard.cardPwd="";
			CBankUIDlg::CurrentCard.balance="";
			CBankUIDlg::CurrentCard.userName="";
			CBankUIDlg::CurrentCard.idNum="";
			CBankUIDlg::CurrentCard.cardType="";
			CBankUIDlg::CurrentCard.credit="";
			CBankUIDlg::CurrentCard.status="";
			CBankUIDlg::CurrentCard.add_time="";

}

bool CMysqlForBank::TransferJdNum(CString ToNum){
	//判断转账的账号是否存在
	CString sql;
	sql.Format(_T("select balance,id from card where cardNum = '%s'"),ToNum);
	if(DB.ExeSqlWithoutRes(ConvertCStringToString(sql))){
		//返回则说明存在，可以进行转账
		DB.result=DB.ExeSqlWithRes(ConvertCStringToString(sql));
		DB.sql_row=mysql_fetch_row(DB.result);
		CTransfer::OderToid=DB.sql_row[1];
		return true;
	}else{
		//否则不存在，不能转账
		return false;	
	}

}





//转账的主函数 ， 在TransferJdNum成功后执行
//到达此步说明卡号存在
bool CMysqlForBank::TransferMain(CString ToNum,double Money){
	
	CString Balance = CBankUIDlg::CurrentCard.balance;
		//转化为double
	double D_Balance=_ttof(Balance);
	//因为金额不符合要求而失败
	if(WithDraw(Money)) {
		
		//相应卡存
			CString sql;
			sql.Format(_T("update card set balance = balance + %f where cardNum='%s'"),Money,ToNum);
			if(DB.Update(ConvertCStringToString(sql))){
				
				CString sql1;
				sql1.Format(_T("insert into transfer (fromCardId,toCardId,money) values (%s , %s ,%f)"),CBankUIDlg::CurrentCard.id,CTransfer::OderToid,Money);

				if(DB.Update(ConvertCStringToString(sql1))){		

					return true;
				}else{
				
					return false;
				}
			}
			return false;
	}else{
	
	
		return false;
	}
	
	




}



bool CMysqlForBank::ChangePwd(CString NewPwd,CString cardNum){
	//修改密码
	CString sql;
	sql.Format(_T("update card set cardPwd = %s where cardNum='%s'"),NewPwd,cardNum);

	if(DB.Update(ConvertCStringToString(sql))){
	
		return true;
	
	}else{
	
		return false;
	}

}




bool CMysqlForBank::FreezenCard(CString CardNum){
	//根据卡号冻结卡

	CString sql;
	sql.Format(_T("update card set status=0 where cardNum='%s'"),CardNum);
	if(DB.Update(ConvertCStringToString(sql))){
		//冻结成功
		return true;
	
	}else{
		//
		return false;
	}




}
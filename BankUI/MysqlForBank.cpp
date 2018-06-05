#include "StdAfx.h"
#include "MysqlForBank.h"
#include "Transfer.h"
#include "BankUIDlg.h"
//------��̬��������
Mysql_Op CMysqlForBank::DB;
//
CMysqlForBank::CMysqlForBank(void)
{
}
CMysqlForBank::~CMysqlForBank(void)
{
}
//ר�ŵĵ�½sql����
//�����˺����룬����ȷ���ʼ��card���ͣ�����true �����򷵻�false
//  status 1���� status 2 ������� �˺���ȷ
//  status 3 �˺Ŷ�������
bool CMysqlForBank::Login(CString Cardnumber,CString CardPwd,int &status){
		status=-1;
		CString sql;
		sql.Format(_T("select * from card where cardNum='%s' and cardPwd='%s'"),Cardnumber,CardPwd);
		
		CString sql1;
		sql1.Format(_T("select * from card where cardNum='%s'"),Cardnumber);


		if(DB.ExeSqlWithoutRes(ConvertCStringToString(sql))) {
			//��½�ɹ� ��ʱ��DB�������е�ֵ������card
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
			//���浽UI��card��̬�����棡��
			//�ж��ǲ��Ƕ���״̬
			if(CBankUIDlg::CurrentCard.status=="1"){
				//������½			
				return true;
			}else{
				//�������
				status=1;
				return false;
			}
			
		}else if(DB.ExeSqlWithoutRes(ConvertCStringToString(sql1))){
			//����һ���϶� ������� �˺���ȷ
			//��½������һ �ﵽһ�������Ͷ���
			status=2;
			CBankUIDlg::m_LogInTimes +=1;
			return false;
		}else{
			//����һ���˺�Ҳ������
			status=3;
			return false;
		
		}		
}

//ר�ŵĴ��sql���
//�����������bool
bool CMysqlForBank::Deposite(double money){
	//��������Ϲ淶	
	if(money <= 0) return false;
	//��ǰ����id
	CString currentid=CBankUIDlg::CurrentCard.id;
	CString sql;
	CString s=CBankUIDlg::CurrentCard.balance;
	sql.Format(_T("update card set balance = balance + %f where id = %s"),money,currentid);
		if(DB.Update(ConvertCStringToString(sql))){
			//��Card�����ֵ
			CBankUIDlg::CurrentCard.balance=AddCStringAnddouble(CBankUIDlg::CurrentCard.balance,money,0);
			CString sql2;
			//���׼�¼��sql���
			sql2.Format(_T("insert into atm (cardId,money,type) values(%s,%f,%d)"),CBankUIDlg::CurrentCard.id
				,money,1);
			if(DB.Update(ConvertCStringToString(sql2))){
				//�ɹ�	
				return true;
			}else{
				return false;
			}
			
		}else{
			return false;
		}

		

}
//ר�ŵ�ȡ��sql���
//����bool 
bool CMysqlForBank::WithDraw(double Money){

	//����ȡ����Ƚ� ȡ��������0С�����
	CString CurrentBalance=CBankUIDlg::CurrentCard.balance;
	//תΪdouble����
	double DoubleBalacne=_ttof(CurrentBalance);
	//ȡ��ȴ��� ��С��0
	if(Money <=0 || DoubleBalacne < Money)  return false;
	CString Currentid=CBankUIDlg::CurrentCard.id;
	CString sql;
	sql.Format(_T("update card set balance = balance - %f where id = %s"),Money,Currentid);
		if(DB.Update(ConvertCStringToString(sql))){
			//���³ɹ�
			CBankUIDlg::CurrentCard.balance=AddCStringAnddouble(CurrentBalance,Money,1);
			
			CString sql2;
			//���׼�¼��sql���
			sql2.Format(_T("insert into atm (cardId,money,type) values(%s,%f,%d)"),CBankUIDlg::CurrentCard.id,Money,2);
			if(DB.Update(ConvertCStringToString(sql2))){
				//�ɹ�	
				return true;
			}else{
				return false;
			}


			return true;
		}else{
			return false;
		}

}

//�ṩ���ٵ�ǰ����Ϣ������
void CMysqlForBank::ExitCard(){
	
		//����card������ı�����Ϣ
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
	//�ж�ת�˵��˺��Ƿ����
	CString sql;
	sql.Format(_T("select balance,id from card where cardNum = '%s'"),ToNum);
	if(DB.ExeSqlWithoutRes(ConvertCStringToString(sql))){
		//������˵�����ڣ����Խ���ת��
		DB.result=DB.ExeSqlWithRes(ConvertCStringToString(sql));
		DB.sql_row=mysql_fetch_row(DB.result);
		CTransfer::OderToid=DB.sql_row[1];
		return true;
	}else{
		//���򲻴��ڣ�����ת��
		return false;	
	}

}





//ת�˵������� �� ��TransferJdNum�ɹ���ִ��
//����˲�˵�����Ŵ���
bool CMysqlForBank::TransferMain(CString ToNum,double Money){
	
	CString Balance = CBankUIDlg::CurrentCard.balance;
		//ת��Ϊdouble
	double D_Balance=_ttof(Balance);
	//��Ϊ������Ҫ���ʧ��
	if(WithDraw(Money)) {
		
		//��Ӧ����
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
	//�޸�����
	CString sql;
	sql.Format(_T("update card set cardPwd = %s where cardNum='%s'"),NewPwd,cardNum);

	if(DB.Update(ConvertCStringToString(sql))){
	
		return true;
	
	}else{
	
		return false;
	}

}




bool CMysqlForBank::FreezenCard(CString CardNum){
	//���ݿ��Ŷ��Ῠ

	CString sql;
	sql.Format(_T("update card set status=0 where cardNum='%s'"),CardNum);
	if(DB.Update(ConvertCStringToString(sql))){
		//����ɹ�
		return true;
	
	}else{
		//
		return false;
	}




}
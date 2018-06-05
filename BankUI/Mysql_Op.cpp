#include "StdAfx.h"
#include "Mysql_Op.h"


Mysql_Op::Mysql_Op(void)
{
	m_bConnect=false;
	MYSQL myCont;
	mysql_init(&myCont);//初始化
	MysqlConnect();//链接数据库
}


Mysql_Op::~Mysql_Op(void)
{
	
}

bool Mysql_Op::MysqlConnect(){

	const char user[] = "root";
	const char pswd[] = "19951103";
	const char host[] = "localhost";//如果不是本机数据库，填写服务器ip地址
	const char database[] = "bank";
	unsigned int port = 3306;
	//int res;
	mysql_init(&myCont);//初始化
	
	if (mysql_real_connect(&myCont, host, user, pswd, database, port, NULL, 0)){
		//cout<<"mysql connect successful!"<<endl;
		m_bConnect=true;
	}else{
		//cout<<"mysql connect fail!"<<endl;
		m_bConnect=false;
	}
	return m_bConnect;



}


bool Mysql_Op::ExeSqlWithoutRes(string sql){

	if(!TestAndSet()) { return false;}//数据库连接失败
		int res = mysql_query(&myCont,sql.c_str()); //string.c_str() 为string类型转化为char指针
													//mysql_query 语句只能判断sql字符串是否符合sql语句的规范，而不能判断到底是否有值
				
		if(!res){	
			result = mysql_store_result(&myCont);//存储查询结果 此时才可以判断查找结果是否有值
			//result && mysql_fetch_row(result)
			if(result && mysql_fetch_row(result)) return true;
			else return false;

		}else{	
			
			return false;
			}
}
//更新语句 成功返回真 否则返回false 
bool Mysql_Op::Update(string sql){
	if(!TestAndSet()) {return false;}//数据库连接失败
	int res = mysql_query(&myCont,sql.c_str());
	if(!res){	
		return true;
		}else{
		return false;
	}

}


//实现有结果集的sql语句
MYSQL_RES* Mysql_Op::ExeSqlWithRes(string sql){
	if(!TestAndSet()) {return false;}//数据库连接失败
	//string str="select * from card where CardNumber='111' and PassWord='1'";	
	int res = mysql_query(&myCont,sql.c_str());
	if(!res){
		 
		return mysql_store_result(&myCont);
			
	}else{
			
		return NULL;
	}

	
	
}

void Mysql_Op::Mysql_disconnect(){

	if(m_bConnect){
		mysql_close(&myCont);
		m_bConnect=false;
	}

}


//判断是否有链接，如果有则设置中文字符集 
bool Mysql_Op::TestAndSet (){
	
	if(!m_bConnect) {
	
		if(MysqlConnect()) {	
			mysql_query(&myCont, "SET NAMES GBK");
			return true;
		}else{		
			return false;
		}

	} else {
	
			return true;
	}


}


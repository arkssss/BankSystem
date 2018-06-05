#include "StdAfx.h"
#include "Mysql_Op.h"


Mysql_Op::Mysql_Op(void)
{
	m_bConnect=false;
	MYSQL myCont;
	mysql_init(&myCont);//��ʼ��
	MysqlConnect();//�������ݿ�
}


Mysql_Op::~Mysql_Op(void)
{
	
}

bool Mysql_Op::MysqlConnect(){

	const char user[] = "root";
	const char pswd[] = "19951103";
	const char host[] = "localhost";//������Ǳ������ݿ⣬��д������ip��ַ
	const char database[] = "bank";
	unsigned int port = 3306;
	//int res;
	mysql_init(&myCont);//��ʼ��
	
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

	if(!TestAndSet()) { return false;}//���ݿ�����ʧ��
		int res = mysql_query(&myCont,sql.c_str()); //string.c_str() Ϊstring����ת��Ϊcharָ��
													//mysql_query ���ֻ���ж�sql�ַ����Ƿ����sql���Ĺ淶���������жϵ����Ƿ���ֵ
				
		if(!res){	
			result = mysql_store_result(&myCont);//�洢��ѯ��� ��ʱ�ſ����жϲ��ҽ���Ƿ���ֵ
			//result && mysql_fetch_row(result)
			if(result && mysql_fetch_row(result)) return true;
			else return false;

		}else{	
			
			return false;
			}
}
//������� �ɹ������� ���򷵻�false 
bool Mysql_Op::Update(string sql){
	if(!TestAndSet()) {return false;}//���ݿ�����ʧ��
	int res = mysql_query(&myCont,sql.c_str());
	if(!res){	
		return true;
		}else{
		return false;
	}

}


//ʵ���н������sql���
MYSQL_RES* Mysql_Op::ExeSqlWithRes(string sql){
	if(!TestAndSet()) {return false;}//���ݿ�����ʧ��
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


//�ж��Ƿ������ӣ�����������������ַ��� 
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


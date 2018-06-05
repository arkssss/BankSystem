#pragma once
#include "mysql.h"
#include <string>
#pragma comment(lib, "libmysql.lib") 
using namespace std;
class Mysql_Op
{
public:
	Mysql_Op(void);
	~Mysql_Op(void);
	 bool MysqlConnect();
	 bool ExeSqlWithoutRes(string sql);
	 MYSQL_RES* ExeSqlWithRes(string sql);
	 bool TestAndSet ();    //�����������ݿ�������������ַ���
	 void Mysql_disconnect();
	 bool Update(string sql);
public :
	MYSQL myCont;
	MYSQL_RES *result;
	MYSQL_ROW sql_row;
	bool m_bConnect;
};


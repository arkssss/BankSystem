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
	 bool TestAndSet ();    //尝试链接数据库而且设置中文字符集
	 void Mysql_disconnect();
	 bool Update(string sql);
public :
	MYSQL myCont;
	MYSQL_RES *result;
	MYSQL_ROW sql_row;
	bool m_bConnect;
};


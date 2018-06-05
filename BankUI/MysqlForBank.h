#pragma once
#include "Card.h"
#include "Mysql_Op.h"
#include "Function.h"
#include "BankUIDlg.h"
class CMysqlForBank
{
public:
	CMysqlForBank(void);
	~CMysqlForBank(void);
	//专门的登陆sql函数
	static bool Login(CString Cardnumber,CString CardPwd,int &status);
	static bool Deposite(double Money);
	static bool WithDraw(double Money);
	static void ExitCard();
	static bool TransferJdNum(CString ToNum);
	static bool TransferMain(CString ToNum,double Money);
	static bool ChangePwd(CString NewPwd,CString cardNum);
	//根据卡号冻结银行卡
	static bool FreezenCard(CString CardNum);
	static Mysql_Op DB;
public :

};


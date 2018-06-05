#pragma once
extern char *Chinese[];
extern char *English[];
#include <string>
using namespace std;
class CLanguage
{
public:
	CLanguage(void);
	~CLanguage(void);

	//登陆
	static CString BankCardId;
	static CString Password;
	static CString Login;

	//菜单
	static CString Dlg1_Caption;
	static CString Dlg1_Tip;
	static CString Dlg1_Show_Balance;
	static CString Dlg1_Deposite;
	static CString Dlg1_Withdraw;
	static CString Dlg1_transfer;
	static CString Dlg1_refund_cards;
	static CString Dlg1_ChangePWD;

	//显示余额
	static CString Dlg2_You_Balance;	
	static CString Dlg2_Back;	

	//存款
	static CString Dlg3_Confirm;	
	static CString Dlg3_deplsit_money;

	//取款
	static CString Dlg4_withdrawal_money;	

	//转账
	static CString Dlg5_Input_CardNumber;

	//转账2
	static CString Dlg6_Input_amount;

	//改密码
	static CString Dlg7_Old_Pwd;
	static CString Dlg7_New_Pwd;
	static CString Dlg7_New_Pwd_Ag;


	void operator () (const int i)const;


};


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

	//��½
	static CString BankCardId;
	static CString Password;
	static CString Login;

	//�˵�
	static CString Dlg1_Caption;
	static CString Dlg1_Tip;
	static CString Dlg1_Show_Balance;
	static CString Dlg1_Deposite;
	static CString Dlg1_Withdraw;
	static CString Dlg1_transfer;
	static CString Dlg1_refund_cards;
	static CString Dlg1_ChangePWD;

	//��ʾ���
	static CString Dlg2_You_Balance;	
	static CString Dlg2_Back;	

	//���
	static CString Dlg3_Confirm;	
	static CString Dlg3_deplsit_money;

	//ȡ��
	static CString Dlg4_withdrawal_money;	

	//ת��
	static CString Dlg5_Input_CardNumber;

	//ת��2
	static CString Dlg6_Input_amount;

	//������
	static CString Dlg7_Old_Pwd;
	static CString Dlg7_New_Pwd;
	static CString Dlg7_New_Pwd_Ag;


	void operator () (const int i)const;


};


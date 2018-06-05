#pragma once
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
enum Status{
	Log_In,
	Login_Successful,
	Login_Fail,
	Lonin_Menu,
	Deposit_Successful,
	Deposit_Fail,
	Withdraw_Fail,
	Withdraw_Successful,
	Account_NotExist,
	CanNot_ToYouself,
	Modify_Successful
};

class C_AIVoice
{
public:
	C_AIVoice(void);
	~C_AIVoice(void);

	CString m_login;
	CString m_LoginSuccessful;
	CString m_LoginFail;
	CString m_LoninMenu;
	CString	m_DepositSuccessful;
	CString m_DepositFail;
	CString m_WithdrawFail;
	CString m_WithdrawSuccessful;
	CString m_AccountNotExist;
	CString m_CanNotToYouself;
	CString m_ModifySuccessful;
	void PlayThisVoice(Status CurrentStatu);

};


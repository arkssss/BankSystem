#include "StdAfx.h"
#include "C_AIVoice.h"
#include "Function.h"

C_AIVoice::C_AIVoice(void)
{
	m_login="Login.wav";
	m_LoginSuccessful="LoginSuccessful.wav";
	m_LoginFail="LoginFail.wav";
	m_LoninMenu="LoninMenu.wav";
	m_DepositSuccessful="DepositSuccessful.wav";
	m_DepositFail="DepositFail.wav";
	m_WithdrawFail="WithdrawFail.wav";
	m_WithdrawSuccessful="WithdrawSuccessful.wav";
	m_AccountNotExist="AccountNotExist.wav";
	m_CanNotToYouself="CanNotToYouself";
	m_ModifySuccessful="ModifySuccessful.wav";
}


C_AIVoice::~C_AIVoice(void)
{
}

void C_AIVoice::PlayThisVoice(Status CurrentStatu){
	
	CString tmp;

	switch (CurrentStatu) {
	
	case Log_In :			 tmp=m_login;
							 break;
	case Login_Successful :	 tmp=m_LoginSuccessful;
							 break;
	case Login_Fail : 		 tmp=m_LoginFail;
							 break;
	case Lonin_Menu :		 tmp=m_LoninMenu;
						 	 break;	
	case Deposit_Successful: tmp=m_DepositSuccessful;
							 break;
	case Deposit_Fail:		 tmp=m_DepositFail;
							 break;
	case Withdraw_Fail:		 tmp=m_WithdrawFail;
							 break;
	case Withdraw_Successful:tmp=m_WithdrawSuccessful;
							 break;
	case Account_NotExist	:tmp=m_AccountNotExist;
							 break;
	case CanNot_ToYouself	:tmp=m_CanNotToYouself	;
							 break;
	case Modify_Successful : tmp=m_ModifySuccessful ;
							 break;

	
	}






	PlaySound(TEXT("Voice\\"+tmp+""), NULL, SND_FILENAME | SND_ASYNC );
}



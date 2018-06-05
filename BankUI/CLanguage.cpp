#include "StdAfx.h"
#include "CLanguage.h"
#include "Function.h"

char *Chinese[] = {"银行卡号 :","密码 :","登陆","登陆成功!","请选择以下操作"
,"余额查询","存款","取款","转账","退卡","修改密码","您的余额为:","返回上一层"
,"确定","请输入存款金额","请输入取款金额","输入您要转账人的卡号","请输入转账金额"
,"请输入原密码","新密码","再次输入新密码"};
char *English[] = {"BankId :","PassWord:","Log In","Log In Successfully","Please select the following operation"
,"Balance inquiry","Deposit","Withdrawal","Transfer","Check Out","change Password","Your balance is :","Return to the previous level"
,"Confirm","Please enter the deposit amount","Please enter the withdrawal amount","Enter the card number of the person you want to transfer"
,"Please enter the transfer amount","Please enter the original password","new password"
,"Enter the new password again"};
//i为0 为中文
//i为1 为英文
//-----静态变量声明
//框1
CString CLanguage::BankCardId;
CString CLanguage::Password;
CString CLanguage::Login;

//框2
CString CLanguage::Dlg1_Caption;
CString CLanguage::Dlg1_Tip;
CString CLanguage::Dlg1_Show_Balance;
CString CLanguage::Dlg1_Deposite;
CString CLanguage::Dlg1_Withdraw;
CString CLanguage::Dlg1_transfer;
CString CLanguage::Dlg1_refund_cards;
CString CLanguage::Dlg1_ChangePWD;

//框3 （显示余额）
CString CLanguage::Dlg2_You_Balance;	
CString CLanguage::Dlg2_Back;	

//框4  （存款）
CString CLanguage::Dlg3_Confirm;	
CString CLanguage::Dlg3_deplsit_money;

//框5 （取款）
CString CLanguage::Dlg4_withdrawal_money;	


//框6 (转账)
CString CLanguage::Dlg5_Input_CardNumber;

//框7（转账2）
CString CLanguage::Dlg6_Input_amount;

//框8 （改密码）
CString CLanguage::Dlg7_Old_Pwd;
CString CLanguage::Dlg7_New_Pwd;
CString CLanguage::Dlg7_New_Pwd_Ag;


CLanguage::CLanguage(void)
{
}

CLanguage::~CLanguage(void)
{
}

void CLanguage::operator () (const int i)const{

	if(i==0){
		//中文
		//框1
		BankCardId=ConvertStringToCString(Chinese[0]);
		Password=ConvertStringToCString(Chinese[1]);
		Login=ConvertStringToCString(Chinese[2]);

		//框2
		Dlg1_Caption=ConvertStringToCString(Chinese[3]);
		Dlg1_Tip=ConvertStringToCString(Chinese[4]);
		Dlg1_Show_Balance=ConvertStringToCString(Chinese[5]);
		Dlg1_Deposite=ConvertStringToCString(Chinese[6]);
		Dlg1_Withdraw=ConvertStringToCString(Chinese[7]);
		Dlg1_transfer=ConvertStringToCString(Chinese[8]);
		Dlg1_refund_cards=ConvertStringToCString(Chinese[9]);
		Dlg1_ChangePWD=ConvertStringToCString(Chinese[10]);
		
		//框3
		Dlg2_You_Balance=ConvertStringToCString(Chinese[11]);
		Dlg2_Back=ConvertStringToCString(Chinese[12]);

		//框4  （存款）
		Dlg3_Confirm=ConvertStringToCString(Chinese[13]);	
		Dlg3_deplsit_money=ConvertStringToCString(Chinese[14]);	

		//框5   取款
		Dlg4_withdrawal_money=ConvertStringToCString(Chinese[15]);

		//框6   转账
		Dlg5_Input_CardNumber=ConvertStringToCString(Chinese[16]);

		//框7   转账2
		Dlg6_Input_amount=ConvertStringToCString(Chinese[17]);

		//框8 （改密码）
		Dlg7_Old_Pwd=ConvertStringToCString(Chinese[18]);
		Dlg7_New_Pwd=ConvertStringToCString(Chinese[19]);
		Dlg7_New_Pwd_Ag=ConvertStringToCString(Chinese[20]);




	}else if(i==1){
		//英文
		
		BankCardId=ConvertStringToCString(English[0]);
		Password=ConvertStringToCString(English[1]);
		Login=ConvertStringToCString(English[2]);

		//框2
		Dlg1_Caption=ConvertStringToCString(English[3]);
		Dlg1_Tip=ConvertStringToCString(English[4]);
		Dlg1_Show_Balance=ConvertStringToCString(English[5]);
		Dlg1_Deposite=ConvertStringToCString(English[6]);
		Dlg1_Withdraw=ConvertStringToCString(English[7]);
		Dlg1_transfer=ConvertStringToCString(English[8]);
		Dlg1_refund_cards=ConvertStringToCString(English[9]);
		Dlg1_ChangePWD=ConvertStringToCString(English[10]);

		//框3
		Dlg2_You_Balance=ConvertStringToCString(English[11]);
		Dlg2_Back=ConvertStringToCString(English[12]);

		//框4  （存款）
		Dlg3_Confirm=ConvertStringToCString(English[13]);	
		Dlg3_deplsit_money=ConvertStringToCString(English[14]);	

		//框5   取款
		Dlg4_withdrawal_money=ConvertStringToCString(English[15]);

		//框6   转账
		Dlg5_Input_CardNumber=ConvertStringToCString(English[16]);

		//框7   转账2
		Dlg6_Input_amount=ConvertStringToCString(English[17]);

		//框8 （改密码）
		Dlg7_Old_Pwd=ConvertStringToCString(English[18]);
		Dlg7_New_Pwd=ConvertStringToCString(English[19]);
		Dlg7_New_Pwd_Ag=ConvertStringToCString(English[20]);


	}
	

}



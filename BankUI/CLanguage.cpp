#include "StdAfx.h"
#include "CLanguage.h"
#include "Function.h"

char *Chinese[] = {"���п��� :","���� :","��½","��½�ɹ�!","��ѡ�����²���"
,"����ѯ","���","ȡ��","ת��","�˿�","�޸�����","�������Ϊ:","������һ��"
,"ȷ��","����������","������ȡ����","������Ҫת���˵Ŀ���","������ת�˽��"
,"������ԭ����","������","�ٴ�����������"};
char *English[] = {"BankId :","PassWord:","Log In","Log In Successfully","Please select the following operation"
,"Balance inquiry","Deposit","Withdrawal","Transfer","Check Out","change Password","Your balance is :","Return to the previous level"
,"Confirm","Please enter the deposit amount","Please enter the withdrawal amount","Enter the card number of the person you want to transfer"
,"Please enter the transfer amount","Please enter the original password","new password"
,"Enter the new password again"};
//iΪ0 Ϊ����
//iΪ1 ΪӢ��
//-----��̬��������
//��1
CString CLanguage::BankCardId;
CString CLanguage::Password;
CString CLanguage::Login;

//��2
CString CLanguage::Dlg1_Caption;
CString CLanguage::Dlg1_Tip;
CString CLanguage::Dlg1_Show_Balance;
CString CLanguage::Dlg1_Deposite;
CString CLanguage::Dlg1_Withdraw;
CString CLanguage::Dlg1_transfer;
CString CLanguage::Dlg1_refund_cards;
CString CLanguage::Dlg1_ChangePWD;

//��3 ����ʾ��
CString CLanguage::Dlg2_You_Balance;	
CString CLanguage::Dlg2_Back;	

//��4  ����
CString CLanguage::Dlg3_Confirm;	
CString CLanguage::Dlg3_deplsit_money;

//��5 ��ȡ�
CString CLanguage::Dlg4_withdrawal_money;	


//��6 (ת��)
CString CLanguage::Dlg5_Input_CardNumber;

//��7��ת��2��
CString CLanguage::Dlg6_Input_amount;

//��8 �������룩
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
		//����
		//��1
		BankCardId=ConvertStringToCString(Chinese[0]);
		Password=ConvertStringToCString(Chinese[1]);
		Login=ConvertStringToCString(Chinese[2]);

		//��2
		Dlg1_Caption=ConvertStringToCString(Chinese[3]);
		Dlg1_Tip=ConvertStringToCString(Chinese[4]);
		Dlg1_Show_Balance=ConvertStringToCString(Chinese[5]);
		Dlg1_Deposite=ConvertStringToCString(Chinese[6]);
		Dlg1_Withdraw=ConvertStringToCString(Chinese[7]);
		Dlg1_transfer=ConvertStringToCString(Chinese[8]);
		Dlg1_refund_cards=ConvertStringToCString(Chinese[9]);
		Dlg1_ChangePWD=ConvertStringToCString(Chinese[10]);
		
		//��3
		Dlg2_You_Balance=ConvertStringToCString(Chinese[11]);
		Dlg2_Back=ConvertStringToCString(Chinese[12]);

		//��4  ����
		Dlg3_Confirm=ConvertStringToCString(Chinese[13]);	
		Dlg3_deplsit_money=ConvertStringToCString(Chinese[14]);	

		//��5   ȡ��
		Dlg4_withdrawal_money=ConvertStringToCString(Chinese[15]);

		//��6   ת��
		Dlg5_Input_CardNumber=ConvertStringToCString(Chinese[16]);

		//��7   ת��2
		Dlg6_Input_amount=ConvertStringToCString(Chinese[17]);

		//��8 �������룩
		Dlg7_Old_Pwd=ConvertStringToCString(Chinese[18]);
		Dlg7_New_Pwd=ConvertStringToCString(Chinese[19]);
		Dlg7_New_Pwd_Ag=ConvertStringToCString(Chinese[20]);




	}else if(i==1){
		//Ӣ��
		
		BankCardId=ConvertStringToCString(English[0]);
		Password=ConvertStringToCString(English[1]);
		Login=ConvertStringToCString(English[2]);

		//��2
		Dlg1_Caption=ConvertStringToCString(English[3]);
		Dlg1_Tip=ConvertStringToCString(English[4]);
		Dlg1_Show_Balance=ConvertStringToCString(English[5]);
		Dlg1_Deposite=ConvertStringToCString(English[6]);
		Dlg1_Withdraw=ConvertStringToCString(English[7]);
		Dlg1_transfer=ConvertStringToCString(English[8]);
		Dlg1_refund_cards=ConvertStringToCString(English[9]);
		Dlg1_ChangePWD=ConvertStringToCString(English[10]);

		//��3
		Dlg2_You_Balance=ConvertStringToCString(English[11]);
		Dlg2_Back=ConvertStringToCString(English[12]);

		//��4  ����
		Dlg3_Confirm=ConvertStringToCString(English[13]);	
		Dlg3_deplsit_money=ConvertStringToCString(English[14]);	

		//��5   ȡ��
		Dlg4_withdrawal_money=ConvertStringToCString(English[15]);

		//��6   ת��
		Dlg5_Input_CardNumber=ConvertStringToCString(English[16]);

		//��7   ת��2
		Dlg6_Input_amount=ConvertStringToCString(English[17]);

		//��8 �������룩
		Dlg7_Old_Pwd=ConvertStringToCString(English[18]);
		Dlg7_New_Pwd=ConvertStringToCString(English[19]);
		Dlg7_New_Pwd_Ag=ConvertStringToCString(English[20]);


	}
	

}



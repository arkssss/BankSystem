#pragma once
class CCard
{
public:
   	CCard(void);
	~CCard(void);
	//��ʾ���
	CString GetBalance();


public:
	CString id;			//��־id
	CString cardNum;	
	CString cardPwd;
	CString balance;
	CString userName;
	CString idNum;
	CString cardType;
	CString credit;
	CString status;	  //�Ƿ񱻶���
	CString add_time;  //����ʱ��


};





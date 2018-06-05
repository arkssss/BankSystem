#pragma once
class CCard
{
public:
   	CCard(void);
	~CCard(void);
	//显示余额
	CString GetBalance();


public:
	CString id;			//标志id
	CString cardNum;	
	CString cardPwd;
	CString balance;
	CString userName;
	CString idNum;
	CString cardType;
	CString credit;
	CString status;	  //是否被冻结
	CString add_time;  //加入时间


};





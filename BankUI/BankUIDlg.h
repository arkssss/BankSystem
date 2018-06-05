
// BankUIDlg.h : 头文件
#pragma once
#include "Card.h"
#include "Mysql_Op.h"
#include "resource.h"
#include "afxwin.h"
#include "CLanguage.h"
#include "C_AIVoice.h"

struct LogInInfo{
	//登陆的状态位 ‘1’为成功
	int LogInSuccess; 
	//id 为如果登陆成功 则为其在数据库中的主键，否则为-1
	CString id ;
};
struct MYsql{
	MYSQL_RES *res;
	MYSQL_ROW sql_row;
};
// CBankUIDlg 对话框
class CBankUIDlg : public CDialogEx
{
// 构造
public:
	CBankUIDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_BANKUI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	
public : static   Mysql_Op DB;
public : static   LogInInfo LogInfo;
public : static   MYsql My_Mysql;
// 实现
protected:
	HICON m_hIcon;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString CardNumber;
	CString CardPassWrod;
	afx_msg void OnEnChangeEdit1();
	bool KeyDown(MSG* pMsg);
//引入静态card类
	static CCard CurrentCard;
	afx_msg void OnCbnSelchangeCombo1();
	// 1英文 0中文
	static int m_LanguageChose;
	afx_msg void OnCbnSelchangeCombolanguage();
	static CLanguage Language;
	static C_AIVoice AIVoice;
	CComboBox m_cb;

	//表示登陆的次数
	static int m_LogInTimes;
	CString BeforeCardNum;
	//afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};


// BankUIDlg.h : ͷ�ļ�
#pragma once
#include "Card.h"
#include "Mysql_Op.h"
#include "resource.h"
#include "afxwin.h"
#include "CLanguage.h"
#include "C_AIVoice.h"

struct LogInInfo{
	//��½��״̬λ ��1��Ϊ�ɹ�
	int LogInSuccess; 
	//id Ϊ�����½�ɹ� ��Ϊ�������ݿ��е�����������Ϊ-1
	CString id ;
};
struct MYsql{
	MYSQL_RES *res;
	MYSQL_ROW sql_row;
};
// CBankUIDlg �Ի���
class CBankUIDlg : public CDialogEx
{
// ����
public:
	CBankUIDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_BANKUI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	
public : static   Mysql_Op DB;
public : static   LogInInfo LogInfo;
public : static   MYsql My_Mysql;
// ʵ��
protected:
	HICON m_hIcon;
	// ���ɵ���Ϣӳ�亯��
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
//���뾲̬card��
	static CCard CurrentCard;
	afx_msg void OnCbnSelchangeCombo1();
	// 1Ӣ�� 0����
	static int m_LanguageChose;
	afx_msg void OnCbnSelchangeCombolanguage();
	static CLanguage Language;
	static C_AIVoice AIVoice;
	CComboBox m_cb;

	//��ʾ��½�Ĵ���
	static int m_LogInTimes;
	CString BeforeCardNum;
	//afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

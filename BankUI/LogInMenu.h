#pragma once
#include <string>
using namespace std;
// CLogInMenu 对话框

class CLogInMenu : public CDialogEx
{
	DECLARE_DYNAMIC(CLogInMenu)

public:
	CLogInMenu(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLogInMenu();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBlacnce();
	afx_msg void OnBnClickeddeposite();
	afx_msg void OnBnClickedwithdraw();
	afx_msg void OnBnClickedBackup();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedtransfer();
	afx_msg void OnBnClickedChangepwd();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

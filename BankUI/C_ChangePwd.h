#pragma once


// C_ChangePwd 对话框

class C_ChangePwd : public CDialogEx
{
	DECLARE_DYNAMIC(C_ChangePwd)

public:
	C_ChangePwd(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~C_ChangePwd();

// 对话框数据
	enum { IDD = IDD_DIALOG_ChangePwd };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_OldPwd;
	CString m_NewPwd;
	CString m_AgPwd;
	afx_msg void OnBnClickedButtonComfirm();
	bool JudgeInfo();

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonBack();
};

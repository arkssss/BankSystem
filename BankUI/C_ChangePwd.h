#pragma once


// C_ChangePwd �Ի���

class C_ChangePwd : public CDialogEx
{
	DECLARE_DYNAMIC(C_ChangePwd)

public:
	C_ChangePwd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~C_ChangePwd();

// �Ի�������
	enum { IDD = IDD_DIALOG_ChangePwd };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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

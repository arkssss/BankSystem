#pragma once


// CShowBlance �Ի���

class CShowBlance : public CDialogEx
{
	DECLARE_DYNAMIC(CShowBlance)

public:
	CShowBlance(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CShowBlance();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	
	CString m_Balance;
	afx_msg void OnBnClickedBack();
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

#pragma once


// CDeposite �Ի���

class CDeposite : public CDialogEx
{
	DECLARE_DYNAMIC(CDeposite)

public:
	CDeposite(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDeposite();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedConfirm();
	double m_money;
	afx_msg void OnBnClickedBack();

	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

#pragma once


// CTransferMain �Ի���

class CTransferMain : public CDialogEx
{
	DECLARE_DYNAMIC(CTransferMain)

public:
	CTransferMain(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTransferMain();

// �Ի�������
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	double m_money;
	afx_msg void OnBnClickedConfirm();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

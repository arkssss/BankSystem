#pragma once


// CTransfer �Ի���

class CTransfer : public CDialogEx
{
	DECLARE_DYNAMIC(CTransfer)

public:
	CTransfer(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTransfer();

// �Ի�������
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString ToNum;
	afx_msg void OnBnClickedConfirm();
	afx_msg void OnBnClickedBack();
	static CString OderToNum;
	static CString OderToid;
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

#pragma once


// CWithDraw �Ի���

class CWithDraw : public CDialogEx
{
	DECLARE_DYNAMIC(CWithDraw)

public:
	CWithDraw(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CWithDraw();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	double m_money;
	afx_msg void OnBnClickedConfirm();
	afx_msg void OnBnClickedBack();
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

#pragma once


// CDeposite 对话框

class CDeposite : public CDialogEx
{
	DECLARE_DYNAMIC(CDeposite)

public:
	CDeposite(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDeposite();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedConfirm();
	double m_money;
	afx_msg void OnBnClickedBack();

	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

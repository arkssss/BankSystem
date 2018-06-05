#pragma once


// CShowBlance 对话框

class CShowBlance : public CDialogEx
{
	DECLARE_DYNAMIC(CShowBlance)

public:
	CShowBlance(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CShowBlance();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	
	CString m_Balance;
	afx_msg void OnBnClickedBack();
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

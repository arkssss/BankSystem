#pragma once


// CWithDraw 对话框

class CWithDraw : public CDialogEx
{
	DECLARE_DYNAMIC(CWithDraw)

public:
	CWithDraw(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CWithDraw();

// 对话框数据
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_money;
	afx_msg void OnBnClickedConfirm();
	afx_msg void OnBnClickedBack();
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

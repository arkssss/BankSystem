#pragma once


// CTransfer 对话框

class CTransfer : public CDialogEx
{
	DECLARE_DYNAMIC(CTransfer)

public:
	CTransfer(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTransfer();

// 对话框数据
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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

#pragma once


// CTransferMain 对话框

class CTransferMain : public CDialogEx
{
	DECLARE_DYNAMIC(CTransferMain)

public:
	CTransferMain(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTransferMain();

// 对话框数据
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_money;
	afx_msg void OnBnClickedConfirm();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

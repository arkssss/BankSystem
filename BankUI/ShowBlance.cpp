// ShowBlance.cpp : 实现文件
//

#include "stdafx.h"
#include "BankUI.h"
#include "ShowBlance.h"
#include "afxdialogex.h"
#include "BankUIDlg.h"
#include "LogInMenu.h"
// CShowBlance 对话框

IMPLEMENT_DYNAMIC(CShowBlance, CDialogEx)

//构造函数
CShowBlance::CShowBlance(CWnd* pParent /*=NULL*/)
	: CDialogEx(CShowBlance::IDD, pParent)
	, m_Balance(CBankUIDlg::CurrentCard.balance)
{
	


}

CShowBlance::~CShowBlance()
{
}

void CShowBlance::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ShowBlance, m_Balance);
}


BEGIN_MESSAGE_MAP(CShowBlance, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_Back, &CShowBlance::OnBnClickedBack)
END_MESSAGE_MAP()


// CShowBlance 消息处理程序



void CShowBlance::OnBnClickedBack()
{
		OnOK();
		CLogInMenu  BlanceDlg;
		BlanceDlg.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


BOOL CShowBlance::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化函数
	CMenu* pMenu = this->GetSystemMenu(FALSE);//系统菜单
	pMenu->ModifyMenu(SC_CLOSE,MF_BYCOMMAND | MF_GRAYED );//禁用关闭按
	
	//语言初始化代码
	this->SetWindowText(CBankUIDlg::Language.Dlg1_Show_Balance);
	GetDlgItem(IDC_STATIC_YouBalacne)->SetWindowText(CBankUIDlg::Language.Dlg2_You_Balance);
	GetDlgItem(IDC_Back)->SetWindowText(CBankUIDlg::Language.Dlg2_Back);







	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


BOOL CShowBlance::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message == WM_KEYDOWN)
	{
		switch(pMsg->wParam)
		{
		case VK_RETURN:    // 屏蔽回车
			OnBnClickedBack();
			return true;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

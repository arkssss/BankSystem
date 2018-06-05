// LogInMenu.cpp : 实现文件
//

#include "stdafx.h"
#include "BankUI.h"
#include "LogInMenu.h"
#include "afxdialogex.h"
#include "ShowBlance.h"
#include "BankUIDlg.h"
#include "Function.h"
#include "WithDraw.h"
#include "Deposite.h"
#include "MysqlForBank.h"
#include "Transfer.h"
#include "CLanguage.h"
#include "C_ChangePwd.h"
// CLogInMenu 对话框




IMPLEMENT_DYNAMIC(CLogInMenu, CDialogEx)

CLogInMenu::CLogInMenu(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLogInMenu::IDD, pParent)
{

}

CLogInMenu::~CLogInMenu()
{
}

void CLogInMenu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLogInMenu, CDialogEx)
	ON_BN_CLICKED(IDC_Blacnce, &CLogInMenu::OnBnClickedBlacnce)
	ON_BN_CLICKED(IDC_deposite, &CLogInMenu::OnBnClickeddeposite)
	ON_BN_CLICKED(IDC_withdraw, &CLogInMenu::OnBnClickedwithdraw)
	ON_BN_CLICKED(IDC_BackUp, &CLogInMenu::OnBnClickedBackup)
	ON_BN_CLICKED(transfer, &CLogInMenu::OnBnClickedtransfer)
	ON_BN_CLICKED(IDC_ChangePwd, &CLogInMenu::OnBnClickedChangepwd)
END_MESSAGE_MAP()


// CLogInMenu 消息处理程序


void CLogInMenu::OnBnClickedBlacnce()
{	
	OnOK();
	CShowBlance BlanceDlg;
	BlanceDlg.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void CLogInMenu::OnBnClickeddeposite()
{
	OnOK();
	CDeposite Depositedlg;
	Depositedlg.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void CLogInMenu::OnBnClickedwithdraw()
{
	OnOK();
	CWithDraw Withdrawdlg;
	Withdrawdlg.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


//退出
void CLogInMenu::OnBnClickedBackup()
{
	// TODO: 在此添加控件通知处理程序代码
		
	int Icomd;
	if(!CBankUIDlg::m_LanguageChose){
	 Icomd=MessageBox(_T("您确定要退出吗?"),_T("注意"),IDOK);
	}else{
	 Icomd=MessageBox(_T("Are you sure to quit?"),_T("note"),IDOK);
	}

	if(Icomd==1){
		//按下确定键
		CMysqlForBank::ExitCard();
		OnOK();
		CBankUIDlg LogIn;
		LogIn.DoModal();
	}


}


BOOL CLogInMenu::OnInitDialog()
{
	CDialogEx::OnInitDialog();

		// TODO:  在此添加额外的初始化
		CMenu* pMenu = this->GetSystemMenu(FALSE);//系统菜单
		pMenu->ModifyMenu(SC_CLOSE,MF_BYCOMMAND | MF_GRAYED );//禁用关闭按

		//语音
		CBankUIDlg::AIVoice.PlayThisVoice(Lonin_Menu);

		//语言初始化
		this->SetWindowText(CBankUIDlg::Language.Dlg1_Caption);
	    GetDlgItem(IDC_STATIC)->SetWindowText(CBankUIDlg::Language.Dlg1_Tip);
				GetDlgItem(IDC_Blacnce)->SetWindowText(CBankUIDlg::Language.Dlg1_Show_Balance);
		GetDlgItem(IDC_deposite)->SetWindowText(CBankUIDlg::Language.Dlg1_Deposite);
		GetDlgItem(IDC_withdraw)->SetWindowText(CBankUIDlg::Language.Dlg1_Withdraw);
		GetDlgItem(transfer)->SetWindowText(CBankUIDlg::Language.Dlg1_transfer);
		GetDlgItem(IDC_ChangePwd)->SetWindowText(CBankUIDlg::Language.Dlg1_ChangePWD);
		GetDlgItem(IDC_BackUp)->SetWindowText(CBankUIDlg::Language.Dlg1_refund_cards);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CLogInMenu::OnBnClickedtransfer()
{

		OnOK();
		CTransfer Transfer;
		Transfer.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void CLogInMenu::OnBnClickedChangepwd()
{
	// TODO: 在此添加控件通知处理程序代码
	// 更改密码
	OnOK();
	C_ChangePwd ChangePwd;
	ChangePwd.DoModal();

}


BOOL CLogInMenu::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message == WM_KEYDOWN)
	{
		switch(pMsg->wParam)
		{
		case VK_RETURN:    // 屏蔽回车
			
			return true;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

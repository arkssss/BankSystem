// Deposite.cpp : 实现文件
//

#include "stdafx.h"
#include "BankUI.h"
#include "Deposite.h"
#include "afxdialogex.h"
#include "MysqlForBank.h"
#include "BankUIDlg.h"
#include "LogInMenu.h"
// CDeposite 对话框

IMPLEMENT_DYNAMIC(CDeposite, CDialogEx)

CDeposite::CDeposite(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDeposite::IDD, pParent)
	, m_money(0)
{

}

CDeposite::~CDeposite()
{
}

void CDeposite::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_deposite, m_money);
}


BEGIN_MESSAGE_MAP(CDeposite, CDialogEx)
	ON_BN_CLICKED(IDC_Confirm, &CDeposite::OnBnClickedConfirm)
	ON_BN_CLICKED(IDC_Back, &CDeposite::OnBnClickedBack)
END_MESSAGE_MAP()


// CDeposite 消息处理程序








void CDeposite::OnBnClickedConfirm()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if(CMysqlForBank::Deposite(m_money)){
		//存款成功 
		CBankUIDlg::AIVoice.PlayThisVoice(Deposit_Successful);
		if(!CBankUIDlg::m_LanguageChose){
				
				MessageBox(_T("存款成功"));
			}else{
				MessageBox(_T("Deposit successful！"));
			}
					

		//页面跳转	
		OnOK();
		CLogInMenu Menu;
		Menu.DoModal();
	}else{
			CBankUIDlg::AIVoice.PlayThisVoice(Deposit_Fail);
			if(!CBankUIDlg::m_LanguageChose){
				MessageBox(_T("存款失败"));
			}else{
				MessageBox(_T("Deposit failed！"));
			}

	}


}


void CDeposite::OnBnClickedBack()
{
		OnOK();
		CLogInMenu  BlanceDlg;
		BlanceDlg.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}

BOOL CDeposite::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化函数
	CMenu* pMenu = this->GetSystemMenu(FALSE);//系统菜单
	pMenu->ModifyMenu(SC_CLOSE,MF_BYCOMMAND | MF_GRAYED );//禁用关闭按

	//初始化语言函数
	this->SetWindowText(CBankUIDlg::Language.Dlg1_Deposite);
	GetDlgItem(IDC_Confirm)->SetWindowText(CBankUIDlg::Language.Dlg3_Confirm);
	GetDlgItem(IDC_STATIC)->SetWindowText(CBankUIDlg::Language.Dlg3_deplsit_money);
	GetDlgItem(IDC_Back)->SetWindowText(CBankUIDlg::Language.Dlg2_Back);
	
	



	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


BOOL CDeposite::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
			if(pMsg->message == WM_KEYDOWN)
	{
		switch(pMsg->wParam)
		{
		case VK_RETURN:    // 屏蔽回车
			OnBnClickedConfirm();
			return true;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

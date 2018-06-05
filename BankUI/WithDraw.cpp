// WithDraw.cpp : 实现文件
//

#include "stdafx.h"
#include "BankUI.h"
#include "WithDraw.h"
#include "afxdialogex.h"
#include "MysqlForBank.h"
#include "LogInMenu.h"

// CWithDraw 对话框

IMPLEMENT_DYNAMIC(CWithDraw, CDialogEx)

CWithDraw::CWithDraw(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWithDraw::IDD, pParent)
	, m_money(0)
{

}

CWithDraw::~CWithDraw()
{
}

void CWithDraw::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_withdraw, m_money);
}


BEGIN_MESSAGE_MAP(CWithDraw, CDialogEx)
	ON_BN_CLICKED(IDC_Confirm, &CWithDraw::OnBnClickedConfirm)
	ON_BN_CLICKED(IDC_Back, &CWithDraw::OnBnClickedBack)
END_MESSAGE_MAP()


// CWithDraw 消息处理程序


void CWithDraw::OnBnClickedConfirm()
{	//取款的确定事件 
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);


	if(CMysqlForBank::WithDraw(m_money)) {
	//成功
		    CBankUIDlg::AIVoice.PlayThisVoice(Withdraw_Successful);
			if(!CBankUIDlg::m_LanguageChose){
				MessageBox(_T("取款成功"));
			}else{
				MessageBox(_T("Withdrawals successful!"));
			}	
		
		//页面跳转	
		OnOK();
		CLogInMenu Menu;
		Menu.DoModal();
	}else{
	//失败
			CBankUIDlg::AIVoice.PlayThisVoice(Withdraw_Fail);
			if(!CBankUIDlg::m_LanguageChose){
				MessageBox(_T("取款失败"));
			}else{
				MessageBox(_T("Withdrawal failed!"));
			}	

	}



}


void CWithDraw::OnBnClickedBack()
{
		OnOK();
		CLogInMenu Menu;
		Menu.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


BOOL CWithDraw::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化函数
	CMenu* pMenu = this->GetSystemMenu(FALSE);//系统菜单
	pMenu->ModifyMenu(SC_CLOSE,MF_BYCOMMAND | MF_GRAYED );//禁用关闭按

	//语言初始化函数
	this->SetWindowText(CBankUIDlg::Language.Dlg1_Withdraw);
	GetDlgItem(IDC_STATIC)->SetWindowText(CBankUIDlg::Language.Dlg4_withdrawal_money);
	GetDlgItem(IDC_Confirm)->SetWindowText(CBankUIDlg::Language.Dlg3_Confirm);
	GetDlgItem(IDC_Back)->SetWindowText(CBankUIDlg::Language.Dlg2_Back);






	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


BOOL CWithDraw::PreTranslateMessage(MSG* pMsg)
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

// TransferMain.cpp : 实现文件
//

#include "stdafx.h"
#include "BankUI.h"
#include "TransferMain.h"
#include "afxdialogex.h"
#include "MysqlForBank.h"
#include "Transfer.h"
#include "BankUIDlg.h"
#include "LogInMenu.h"
// CTransferMain 对话框

IMPLEMENT_DYNAMIC(CTransferMain, CDialogEx)

CTransferMain::CTransferMain(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTransferMain::IDD, pParent)
	, m_money(0)
{

}

CTransferMain::~CTransferMain()
{
}

void CTransferMain::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Money, m_money);
}


BEGIN_MESSAGE_MAP(CTransferMain, CDialogEx)
	ON_BN_CLICKED(IDC_Confirm, &CTransferMain::OnBnClickedConfirm)
END_MESSAGE_MAP()


// CTransferMain 消息处理程序


void CTransferMain::OnBnClickedConfirm()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(true);

	if(CMysqlForBank::TransferMain(CTransfer::OderToNum,m_money)){
		//成功
		
		if(!CBankUIDlg::m_LanguageChose){
				MessageBox(_T("转账成功!"));
			}else{
				MessageBox(_T("Transfer successful!"));
			}
		
		
		OnOK();
		CLogInMenu LogInMenu;
		LogInMenu .DoModal();


	}else{
		//失败
		
			if(!CBankUIDlg::m_LanguageChose){
				MessageBox(_T("转账失败!"));
			}else{
				MessageBox(_T("Transfer failed!"));
			}
		
		OnOK();
		CLogInMenu LogInMenu;
		LogInMenu .DoModal();
		

	}

	return ;


}


BOOL CTransferMain::PreTranslateMessage(MSG* pMsg)
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

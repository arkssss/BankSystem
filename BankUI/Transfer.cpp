// Transfer.cpp : 实现文件
//

#include "stdafx.h"
#include "BankUI.h"
#include "Transfer.h"
#include "afxdialogex.h"
#include "MysqlForBank.h"
#include "BankUIDlg.h"
#include "TransferMain.h"
#include "LogInMenu.h"
// CTransfer 对话框
//-----静态变量声明
CString CTransfer::OderToNum;
CString CTransfer::OderToid;	
//

IMPLEMENT_DYNAMIC(CTransfer, CDialogEx)

CTransfer::CTransfer(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTransfer::IDD, pParent)
	, ToNum(_T(""))
{

}

CTransfer::~CTransfer()
{
}

void CTransfer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TransferNum, ToNum);
}


BEGIN_MESSAGE_MAP(CTransfer, CDialogEx)
	ON_BN_CLICKED(IDC_Confirm, &CTransfer::OnBnClickedConfirm)
	ON_BN_CLICKED(IDC_Back, &CTransfer::OnBnClickedBack)
END_MESSAGE_MAP()


// CTransfer 消息处理程序


void CTransfer::OnBnClickedConfirm()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if(ToNum==CBankUIDlg::CurrentCard.cardNum) {
		CBankUIDlg::AIVoice.PlayThisVoice(CanNot_ToYouself);
			if(!CBankUIDlg::m_LanguageChose){
				MessageBox(_T("不能给自己转账!"));	
			}else{
				MessageBox(_T("Can not transfer to myself！"));
			}
		
		
		
		return ;
	}
	if(CMysqlForBank::TransferJdNum(ToNum)){
		//赋予全局变量
		OderToNum=ToNum;
		OnOK();
		CTransferMain  TransferMain;
		TransferMain.DoModal();

	}else{
	
		if(!CBankUIDlg::m_LanguageChose){
				MessageBox(_T("不存在该账户!"));	
		}else{
			MessageBox(_T("This account does not exist！"));
		}
		
		
	}


}


void CTransfer::OnBnClickedBack()
{
		OnOK();
		CLogInMenu  LogInMenu;
		LogInMenu.DoModal();	
	// TODO: 在此添加控件通知处理程序代码
}


BOOL CTransfer::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化
	this->SetWindowText(CBankUIDlg::Language.Dlg1_transfer);
	GetDlgItem(IDC_Confirm)->SetWindowText(CBankUIDlg::Language.Dlg3_Confirm);
	GetDlgItem(IDC_STATIC)->SetWindowText(CBankUIDlg::Language.Dlg5_Input_CardNumber);
	GetDlgItem(IDC_Back)->SetWindowText(CBankUIDlg::Language.Dlg2_Back);



	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


BOOL CTransfer::PreTranslateMessage(MSG* pMsg)
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

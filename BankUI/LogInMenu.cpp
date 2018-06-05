// LogInMenu.cpp : ʵ���ļ�
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
// CLogInMenu �Ի���




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


// CLogInMenu ��Ϣ�������


void CLogInMenu::OnBnClickedBlacnce()
{	
	OnOK();
	CShowBlance BlanceDlg;
	BlanceDlg.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CLogInMenu::OnBnClickeddeposite()
{
	OnOK();
	CDeposite Depositedlg;
	Depositedlg.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CLogInMenu::OnBnClickedwithdraw()
{
	OnOK();
	CWithDraw Withdrawdlg;
	Withdrawdlg.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


//�˳�
void CLogInMenu::OnBnClickedBackup()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		
	int Icomd;
	if(!CBankUIDlg::m_LanguageChose){
	 Icomd=MessageBox(_T("��ȷ��Ҫ�˳���?"),_T("ע��"),IDOK);
	}else{
	 Icomd=MessageBox(_T("Are you sure to quit?"),_T("note"),IDOK);
	}

	if(Icomd==1){
		//����ȷ����
		CMysqlForBank::ExitCard();
		OnOK();
		CBankUIDlg LogIn;
		LogIn.DoModal();
	}


}


BOOL CLogInMenu::OnInitDialog()
{
	CDialogEx::OnInitDialog();

		// TODO:  �ڴ���Ӷ���ĳ�ʼ��
		CMenu* pMenu = this->GetSystemMenu(FALSE);//ϵͳ�˵�
		pMenu->ModifyMenu(SC_CLOSE,MF_BYCOMMAND | MF_GRAYED );//���ùرհ�

		//����
		CBankUIDlg::AIVoice.PlayThisVoice(Lonin_Menu);

		//���Գ�ʼ��
		this->SetWindowText(CBankUIDlg::Language.Dlg1_Caption);
	    GetDlgItem(IDC_STATIC)->SetWindowText(CBankUIDlg::Language.Dlg1_Tip);
				GetDlgItem(IDC_Blacnce)->SetWindowText(CBankUIDlg::Language.Dlg1_Show_Balance);
		GetDlgItem(IDC_deposite)->SetWindowText(CBankUIDlg::Language.Dlg1_Deposite);
		GetDlgItem(IDC_withdraw)->SetWindowText(CBankUIDlg::Language.Dlg1_Withdraw);
		GetDlgItem(transfer)->SetWindowText(CBankUIDlg::Language.Dlg1_transfer);
		GetDlgItem(IDC_ChangePwd)->SetWindowText(CBankUIDlg::Language.Dlg1_ChangePWD);
		GetDlgItem(IDC_BackUp)->SetWindowText(CBankUIDlg::Language.Dlg1_refund_cards);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CLogInMenu::OnBnClickedtransfer()
{

		OnOK();
		CTransfer Transfer;
		Transfer.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CLogInMenu::OnBnClickedChangepwd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// ��������
	OnOK();
	C_ChangePwd ChangePwd;
	ChangePwd.DoModal();

}


BOOL CLogInMenu::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message == WM_KEYDOWN)
	{
		switch(pMsg->wParam)
		{
		case VK_RETURN:    // ���λس�
			
			return true;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

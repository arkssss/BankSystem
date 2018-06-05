// Deposite.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BankUI.h"
#include "Deposite.h"
#include "afxdialogex.h"
#include "MysqlForBank.h"
#include "BankUIDlg.h"
#include "LogInMenu.h"
// CDeposite �Ի���

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


// CDeposite ��Ϣ�������








void CDeposite::OnBnClickedConfirm()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(CMysqlForBank::Deposite(m_money)){
		//���ɹ� 
		CBankUIDlg::AIVoice.PlayThisVoice(Deposit_Successful);
		if(!CBankUIDlg::m_LanguageChose){
				
				MessageBox(_T("���ɹ�"));
			}else{
				MessageBox(_T("Deposit successful��"));
			}
					

		//ҳ����ת	
		OnOK();
		CLogInMenu Menu;
		Menu.DoModal();
	}else{
			CBankUIDlg::AIVoice.PlayThisVoice(Deposit_Fail);
			if(!CBankUIDlg::m_LanguageChose){
				MessageBox(_T("���ʧ��"));
			}else{
				MessageBox(_T("Deposit failed��"));
			}

	}


}


void CDeposite::OnBnClickedBack()
{
		OnOK();
		CLogInMenu  BlanceDlg;
		BlanceDlg.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

BOOL CDeposite::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	CMenu* pMenu = this->GetSystemMenu(FALSE);//ϵͳ�˵�
	pMenu->ModifyMenu(SC_CLOSE,MF_BYCOMMAND | MF_GRAYED );//���ùرհ�

	//��ʼ�����Ժ���
	this->SetWindowText(CBankUIDlg::Language.Dlg1_Deposite);
	GetDlgItem(IDC_Confirm)->SetWindowText(CBankUIDlg::Language.Dlg3_Confirm);
	GetDlgItem(IDC_STATIC)->SetWindowText(CBankUIDlg::Language.Dlg3_deplsit_money);
	GetDlgItem(IDC_Back)->SetWindowText(CBankUIDlg::Language.Dlg2_Back);
	
	



	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


BOOL CDeposite::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
			if(pMsg->message == WM_KEYDOWN)
	{
		switch(pMsg->wParam)
		{
		case VK_RETURN:    // ���λس�
			OnBnClickedConfirm();
			return true;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

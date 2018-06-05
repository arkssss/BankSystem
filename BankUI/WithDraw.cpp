// WithDraw.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BankUI.h"
#include "WithDraw.h"
#include "afxdialogex.h"
#include "MysqlForBank.h"
#include "LogInMenu.h"

// CWithDraw �Ի���

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


// CWithDraw ��Ϣ�������


void CWithDraw::OnBnClickedConfirm()
{	//ȡ���ȷ���¼� 
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);


	if(CMysqlForBank::WithDraw(m_money)) {
	//�ɹ�
		    CBankUIDlg::AIVoice.PlayThisVoice(Withdraw_Successful);
			if(!CBankUIDlg::m_LanguageChose){
				MessageBox(_T("ȡ��ɹ�"));
			}else{
				MessageBox(_T("Withdrawals successful!"));
			}	
		
		//ҳ����ת	
		OnOK();
		CLogInMenu Menu;
		Menu.DoModal();
	}else{
	//ʧ��
			CBankUIDlg::AIVoice.PlayThisVoice(Withdraw_Fail);
			if(!CBankUIDlg::m_LanguageChose){
				MessageBox(_T("ȡ��ʧ��"));
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


BOOL CWithDraw::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	CMenu* pMenu = this->GetSystemMenu(FALSE);//ϵͳ�˵�
	pMenu->ModifyMenu(SC_CLOSE,MF_BYCOMMAND | MF_GRAYED );//���ùرհ�

	//���Գ�ʼ������
	this->SetWindowText(CBankUIDlg::Language.Dlg1_Withdraw);
	GetDlgItem(IDC_STATIC)->SetWindowText(CBankUIDlg::Language.Dlg4_withdrawal_money);
	GetDlgItem(IDC_Confirm)->SetWindowText(CBankUIDlg::Language.Dlg3_Confirm);
	GetDlgItem(IDC_Back)->SetWindowText(CBankUIDlg::Language.Dlg2_Back);






	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


BOOL CWithDraw::PreTranslateMessage(MSG* pMsg)
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

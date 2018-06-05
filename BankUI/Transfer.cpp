// Transfer.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BankUI.h"
#include "Transfer.h"
#include "afxdialogex.h"
#include "MysqlForBank.h"
#include "BankUIDlg.h"
#include "TransferMain.h"
#include "LogInMenu.h"
// CTransfer �Ի���
//-----��̬��������
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


// CTransfer ��Ϣ�������


void CTransfer::OnBnClickedConfirm()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(ToNum==CBankUIDlg::CurrentCard.cardNum) {
		CBankUIDlg::AIVoice.PlayThisVoice(CanNot_ToYouself);
			if(!CBankUIDlg::m_LanguageChose){
				MessageBox(_T("���ܸ��Լ�ת��!"));	
			}else{
				MessageBox(_T("Can not transfer to myself��"));
			}
		
		
		
		return ;
	}
	if(CMysqlForBank::TransferJdNum(ToNum)){
		//����ȫ�ֱ���
		OderToNum=ToNum;
		OnOK();
		CTransferMain  TransferMain;
		TransferMain.DoModal();

	}else{
	
		if(!CBankUIDlg::m_LanguageChose){
				MessageBox(_T("�����ڸ��˻�!"));	
		}else{
			MessageBox(_T("This account does not exist��"));
		}
		
		
	}


}


void CTransfer::OnBnClickedBack()
{
		OnOK();
		CLogInMenu  LogInMenu;
		LogInMenu.DoModal();	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


BOOL CTransfer::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	this->SetWindowText(CBankUIDlg::Language.Dlg1_transfer);
	GetDlgItem(IDC_Confirm)->SetWindowText(CBankUIDlg::Language.Dlg3_Confirm);
	GetDlgItem(IDC_STATIC)->SetWindowText(CBankUIDlg::Language.Dlg5_Input_CardNumber);
	GetDlgItem(IDC_Back)->SetWindowText(CBankUIDlg::Language.Dlg2_Back);



	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


BOOL CTransfer::PreTranslateMessage(MSG* pMsg)
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

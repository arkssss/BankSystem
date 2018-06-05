// TransferMain.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BankUI.h"
#include "TransferMain.h"
#include "afxdialogex.h"
#include "MysqlForBank.h"
#include "Transfer.h"
#include "BankUIDlg.h"
#include "LogInMenu.h"
// CTransferMain �Ի���

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


// CTransferMain ��Ϣ�������


void CTransferMain::OnBnClickedConfirm()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	UpdateData(true);

	if(CMysqlForBank::TransferMain(CTransfer::OderToNum,m_money)){
		//�ɹ�
		
		if(!CBankUIDlg::m_LanguageChose){
				MessageBox(_T("ת�˳ɹ�!"));
			}else{
				MessageBox(_T("Transfer successful!"));
			}
		
		
		OnOK();
		CLogInMenu LogInMenu;
		LogInMenu .DoModal();


	}else{
		//ʧ��
		
			if(!CBankUIDlg::m_LanguageChose){
				MessageBox(_T("ת��ʧ��!"));
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

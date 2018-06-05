// ShowBlance.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BankUI.h"
#include "ShowBlance.h"
#include "afxdialogex.h"
#include "BankUIDlg.h"
#include "LogInMenu.h"
// CShowBlance �Ի���

IMPLEMENT_DYNAMIC(CShowBlance, CDialogEx)

//���캯��
CShowBlance::CShowBlance(CWnd* pParent /*=NULL*/)
	: CDialogEx(CShowBlance::IDD, pParent)
	, m_Balance(CBankUIDlg::CurrentCard.balance)
{
	


}

CShowBlance::~CShowBlance()
{
}

void CShowBlance::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ShowBlance, m_Balance);
}


BEGIN_MESSAGE_MAP(CShowBlance, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_Back, &CShowBlance::OnBnClickedBack)
END_MESSAGE_MAP()


// CShowBlance ��Ϣ�������



void CShowBlance::OnBnClickedBack()
{
		OnOK();
		CLogInMenu  BlanceDlg;
		BlanceDlg.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


BOOL CShowBlance::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	CMenu* pMenu = this->GetSystemMenu(FALSE);//ϵͳ�˵�
	pMenu->ModifyMenu(SC_CLOSE,MF_BYCOMMAND | MF_GRAYED );//���ùرհ�
	
	//���Գ�ʼ������
	this->SetWindowText(CBankUIDlg::Language.Dlg1_Show_Balance);
	GetDlgItem(IDC_STATIC_YouBalacne)->SetWindowText(CBankUIDlg::Language.Dlg2_You_Balance);
	GetDlgItem(IDC_Back)->SetWindowText(CBankUIDlg::Language.Dlg2_Back);







	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


BOOL CShowBlance::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message == WM_KEYDOWN)
	{
		switch(pMsg->wParam)
		{
		case VK_RETURN:    // ���λس�
			OnBnClickedBack();
			return true;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

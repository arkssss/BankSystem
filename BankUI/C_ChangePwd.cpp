// C_ChangePwd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BankUI.h"
#include "C_ChangePwd.h"
#include "afxdialogex.h"
#include "BankUIDlg.h"
#include "MysqlForBank.h"
#include "LogInMenu.h"
// C_ChangePwd �Ի���

IMPLEMENT_DYNAMIC(C_ChangePwd, CDialogEx)

C_ChangePwd::C_ChangePwd(CWnd* pParent /*=NULL*/)
	: CDialogEx(C_ChangePwd::IDD, pParent)
	, m_OldPwd(_T(""))
	, m_NewPwd(_T(""))
	, m_AgPwd(_T(""))
{

}

C_ChangePwd::~C_ChangePwd()
{
}

void C_ChangePwd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_Old_Pwd, m_OldPwd);
	DDX_Text(pDX, IDC_EDIT_New_Pwd, m_NewPwd);
	DDX_Text(pDX, IDC_EDIT_Ag_NewPwd, m_AgPwd);
}


BEGIN_MESSAGE_MAP(C_ChangePwd, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_Comfirm, &C_ChangePwd::OnBnClickedButtonComfirm)
	ON_BN_CLICKED(IDC_BUTTON_Back, &C_ChangePwd::OnBnClickedButtonBack)
END_MESSAGE_MAP()


// C_ChangePwd ��Ϣ�������


void C_ChangePwd::OnBnClickedButtonComfirm()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//�ύ�İ�ť
	UpdateData(true);
	if(JudgeInfo()){
		//��֤ͨ���������
		
		if(CMysqlForBank ::ChangePwd(m_NewPwd,CBankUIDlg::CurrentCard.cardNum)){
		
			//����Card��½�Ľṹ
				if(!CBankUIDlg::m_LanguageChose){
					MessageBox(_T("�޸ĳɹ���"));
				}else{
					MessageBox(_T("Successfully modified��"));
				}
			
			CBankUIDlg::CurrentCard.cardPwd=m_NewPwd;
			OnOK();
			CLogInMenu LogInMenu;
			LogInMenu.DoModal();
			

		}else{
				if(!CBankUIDlg::m_LanguageChose){
					MessageBox(_T("������æ���޸�ʧ�ܣ�"));
				}else{
					MessageBox(_T("Server busy, modify failed!��"));
				}
			
		}

	}else{
		//����ȷ
		return ;
	
	}


}
bool C_ChangePwd::JudgeInfo(){
	//��֤
	UpdateData(true);
	if(m_OldPwd!=CBankUIDlg::CurrentCard.cardPwd){
		//�������
		
			if(!CBankUIDlg::m_LanguageChose){
				MessageBox(_T("ԭ�������!"));
			}else{
				MessageBox(_T("The original password is wrong��"));
			}
						
		return false;
	}else if(m_NewPwd!=m_AgPwd){
			
			if(!CBankUIDlg::m_LanguageChose){
				MessageBox(_T("�����������벻һ��!"));
			}else{
				MessageBox(_T("The password input is inconsistent twice��"));
			}

		return false;	
	
	}else if(m_OldPwd==m_NewPwd==m_AgPwd){
			
			if(!CBankUIDlg::m_LanguageChose){
				MessageBox(_T("�����벻��ԭ������ͬ!"));
			}else{
				MessageBox(_T("The new password is not the same as the original password��"));
			}

		return false;
	}else if(m_OldPwd==CBankUIDlg::CurrentCard.cardPwd && m_NewPwd==m_AgPwd){
		//����
		CBankUIDlg::AIVoice.PlayThisVoice(Modify_Successful);

		return true;
	}else{

		return false;
	}

}

BOOL C_ChangePwd::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//��ʼ�����Ժ���
	this->SetWindowText(CBankUIDlg::Language.Dlg1_ChangePWD);
	GetDlgItem(IDC_STATIC_Old)->SetWindowText(CBankUIDlg::Language.Dlg7_Old_Pwd);
	GetDlgItem(IDC_STATIC_New)->SetWindowText(CBankUIDlg::Language.Dlg7_New_Pwd);
	GetDlgItem(IDC_STATIC_NewAg)->SetWindowText(CBankUIDlg::Language.Dlg7_New_Pwd_Ag);
	GetDlgItem(IDC_BUTTON_Comfirm)->SetWindowText(CBankUIDlg::Language.Dlg3_Confirm);
	GetDlgItem(IDC_BUTTON_Back)->SetWindowText(CBankUIDlg::Language.Dlg2_Back);








	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void C_ChangePwd::OnBnClickedButtonBack()
{
			OnOK();
			CLogInMenu LogInMenu;
			LogInMenu.DoModal();

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

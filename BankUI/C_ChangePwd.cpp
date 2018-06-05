// C_ChangePwd.cpp : 实现文件
//

#include "stdafx.h"
#include "BankUI.h"
#include "C_ChangePwd.h"
#include "afxdialogex.h"
#include "BankUIDlg.h"
#include "MysqlForBank.h"
#include "LogInMenu.h"
// C_ChangePwd 对话框

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


// C_ChangePwd 消息处理程序


void C_ChangePwd::OnBnClickedButtonComfirm()
{
	// TODO: 在此添加控件通知处理程序代码
	//提交的按钮
	UpdateData(true);
	if(JudgeInfo()){
		//验证通过则改密码
		
		if(CMysqlForBank ::ChangePwd(m_NewPwd,CBankUIDlg::CurrentCard.cardNum)){
		
			//更新Card登陆的结构
				if(!CBankUIDlg::m_LanguageChose){
					MessageBox(_T("修改成功！"));
				}else{
					MessageBox(_T("Successfully modified！"));
				}
			
			CBankUIDlg::CurrentCard.cardPwd=m_NewPwd;
			OnOK();
			CLogInMenu LogInMenu;
			LogInMenu.DoModal();
			

		}else{
				if(!CBankUIDlg::m_LanguageChose){
					MessageBox(_T("服务器忙，修改失败！"));
				}else{
					MessageBox(_T("Server busy, modify failed!！"));
				}
			
		}

	}else{
		//不正确
		return ;
	
	}


}
bool C_ChangePwd::JudgeInfo(){
	//验证
	UpdateData(true);
	if(m_OldPwd!=CBankUIDlg::CurrentCard.cardPwd){
		//密码错误
		
			if(!CBankUIDlg::m_LanguageChose){
				MessageBox(_T("原密码错误!"));
			}else{
				MessageBox(_T("The original password is wrong！"));
			}
						
		return false;
	}else if(m_NewPwd!=m_AgPwd){
			
			if(!CBankUIDlg::m_LanguageChose){
				MessageBox(_T("两次密码输入不一致!"));
			}else{
				MessageBox(_T("The password input is inconsistent twice！"));
			}

		return false;	
	
	}else if(m_OldPwd==m_NewPwd==m_AgPwd){
			
			if(!CBankUIDlg::m_LanguageChose){
				MessageBox(_T("新密码不与原密码相同!"));
			}else{
				MessageBox(_T("The new password is not the same as the original password！"));
			}

		return false;
	}else if(m_OldPwd==CBankUIDlg::CurrentCard.cardPwd && m_NewPwd==m_AgPwd){
		//声音
		CBankUIDlg::AIVoice.PlayThisVoice(Modify_Successful);

		return true;
	}else{

		return false;
	}

}

BOOL C_ChangePwd::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//初始化语言函数
	this->SetWindowText(CBankUIDlg::Language.Dlg1_ChangePWD);
	GetDlgItem(IDC_STATIC_Old)->SetWindowText(CBankUIDlg::Language.Dlg7_Old_Pwd);
	GetDlgItem(IDC_STATIC_New)->SetWindowText(CBankUIDlg::Language.Dlg7_New_Pwd);
	GetDlgItem(IDC_STATIC_NewAg)->SetWindowText(CBankUIDlg::Language.Dlg7_New_Pwd_Ag);
	GetDlgItem(IDC_BUTTON_Comfirm)->SetWindowText(CBankUIDlg::Language.Dlg3_Confirm);
	GetDlgItem(IDC_BUTTON_Back)->SetWindowText(CBankUIDlg::Language.Dlg2_Back);








	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void C_ChangePwd::OnBnClickedButtonBack()
{
			OnOK();
			CLogInMenu LogInMenu;
			LogInMenu.DoModal();

	// TODO: 在此添加控件通知处理程序代码
}

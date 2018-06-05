
// BankUIDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "BankUI.h"
#include "BankUIDlg.h"
#include "afxdialogex.h"
#include "LogInMenu.h"
#include "MysqlForBank.h"
#include "Function.h"
#include "CLanguage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//-------静态成员变量初始化
int			CBankUIDlg::m_LogInTimes=0;
C_AIVoice   CBankUIDlg::AIVoice;
CCard		CBankUIDlg::CurrentCard;
Mysql_Op	CBankUIDlg::DB;
CLanguage   CBankUIDlg::Language;
//用户的语言选择 1英文 0中文
int			CBankUIDlg::m_LanguageChose;
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
LogInInfo	CBankUIDlg::LogInfo;
MYsql		CBankUIDlg::My_Mysql;
//--------

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
	MessageBox(_T("111"));
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBankUIDlg 对话框





CBankUIDlg::CBankUIDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBankUIDlg::IDD, pParent)
	, CardNumber(_T(""))
	, CardPassWrod(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBankUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CardNumber, CardNumber);
	DDX_Text(pDX, IDC_PassWord, CardPassWrod);
	DDX_Control(pDX, IDC_COMBO_language, m_cb);
	DDX_Control(pDX, IDC_COMBO_language, m_cb);
}

BEGIN_MESSAGE_MAP(CBankUIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDB_LOGIN, &CBankUIDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_CardNumber, &CBankUIDlg::OnEnChangeEdit1)
	ON_CBN_SELCHANGE(IDC_COMBO_language, &CBankUIDlg::OnCbnSelchangeCombolanguage)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CBankUIDlg 消息处理程序

BOOL CBankUIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_cb.InsertString(0,_T("中文"));
	m_cb.InsertString(1,_T("English"));

	//Status tmp=Log_In; 
	AIVoice.PlayThisVoice(Log_In);

	//初始化为次数
	m_LogInTimes=0;

	//语言直接初始化为中文
	Language(0);




	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CBankUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CBankUIDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		 
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CBankUIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBankUIDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
		UpdateData(true);
		int status;

		if(m_LogInTimes==0){
			//说明是新账号登陆
			//则跟BeForeCardNum 赋值
			BeforeCardNum=CardNumber;
		}

		if(CardNumber!=BeforeCardNum){
			//登陆的为新账号
			m_LogInTimes=0;
			BeforeCardNum=CardNumber;
			//同样的赋值
		}


		if(CMysqlForBank::Login(CardNumber,CardPassWrod,status)){
			//登陆成功 显示菜单界面
			//AIVoice.PlayThisVoice(Login_Successful);
			OnOK();
			CLogInMenu Menu;
			Menu.DoModal();

		}else{ 
			AIVoice.PlayThisVoice(Login_Fail);
			if(status==3){
			
				if(!m_LanguageChose){
					//中文
					MessageBox(_T("账号不存在!"));
				}else{
					MessageBox(_T("Account or password is not correct!"));
					}
		}else if(status==1){
			//冻结		
			
				if(!m_LanguageChose){
					//中文
					MessageBox(_T("该账号被冻结"));
				}else{
					MessageBox(_T("This account has been frozen!"));
					}

		}else if(status==2 && m_LogInTimes<3){
			//密码错误
			
			CString chi;
			chi.Format(_T("密码输入错误 ！！您还有%d次输入机会"),3-m_LogInTimes);
			CString eng;
			eng.Format(_T("Incorrect password ! ! You also have %d chances to enter"),3-m_LogInTimes);
				if(!m_LanguageChose){
					//中文
					MessageBox(chi);
				}else{
					MessageBox(eng);
					}
			
			
		}else if(status==2 && m_LogInTimes==3){
		
			if(CMysqlForBank::FreezenCard(CardNumber)){
				
				
				if(!m_LanguageChose){
					//中文
					MessageBox(_T("该账号被冻结"));
				}else{
					MessageBox(_T("This account has been frozen!"));
					}	
			
			
			}else{
				
				
				if(!m_LanguageChose){
					//中文
					MessageBox(_T("服务器忙"));
				}else{
					MessageBox(_T("Server busy!"));
					}	
			
			
			}
		}
		
		
		}

}


void CBankUIDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


bool CBankUIDlg::KeyDown(MSG* pMsg){

	 if (WM_KEYFIRST <= pMsg->message && pMsg->message <= WM_KEYLAST)
	 {
		MessageBox(_T("111"));
	 }		
	return true;
}

void CBankUIDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}



//下拉框的选择
void CBankUIDlg::OnCbnSelchangeCombolanguage()
{
	// TODO: 在此添加控件通知处理程序代码
		int nIndex = m_cb.GetCurSel();
		//中文 0  英文 1
		//m_cb.GetLBText( nIndex, strCBText);
		//MessageBox(strCBText); 
		m_LanguageChose=nIndex;		
		Language(m_LanguageChose);

		//设置语言
		GetDlgItem(IDC_STATIC_Id)->SetWindowText(Language.BankCardId);
		GetDlgItem(IDC_STATIC_pwd)->SetWindowText(Language.Password);
		GetDlgItem(IDB_LOGIN)->SetWindowText(Language.Login);

}



BOOL CBankUIDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类

		if(pMsg->message == WM_KEYDOWN)
	{
		switch(pMsg->wParam)
		{
		case VK_RETURN:    // 屏蔽回车
			OnBnClickedButton1();
			return true;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

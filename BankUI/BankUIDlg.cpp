
// BankUIDlg.cpp : ʵ���ļ�
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

//-------��̬��Ա������ʼ��
int			CBankUIDlg::m_LogInTimes=0;
C_AIVoice   CBankUIDlg::AIVoice;
CCard		CBankUIDlg::CurrentCard;
Mysql_Op	CBankUIDlg::DB;
CLanguage   CBankUIDlg::Language;
//�û�������ѡ�� 1Ӣ�� 0����
int			CBankUIDlg::m_LanguageChose;
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
LogInInfo	CBankUIDlg::LogInfo;
MYsql		CBankUIDlg::My_Mysql;
//--------

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CBankUIDlg �Ի���





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


// CBankUIDlg ��Ϣ�������

BOOL CBankUIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_cb.InsertString(0,_T("����"));
	m_cb.InsertString(1,_T("English"));

	//Status tmp=Log_In; 
	AIVoice.PlayThisVoice(Log_In);

	//��ʼ��Ϊ����
	m_LogInTimes=0;

	//����ֱ�ӳ�ʼ��Ϊ����
	Language(0);




	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CBankUIDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		 
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CBankUIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBankUIDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		UpdateData(true);
		int status;

		if(m_LogInTimes==0){
			//˵�������˺ŵ�½
			//���BeForeCardNum ��ֵ
			BeforeCardNum=CardNumber;
		}

		if(CardNumber!=BeforeCardNum){
			//��½��Ϊ���˺�
			m_LogInTimes=0;
			BeforeCardNum=CardNumber;
			//ͬ���ĸ�ֵ
		}


		if(CMysqlForBank::Login(CardNumber,CardPassWrod,status)){
			//��½�ɹ� ��ʾ�˵�����
			//AIVoice.PlayThisVoice(Login_Successful);
			OnOK();
			CLogInMenu Menu;
			Menu.DoModal();

		}else{ 
			AIVoice.PlayThisVoice(Login_Fail);
			if(status==3){
			
				if(!m_LanguageChose){
					//����
					MessageBox(_T("�˺Ų�����!"));
				}else{
					MessageBox(_T("Account or password is not correct!"));
					}
		}else if(status==1){
			//����		
			
				if(!m_LanguageChose){
					//����
					MessageBox(_T("���˺ű�����"));
				}else{
					MessageBox(_T("This account has been frozen!"));
					}

		}else if(status==2 && m_LogInTimes<3){
			//�������
			
			CString chi;
			chi.Format(_T("����������� ����������%d���������"),3-m_LogInTimes);
			CString eng;
			eng.Format(_T("Incorrect password ! ! You also have %d chances to enter"),3-m_LogInTimes);
				if(!m_LanguageChose){
					//����
					MessageBox(chi);
				}else{
					MessageBox(eng);
					}
			
			
		}else if(status==2 && m_LogInTimes==3){
		
			if(CMysqlForBank::FreezenCard(CardNumber)){
				
				
				if(!m_LanguageChose){
					//����
					MessageBox(_T("���˺ű�����"));
				}else{
					MessageBox(_T("This account has been frozen!"));
					}	
			
			
			}else{
				
				
				if(!m_LanguageChose){
					//����
					MessageBox(_T("������æ"));
				}else{
					MessageBox(_T("Server busy!"));
					}	
			
			
			}
		}
		
		
		}

}


void CBankUIDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}



//�������ѡ��
void CBankUIDlg::OnCbnSelchangeCombolanguage()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		int nIndex = m_cb.GetCurSel();
		//���� 0  Ӣ�� 1
		//m_cb.GetLBText( nIndex, strCBText);
		//MessageBox(strCBText); 
		m_LanguageChose=nIndex;		
		Language(m_LanguageChose);

		//��������
		GetDlgItem(IDC_STATIC_Id)->SetWindowText(Language.BankCardId);
		GetDlgItem(IDC_STATIC_pwd)->SetWindowText(Language.Password);
		GetDlgItem(IDB_LOGIN)->SetWindowText(Language.Login);

}



BOOL CBankUIDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���

		if(pMsg->message == WM_KEYDOWN)
	{
		switch(pMsg->wParam)
		{
		case VK_RETURN:    // ���λس�
			OnBnClickedButton1();
			return true;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

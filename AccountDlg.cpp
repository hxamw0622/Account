// AccountDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Account.h"
#include "AccountDlg.h"

#include   <windows.h>   
#include   <stdio.h> 


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
int Dialog_Type=-1;
int Cancel_Label=0;
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAccountDlg dialog

CAccountDlg::CAccountDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAccountDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAccountDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	strcpy(user_data_file_name,"user_data.dat");
	//MessageBox("abc");
	
}

void CAccountDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAccountDlg)
	DDX_Control(pDX, IDC_COMBO1, m_item);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAccountDlg, CDialog)
	//{{AFX_MSG_MAP(CAccountDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SEARCH, OnSearch)
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_MODIFY, OnModify)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAccountDlg message handlers

BOOL CAccountDlg::OnInitDialog()
{
	
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
    // TODO: Add extra initialization here
	if( LoadUserData(user_data_file_name) == -1 )
	{
		MessageBox("Load User Data Error");
		return FALSE;
	}
	else
		MessageBox("Load OK");
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAccountDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAccountDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAccountDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

int CAccountDlg::LoadUserData(char *file_name)
{
	int ret;
	int i=0;
	
	ret = FileOpt.LoadFile(file_name);
	if(ret == -1 )
	{
		MessageBox("Load Error");
		return false;
	}
    m_item.DeleteString(-1);
    for(i=0;i<total_count;i++)
	{
       m_item.AddString(user_data[i].account_name);
	}
	return 1;
}

void CAccountDlg::OnSearch() 
{
	// TODO: Add your control notification handler code here
    char account_name[100];
	int ret;
	m_item.GetWindowText(account_name,100);
	ret = FileOpt.AccountSearch(account_name);
	item_count = ret;
	Dialog_Type = SEARCH;
    InfoDlg.DoModal();

	
}

void CAccountDlg::OnRemove() 
{
	// TODO: Add your control notification handler code here
    char account_name[100];
	m_item.GetWindowText(account_name,30);
	FileOpt.AccountRemove(account_name);
	m_item.DeleteString(m_item.GetCurSel());
	MessageBox("Remove account OK!");
}

void CAccountDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	Dialog_Type = ADD;
	InfoDlg.DoModal();
	if(Cancel_Label == 0)
    {
		m_item.AddString((LPCTSTR)user_data[total_count-1].account_name);
		MessageBox("Add account OK!");
	}
}

void CAccountDlg::OnModify() 
{
	// TODO: Add your control notification handler code here
	char account_name[100];
	int ret;
	m_item.GetWindowText(account_name,30);
	ret = FileOpt.AccountSearch(account_name);
	item_count = ret;
	Dialog_Type = MODIFY;
    InfoDlg.DoModal();
	if(Cancel_Label == 0)
    {
		MessageBox("Modify account OK!");
	}
}


void CAccountDlg::OnDestroy() 
{

    char current_path[256],tmp_data_file[256],user_data_file[256];
    GetCurrentDirectory(256,current_path); 
	strcpy(user_data_file,current_path);
	strcpy(tmp_data_file,current_path);
    strcat(user_data_file,"\\user_data.dat");
	strcat(tmp_data_file,"\\tmp_data.dat");

	CDialog::OnDestroy();
	int i;
	// TODO: Add your message handler code here
	fstream fp;
	fp.open("tmp_data.dat",ios::binary|ios::out);
	if(fp.fail())
	{
		MessageBox("The database does not exist!");
		exit(0);
	}
	for(i=0;i<total_count;i++)
	{
		if(user_data[i].valid == 1)
			fp.write((char *)&user_data[i],sizeof(struct User_Data));
	}
	fp.close();
    
	DeleteFile(user_data_file);
	MoveFile(tmp_data_file,user_data_file);
}

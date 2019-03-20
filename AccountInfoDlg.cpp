// AccountInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "account.h"
#include "AccountInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAccountInfoDlg dialog
extern int item_count;

CAccountInfoDlg::CAccountInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAccountInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAccountInfoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAccountInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAccountInfoDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAccountInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CAccountInfoDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAccountInfoDlg message handlers

BOOL CAccountInfoDlg::OnInitDialog() 
{
	CEdit *pEdit;
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	switch(Dialog_Type)
	{
	case ADD:    SetWindowText("ADD");
		         break;

	case MODIFY: SetWindowText("MODIFY");
		         pEdit=(CEdit*)GetDlgItem(IDC_ACCOUNT);
			     pEdit->SetReadOnly(true);
		         GetDlgItem(IDC_ACCOUNT)->SetWindowText(user_data[item_count].account_name);
				 GetDlgItem(IDC_USER)->SetWindowText(user_data[item_count].user);
				 GetDlgItem(IDC_PASSWD)->SetWindowText(user_data[item_count].password);
				 GetDlgItem(IDC_CONTENT)->SetWindowText(user_data[item_count].content);
		         break;

	case SEARCH: SetWindowText("SEARCH");
                 pEdit=(CEdit*)GetDlgItem(IDC_ACCOUNT);
			     pEdit->SetReadOnly(true);
				 pEdit=(CEdit*)GetDlgItem(IDC_USER);
			     pEdit->SetReadOnly(true);
				 pEdit=(CEdit*)GetDlgItem(IDC_PASSWD);
			     pEdit->SetReadOnly(true);
				 pEdit=(CEdit*)GetDlgItem(IDC_CONTENT);
			     pEdit->SetReadOnly(true);

		         GetDlgItem(IDC_ACCOUNT)->SetWindowText(user_data[item_count].account_name);
				 GetDlgItem(IDC_USER)->SetWindowText(user_data[item_count].user);
				 GetDlgItem(IDC_PASSWD)->SetWindowText(user_data[item_count].password);
				 GetDlgItem(IDC_CONTENT)->SetWindowText(user_data[item_count].content);
		         break;
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAccountInfoDlg::OnOK() 
{
	// TODO: Add extra validation here
	char account_name[20];
	int label=0;
	switch(Dialog_Type)
	{
	case ADD:    GetDlgItem(IDC_ACCOUNT)->GetWindowText(account_name,100);
		         if(strcmp(account_name,"") != 0)
				 {
					 strcpy(user_data[total_count].account_name,account_name);
					 GetDlgItem(IDC_USER)->GetWindowText(user_data[total_count].user,30);
					 GetDlgItem(IDC_PASSWD)->GetWindowText(user_data[total_count].password,30);
					 GetDlgItem(IDC_CONTENT)->GetWindowText(user_data[total_count].content,500);
					 user_data[total_count].valid = 1;
					 total_count++;
				 }
                 else
				 {
					 MessageBox("The account_name is NULL");
					 label = 1;
				 }
		         break;

	case MODIFY: GetDlgItem(IDC_ACCOUNT)->GetWindowText(user_data[item_count].account_name,30);
				 GetDlgItem(IDC_USER)->GetWindowText(user_data[item_count].user,30);
				 GetDlgItem(IDC_PASSWD)->GetWindowText(user_data[item_count].password,30);
				 GetDlgItem(IDC_CONTENT)->GetWindowText(user_data[item_count].content,500);
		         break;

	case SEARCH: GetDlgItem(IDC_ACCOUNT)->SetWindowText(user_data[item_count].account_name);
				 GetDlgItem(IDC_USER)->SetWindowText(user_data[item_count].user);
				 GetDlgItem(IDC_PASSWD)->SetWindowText(user_data[item_count].password);
				 GetDlgItem(IDC_CONTENT)->SetWindowText(user_data[item_count].content);
		         break;
	}
	if(label == 0)
		CDialog::OnOK();
	Cancel_Label = 0;
}

void CAccountInfoDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	Cancel_Label = 1;
	CDialog::OnCancel();
}

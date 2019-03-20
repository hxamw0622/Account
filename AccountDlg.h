// AccountDlg.h : header file
//

#if !defined(AFX_ACCOUNTDLG_H__A0B42930_4411_4C2A_B540_36928AAA55F2__INCLUDED_)
#define AFX_ACCOUNTDLG_H__A0B42930_4411_4C2A_B540_36928AAA55F2__INCLUDED_

#include "FileOperation.h"	// Added by ClassView
#include "AccountInfoDlg.h"  // Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAccountDlg dialog

class CAccountDlg : public CDialog
{
// Construction
public:
	CAccountInfoDlg InfoDlg;
	FileOperation FileOpt;
	int LoadUserData(char *file_name);
	CAccountDlg(CWnd* pParent = NULL);	// standard constructor
// Dialog Data
	//{{AFX_DATA(CAccountDlg)
	enum { IDD = IDD_ACCOUNT_DIALOG };
	CComboBox	m_item;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAccountDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAccountDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSearch();
	afx_msg void OnRemove();
	afx_msg void OnAdd();
	afx_msg void OnModify();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	char user_data_file_name[100];
};



//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACCOUNTDLG_H__A0B42930_4411_4C2A_B540_36928AAA55F2__INCLUDED_)

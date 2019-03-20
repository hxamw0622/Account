#if !defined(AFX_ACCOUNTINFODLG_H__11F68D2F_DE2B_411F_9C42_6D7E5BCFA743__INCLUDED_)
#define AFX_ACCOUNTINFODLG_H__11F68D2F_DE2B_411F_9C42_6D7E5BCFA743__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AccountInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAccountInfoDlg dialog

class CAccountInfoDlg : public CDialog
{
// Construction
public:
	CAccountInfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAccountInfoDlg)
	enum { IDD = IDD_INFO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAccountInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAccountInfoDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACCOUNTINFODLG_H__11F68D2F_DE2B_411F_9C42_6D7E5BCFA743__INCLUDED_)

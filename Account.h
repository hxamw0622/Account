// Account.h : main header file for the ACCOUNT application
//

#if !defined(AFX_ACCOUNT_H__2469ED6F_7CF3_4EF3_92D5_BC405026A5D3__INCLUDED_)
#define AFX_ACCOUNT_H__2469ED6F_7CF3_4EF3_92D5_BC405026A5D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include <fstream.h>
/////////////////////////////////////////////////////////////////////////////
// CAccountApp:
// See Account.cpp for the implementation of this class
//

class CAccountApp : public CWinApp
{
public:
	CAccountApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAccountApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAccountApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CString Add_Account;
extern CString Add_Passwd;
extern CString Modify_Account;
extern CString Modify_Passwd;

#define SEARCH 0
#define ADD 1
#define MODIFY 2


struct User_Data
{
	char account_name[30];
	char user[30];
	char password[30];
	char content[500];
	bool valid;
};

extern struct User_Data user_data[1000];
extern int total_count;
extern int Dialog_Type;
extern int item_count;
extern int Cancel_Label;
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACCOUNT_H__2469ED6F_7CF3_4EF3_92D5_BC405026A5D3__INCLUDED_)

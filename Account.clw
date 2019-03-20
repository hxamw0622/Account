; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAccountDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "account.h"
LastPage=0

ClassCount=4
Class1=CAccountApp
Class2=CAboutDlg
Class3=CAccountDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX (English (U.S.))
Resource2=IDD_INFO_DIALOG
Class4=CAccountInfoDlg
Resource3=IDD_ACCOUNT_DIALOG (English (U.S.))

[CLS:CAccountApp]
Type=0
BaseClass=CWinApp
HeaderFile=Account.h
ImplementationFile=Account.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=AccountDlg.cpp
ImplementationFile=AccountDlg.cpp
LastObject=CAboutDlg

[CLS:CAccountDlg]
Type=0
BaseClass=CDialog
HeaderFile=AccountDlg.h
ImplementationFile=AccountDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=CAccountDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg

[DLG:IDD_ACCOUNT_DIALOG]
Type=1
Class=CAccountDlg

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ACCOUNT_DIALOG (English (U.S.))]
Type=1
Class=CAccountDlg
ControlCount=6
Control1=IDC_COMBO1,combobox,1344341314
Control2=IDC_SEARCH,button,1342242816
Control3=IDC_ADD,button,1342242816
Control4=IDC_REMOVE,button,1342242816
Control5=IDC_MODIFY,button,1342242816
Control6=IDC_STATIC,static,1342308352

[DLG:IDD_INFO_DIALOG]
Type=1
Class=CAccountInfoDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDC_PASSWD,edit,1350631552
Control3=IDC_USER,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDCANCEL,button,1342242817
Control7=IDC_CONTENT,edit,1350635716
Control8=IDC_STATIC,static,1342308352
Control9=IDC_ACCOUNT,edit,1350631552
Control10=IDC_STATIC,static,1342308352

[CLS:CAccountInfoDlg]
Type=0
HeaderFile=AccountInfoDlg.h
ImplementationFile=AccountInfoDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CAccountInfoDlg
VirtualFilter=dWC


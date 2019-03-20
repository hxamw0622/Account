// FileOperation.h: interface for the FileOperation class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILEOPERATION_H__2A84C2CD_F123_4995_BB80_16A1C6D4AC8C__INCLUDED_)
#define AFX_FILEOPERATION_H__2A84C2CD_F123_4995_BB80_16A1C6D4AC8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class FileOperation  
{
public:
	int AccountModify(char *account_name,char *user,char *account_passwd,char *content);
	int AccountSearch(char *account_name);
	int AccountRemove(char *account_name);
	int AccountAdd(char *account_name,char *user,char *account_passwd,char *content);
	int LoadFile(char *account_file);
	FileOperation();
	virtual ~FileOperation();

private:
	char user_data_file_name[100];
};

#endif // !defined(AFX_FILEOPERATION_H__2A84C2CD_F123_4995_BB80_16A1C6D4AC8C__INCLUDED_)

// FileOperation.cpp: implementation of the FileOperation class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Account.h"
#include "FileOperation.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif




//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
struct User_Data user_data[1000];
int total_count=0;

FileOperation::FileOperation()
{

}

FileOperation::~FileOperation()
{

}

int FileOperation::LoadFile(char *account_name)//load user data to memory is a plus function
{
	fstream fp;
	int i=0;
	fp.open(account_name,ios::in|ios::binary);
    if(fp.fail())
		return -1;
	while(!fp.eof())
	{
		fp.read((char *)&user_data[i],sizeof(struct User_Data));
		i++;
	}
	total_count = i;
	fp.close();
    return 1;
}

int FileOperation::AccountSearch(char *account_name) //return the index found in the array
{
    int i=0;
	for(i=0;i<total_count;i++)
	{
		if(strcmp(account_name,user_data[i].account_name)==0)
			break;
	}
    return i;
}


int FileOperation::AccountRemove(char *account_name)
{
	int i=0;
	for(i=0;i<total_count;i++)
	{
		if(strcmp(account_name,user_data[i].account_name)==0)
			break;
	}
    user_data[i].valid = false;
	return 1;
}

int FileOperation::AccountModify(char *account_name,char *user,char *account_passwd,char *content)
{
	int i=0;
	for(i=0;i<total_count;i++)
	{
		if(strcmp(account_name,user_data[i].account_name)==0)
			break;
	}
    strcpy(user_data[i].user,user);
	strcpy(user_data[i].password,account_passwd);
	strcpy(user_data[i].content,content);
    return 1;
}


int FileOperation::AccountAdd(char *account_name,char *user,char *account_passwd,char *content)
{
	strcpy(user_data[total_count].account_name,account_name);
	strcpy(user_data[total_count].user,user);
	strcpy(user_data[total_count].password,account_passwd);
	strcpy(user_data[total_count].content,content);
	user_data[total_count].valid = true;
	total_count++;
    return 1;
}

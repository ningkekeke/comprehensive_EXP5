// MyDlgAdd.cpp : 实现文件
//

#include "stdafx.h"
#include "CompExp.h"
#include "MyDlgAdd.h"
#include "afxdialogex.h"


// MyDlgAdd 对话框

IMPLEMENT_DYNAMIC(MyDlgAdd, CDialogEx)

MyDlgAdd::MyDlgAdd(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG5, pParent)
	, a_id(0)
	, a_name(_T(""))
	, a_number(_T(""))
	, a_pro(_T(""))
	, a_sex(_T(""))
	, a_birth(_T(""))
	, a_pnumber(_T(""))
	, a_ad(_T(""))
	, a_filename(_T(""))
	
{

}

MyDlgAdd::~MyDlgAdd()
{
}

void MyDlgAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a_id);
	DDX_Text(pDX, IDC_EDIT3, a_name);
	DDX_Text(pDX, IDC_EDIT2, a_number);
	DDX_Text(pDX, IDC_EDIT5, a_pro);
	DDX_Text(pDX, IDC_EDIT4, a_sex);
	DDX_Text(pDX, IDC_EDIT6, a_birth);
	DDX_Text(pDX, IDC_EDIT7, a_pnumber);
	DDX_Text(pDX, IDC_EDIT8, a_ad);
	DDX_Text(pDX, IDC_EDIT9, a_filename);
	
}


BEGIN_MESSAGE_MAP(MyDlgAdd, CDialogEx)
END_MESSAGE_MAP()


// MyDlgAdd 消息处理程序

// MyDlg3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CompExp.h"
#include "MyDlg3.h"
#include "afxdialogex.h"


// MyDlg3 �Ի���

IMPLEMENT_DYNAMIC(MyDlg3, CDialogEx)

MyDlg3::MyDlg3(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, o_text(_T(""))
{

}

MyDlg3::~MyDlg3()
{
}

void MyDlg3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, o_text);
}


BEGIN_MESSAGE_MAP(MyDlg3, CDialogEx)
END_MESSAGE_MAP()


// MyDlg3 ��Ϣ�������

// MyDlg2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CompExp.h"
#include "MyDlg2.h"
#include "afxdialogex.h"


// MyDlg2 �Ի���

IMPLEMENT_DYNAMIC(MyDlg2, CDialogEx)

MyDlg2::MyDlg2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)

	, s_text(_T(""))
{

}

MyDlg2::~MyDlg2()
{
}

void MyDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT2, s_text);
}


BEGIN_MESSAGE_MAP(MyDlg2, CDialogEx)
END_MESSAGE_MAP()


// MyDlg2 ��Ϣ�������

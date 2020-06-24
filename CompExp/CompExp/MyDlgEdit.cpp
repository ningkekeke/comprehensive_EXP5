// MyDlgEdit.cpp : 实现文件
//

#include "stdafx.h"
#include "CompExp.h"
#include "CompExpSet.h"
#include "MyDlgEdit.h"
#include "afxdialogex.h"
#include "CompExpDoc.h"
#include "MainFrm.h"
#include "CompExpView.h"


// MyDlgEdit 对话框

IMPLEMENT_DYNAMIC(MyDlgEdit, CDialogEx)

MyDlgEdit::MyDlgEdit(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG6, pParent)
	, e_id(0)
	, e_name(_T(""))
	, e_number(_T(""))
	, e_pro(_T(""))
	, e_sex(_T(""))
	, e_birth(_T(""))
	, e_pnumber(_T(""))
	, e_ad(_T(""))
	, e_filename(_T(""))
{

}

MyDlgEdit::~MyDlgEdit()
{
}

void MyDlgEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, e_id);
	DDX_Text(pDX, IDC_EDIT3, e_name);
	DDX_Text(pDX, IDC_EDIT2, e_number);
	DDX_Text(pDX, IDC_EDIT5, e_pro);
	DDX_Text(pDX, IDC_EDIT4, e_sex);
	DDX_Text(pDX, IDC_EDIT6, e_birth);
	DDX_Text(pDX, IDC_EDIT7, e_pnumber);
	DDX_Text(pDX, IDC_EDIT8, e_ad);
	DDX_Text(pDX, IDC_EDIT9, e_filename);
}


BEGIN_MESSAGE_MAP(MyDlgEdit, CDialogEx)
END_MESSAGE_MAP()


// MyDlgEdit 消息处理程序


BOOL MyDlgEdit::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	CCompExpView* pView = (CCompExpView*)pFrame->GetActiveView();
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

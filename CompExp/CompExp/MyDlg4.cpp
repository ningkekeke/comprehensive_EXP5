// MyDlg4.cpp : 实现文件
//

#include "stdafx.h"
#include "CompExp.h"
#include "CompExpSet.h"
#include "MyDlg4.h"
#include "afxdialogex.h"


// MyDlg4 对话框

IMPLEMENT_DYNAMIC(MyDlg4, CDialogEx)

MyDlg4::MyDlg4(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, r_text(_T(""))
{

}

MyDlg4::~MyDlg4()
{
}

void MyDlg4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_LBString(pDX, IDC_LIST1, r_text);
}


BEGIN_MESSAGE_MAP(MyDlg4, CDialogEx)
END_MESSAGE_MAP()


// MyDlg4 消息处理程序


BOOL MyDlg4::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_list.ResetContent();
	m_pListSet->MoveFirst();
	int n = m_pListSet->GetODBCFieldCount();
	CString s;
	while (!m_pListSet->IsEOF())
	{
		s.Empty();
		CString str;
		for (int i = 0; i < n; i++)
		{
			m_pListSet->GetFieldValue((short)i, str);
			s += str;
			s += "     ";
		}
		m_list.AddString(s);
		m_pListSet->MoveNext();
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

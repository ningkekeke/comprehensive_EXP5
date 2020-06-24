#pragma once
#include "afxwin.h"


// MyDlg4 对话框

class MyDlg4 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg4)

public:
	MyDlg4(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDlg4();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif
	CCompExpSet* m_pListSet;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_list;
	CString r_text;
	virtual BOOL OnInitDialog();
};

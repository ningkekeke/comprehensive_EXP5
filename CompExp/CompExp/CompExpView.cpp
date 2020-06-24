
// CompExpView.cpp : CCompExpView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CompExp.h"
#endif

#include "CompExpSet.h"
#include "CompExpDoc.h"
#include "CompExpView.h"
#include "MyDlg1.h"
#include "MyDlg2.h"
#include "MyDlg3.h"
#include "MyDlg4.h"
#include "MyDlgAdd.h"
#include "MyDlgEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCompExpView

IMPLEMENT_DYNCREATE(CCompExpView, CRecordView)

BEGIN_MESSAGE_MAP(CCompExpView, CRecordView)
	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_FIRST, &CCompExpView::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CCompExpView::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CCompExpView::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CCompExpView::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON1, &CCompExpView::OnEnLarge)
	ON_BN_CLICKED(IDC_BUTTON2, &CCompExpView::OnSearch)
	ON_BN_CLICKED(IDC_BUTTON3, &CCompExpView::OnOrder)
	ON_BN_CLICKED(IDC_BUTTON4, &CCompExpView::OnRecovery)
	ON_BN_CLICKED(IDC_BUTTON5, &CCompExpView::OnRecordset)
	ON_BN_CLICKED(IDC_BUTTON6, &CCompExpView::OnAdd)
	ON_BN_CLICKED(IDC_BUTTON7, &CCompExpView::OnDelete)
	ON_BN_CLICKED(IDC_BUTTON8, &CCompExpView::OnEdit)
	ON_STN_CLICKED(IDC_PICTURE, &CCompExpView::OnStnClickedPicture)
END_MESSAGE_MAP()

// CCompExpView 构造/析构

CCompExpView::CCompExpView()
	: CRecordView(IDD_COMPEXP_FORM)
	, id(0)
	, name(_T(""))
	, number(_T(""))
	, pro(_T(""))
	, sex(_T(""))
	, birth(_T(""))
	, pnumber(_T(""))
	, ad(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CCompExpView::~CCompExpView()
{
}

void CCompExpView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column4);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column5);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->column6);
	DDX_Text(pDX, IDC_EDIT8, m_pSet->column7);
}

BOOL CCompExpView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CCompExpView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_CompExpSet;
	CRecordView::OnInitialUpdate();

}


// CCompExpView 诊断

#ifdef _DEBUG
void CCompExpView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CCompExpView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CCompExpDoc* CCompExpView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCompExpDoc)));
	return (CCompExpDoc*)m_pDocument;
}
#endif //_DEBUG


// CCompExpView 数据库支持
CRecordset* CCompExpView::OnGetRecordset()
{
	return m_pSet;
}



// CCompExpView 消息处理程序

void CCompExpView::foo(CImage& img, int& sx, int& sy, int& w, int& h)
{
	CRect rect;
	GetDlgItem(IDC_PICTURE)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
}

void CCompExpView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	CString s;
	CImage img;
	CDC *pDC = GetDlgItem(IDC_PICTURE)->GetDC();//凡是用到getdc必须释放它
	pDC->SetStretchBltMode(HALFTONE);//图像不失真
	m_pSet->GetFieldValue(short(8), s);
	filename = s;
	img.Load(s);

	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
}


void CCompExpView::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(true);
	OnPaint();
}


void CCompExpView::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF()) {
		m_pSet->MovePrev();
	}
	UpdateData(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(true);
	OnPaint();
}


void CCompExpView::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveNext();
	}
	UpdateData(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(true);
	OnPaint();
}


void CCompExpView::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(true);
	OnPaint();
}


void CCompExpView::OnEnLarge()
{
	// TODO: 在此添加控件通知处理程序代码
	MyDlg1 dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{

	}
}


void CCompExpView::OnSearch()
{
	// TODO: 在此添加控件通知处理程序代码
	MyDlg2 dlg;
	int r = dlg.DoModal();
	CString s;
	if (r == IDOK)
	{

		s = dlg.s_text;

	}
	m_pSet->m_strFilter = s;
	m_pSet->Requery();
	UpdateData(false);
}


void CCompExpView::OnOrder()
{
	// TODO: 在此添加控件通知处理程序代码
	MyDlg3 dlg;
	int r = dlg.DoModal();
	CString s;
	if (r == IDOK)
	{
		s = dlg.o_text;
	}
	m_pSet->m_strSort = s;
	m_pSet->Requery();
	UpdateData(false);
}


void CCompExpView::OnRecovery()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->m_strFilter = _T("");
	m_pSet->m_strSort = _T("");
	m_pSet->Requery();
	UpdateData(false);
}


void CCompExpView::OnRecordset()
{
	// TODO: 在此添加控件通知处理程序代码
	MyDlg4 dlg;
	dlg.m_pListSet = m_pSet;
	int r = dlg.DoModal();
	if (r == IDOK)
	{

	}
}


void CCompExpView::OnAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	MyDlgAdd add;
	int r = add.DoModal();
	if (r == IDOK)
	{
		long aa_id = add.a_id;
		CString aa_name = add.a_name;
		CString aa_number = add.a_number;
		CString aa_pro = add.a_pro;
		CString aa_sex = add.a_sex;
		CString aa_birth = add.a_birth;
		CString aa_pnumber = add.a_pnumber;
		CString aa_ad = add.a_ad;
		CString aa_filename = add.a_filename;
		m_pSet->AddNew();
		m_pSet->m_ID = aa_id;
		m_pSet->column1 = aa_name;
		m_pSet->column2 = aa_number;
		m_pSet->column3 = aa_pro;
		m_pSet->column4 = aa_sex;
		m_pSet->column5 = aa_birth;
		m_pSet->column6 = aa_pnumber;
		m_pSet->column7 = aa_ad;
		m_pSet->column8 = aa_filename;
		m_pSet->Update();
		UpdateData(false);
	}
}


void CCompExpView::OnDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
	{
		m_pSet->MoveFirst();
	}
	UpdateData(false);
}


void CCompExpView::OnEdit()
{
	// TODO: 在此添加控件通知处理程序代码
	MyDlgEdit edit;
	int r = edit.DoModal();
	if (r == IDOK)
	{
		long ee_id = edit.e_id;
		CString ee_name = edit.e_name;
		CString ee_number = edit.e_number;
		CString ee_pro = edit.e_pro;
		CString ee_sex = edit.e_sex;
		CString ee_birth = edit.e_birth;
		CString ee_pnumber = edit.e_pnumber;
		CString ee_ad = edit.e_ad;
		CString ee_filename = edit.e_filename;
		m_pSet->Edit();
		m_pSet->m_ID = ee_id;
		m_pSet->column1 = ee_name;
		m_pSet->column2 = ee_number;
		m_pSet->column3 = ee_pro;
		m_pSet->column4 = ee_sex;
		m_pSet->column5 = ee_birth;
		m_pSet->column6 = ee_pnumber;
		m_pSet->column7 = ee_ad;
		m_pSet->column8 = ee_filename;
		m_pSet->Update();
		UpdateData(false);
	}
}


void CCompExpView::OnStnClickedPicture()
{
	// TODO: 在此添加控件通知处理程序代码
}

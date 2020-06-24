
// CompExpView.cpp : CCompExpView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CCompExpView ����/����

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
	// TODO: �ڴ˴���ӹ������

}

CCompExpView::~CCompExpView()
{
}

void CCompExpView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CCompExpView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_CompExpSet;
	CRecordView::OnInitialUpdate();

}


// CCompExpView ���

#ifdef _DEBUG
void CCompExpView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CCompExpView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CCompExpDoc* CCompExpView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCompExpDoc)));
	return (CCompExpDoc*)m_pDocument;
}
#endif //_DEBUG


// CCompExpView ���ݿ�֧��
CRecordset* CCompExpView::OnGetRecordset()
{
	return m_pSet;
}



// CCompExpView ��Ϣ�������

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
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
	CString s;
	CImage img;
	CDC *pDC = GetDlgItem(IDC_PICTURE)->GetDC();//�����õ�getdc�����ͷ���
	pDC->SetStretchBltMode(HALFTONE);//ͼ��ʧ��
	m_pSet->GetFieldValue(short(8), s);
	filename = s;
	img.Load(s);

	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
}


void CCompExpView::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(true);
	OnPaint();
}


void CCompExpView::OnRecordPrev()
{
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(false);
	GetDlgItem(IDC_PICTURE)->ShowWindow(true);
	OnPaint();
}


void CCompExpView::OnEnLarge()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MyDlg1 dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{

	}
}


void CCompExpView::OnSearch()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_pSet->m_strFilter = _T("");
	m_pSet->m_strSort = _T("");
	m_pSet->Requery();
	UpdateData(false);
}


void CCompExpView::OnRecordset()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MyDlg4 dlg;
	dlg.m_pListSet = m_pSet;
	int r = dlg.DoModal();
	if (r == IDOK)
	{

	}
}


void CCompExpView::OnAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

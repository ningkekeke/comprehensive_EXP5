// MyDlg1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CompExp.h"
#include "MyDlg1.h"
#include "afxdialogex.h"
#include "CompExpDoc.h"
#include "MainFrm.h"
#include "CompExpView.h"


// MyDlg1 �Ի���

IMPLEMENT_DYNAMIC(MyDlg1, CDialogEx)

MyDlg1::MyDlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MyDlg1::~MyDlg1()
{
}

void MyDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDlg1, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// MyDlg1 ��Ϣ�������


void MyDlg1::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	CCompExpView* pView = (CCompExpView*)pFrame->GetActiveView();
	CString s = pView->filename;
	CDC *pDC = GetDlgItem(IDC_LARGE)->GetDC();//�����õ�getdc�����ͷ���
	pDC->SetStretchBltMode(HALFTONE);//ͼ��ʧ��
	CImage img;
	img.Load(s);
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_LARGE)->GetClientRect(&rect);
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
	img.Draw(pDC->m_hDC, sx, sy, w, h);
}


// CompExpView.h : CCompExpView 类的接口
//

#pragma once

class CCompExpSet;

class CCompExpView : public CRecordView
{
protected: // 仅从序列化创建
	CCompExpView();
	DECLARE_DYNCREATE(CCompExpView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_COMPEXP_FORM };
#endif
	CCompExpSet* m_pSet;

// 特性
public:
	CCompExpDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void foo(CImage& img, int& sx, int& sy, int& w, int& h);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CCompExpView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CString filename;
protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long id;
	CString name;
	CString number;
	CString pro;
	CString sex;
	CString birth;
	CString pnumber;
	CString ad;
	afx_msg void OnPaint();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnEnLarge();
	afx_msg void OnSearch();
	afx_msg void OnOrder();
	afx_msg void OnRecovery();
	afx_msg void OnRecordset();
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	afx_msg void OnEdit();
	afx_msg void OnStnClickedPicture();
};

#ifndef _DEBUG  // CompExpView.cpp 中的调试版本
inline CCompExpDoc* CCompExpView::GetDocument() const
   { return reinterpret_cast<CCompExpDoc*>(m_pDocument); }
#endif


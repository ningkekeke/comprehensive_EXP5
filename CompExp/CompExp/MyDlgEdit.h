#pragma once


// MyDlgEdit �Ի���

class MyDlgEdit : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlgEdit)

public:
	MyDlgEdit(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDlgEdit();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif
	CCompExpSet* EditSet;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	long e_id;
	CString e_name;
	CString e_number;
	CString e_pro;
	CString e_sex;
	CString e_birth;
	CString e_pnumber;
	CString e_ad;
	CString e_filename;
	virtual BOOL OnInitDialog();
};

#pragma once


// MyDlgAdd �Ի���

class MyDlgAdd : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlgAdd)

public:
	MyDlgAdd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDlgAdd();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	long a_id;
	CString a_name;
	CString a_number;
	CString a_pro;
	CString a_sex;
	CString a_birth;
	CString a_pnumber;
	CString a_ad;
	CString a_filename;
	
};

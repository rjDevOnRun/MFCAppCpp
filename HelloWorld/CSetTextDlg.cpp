// CSetTextDlg.cpp : implementation file
//

#include "pch.h"
#include "HelloWorld.h"
#include "CSetTextDlg.h"
#include "afxdialogex.h"


// CSetTextDlg dialog

IMPLEMENT_DYNAMIC(CSetTextDlg, CDialog)

CSetTextDlg::CSetTextDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DLG_SET_TEXT, pParent)
	, m_text(_T(""))
{

}

CSetTextDlg::~CSetTextDlg()
{
}

void CSetTextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_text);
}


BEGIN_MESSAGE_MAP(CSetTextDlg, CDialog)
END_MESSAGE_MAP()


// CSetTextDlg message handlers

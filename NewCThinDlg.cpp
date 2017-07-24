// NewCThinDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "NewCThinDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewCThinDlg dialog


CNewCThinDlg::CNewCThinDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewCThinDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewCThinDlg)
	m_strSex = _T("");
	m_strName = _T("");
	m_strFPhone = _T("");
	m_strOPhone = _T("");
	m_strUnit = _T("");
	m_strMPhone = _T("");
	m_strShort = _T("");
	m_strQQ = _T("");
	m_strWeChat = _T("");
	m_strEmail = _T("");
	m_strRemark = _T("");
	//}}AFX_DATA_INIT
}


void CNewCThinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewCThinDlg)
	DDX_CBString(pDX, IDC_COMBO_SEX, m_strSex);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_FPHONE, m_strFPhone);
	DDX_Text(pDX, IDC_EDIT_OPHONE, m_strOPhone);
	DDX_Text(pDX, IDC_EDIT_UNIT1, m_strUnit);
	DDX_Text(pDX, IDC_EDIT_MPHONE, m_strMPhone);
	DDX_Text(pDX, IDC_EDIT_SHORT, m_strShort);
	DDX_Text(pDX, IDC_EDIT_QQ, m_strQQ);
	DDX_Text(pDX, IDC_EDIT_WECHAT, m_strWeChat);
	DDX_Text(pDX, IDC_EDIT_EMAIL, m_strEmail);
	DDX_Text(pDX, IDC_EDIT_REMARK, m_strRemark);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewCThinDlg, CDialog)
	//{{AFX_MSG_MAP(CNewCThinDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewCThinDlg message handlers

void CNewCThinDlg::OnOK() 
{
	// TODO: Add extra validation here
	//添加代码
	UpdateData();
	if(m_strName == "")
	{
		MessageBox("请输入姓名！");
		return;
	}
	//添加代码结束
	CDialog::OnOK();
}

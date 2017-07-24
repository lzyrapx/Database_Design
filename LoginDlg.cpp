// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "LoginDlg.h"
//添加代码
#include <afxdb.h>      //添加ODBC数据库类的定义文件afxdb.h
#include "User.h"
//添加代码结束
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog


CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg)
	m_strUser = _T("");
	m_strPassword = _T("");
	//}}AFX_DATA_INIT
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
	DDX_Control(pDX, IDC_EDIT_PASSWORD, m_ctrPassword);
	DDX_Control(pDX, IDC_COMBO_USER, m_ctrUser);
	DDX_CBString(pDX, IDC_COMBO_USER, m_strUser);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_strPassword);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

void CLoginDlg::OnOK() 
{
	// TODO: Add extra validation here
	//添加代码
	CUser recordset;
	CString strSQL;
	CDatabaseApp*ptheApp = (CDatabaseApp * ) AfxGetApp();
	UpdateData(TRUE);
	//若用户名为空,则要求用户输入用户名
	if(m_strUser.IsEmpty())
	{
		AfxMessageBox("用户名不能为空,请输入用户名!");
		m_ctrUser.SetFocus();
		return;}
	if(m_strPassword.IsEmpty())
	{
		AfxMessageBox("密码不能为空,请输入正确的密码!");
		m_ctrPassword.SetFocus();
		return;
	}
	//检测用户输入密码的正确性
	strSQL.Format("select*from user where customer = '%s' AND \password = '%s'",m_strUser,m_strPassword);
	if(! recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return;
	}
	if(recordset.GetRecordCount()==0)
	{
		//密码错误，则重新输入；便于简化陈述，不限定输入次数，直到用户输入正确为止
		recordset.Close();
		MessageBox("你的密码错误,请重新输入!");
		m_strPassword = "";
		m_ctrPassword.SetFocus();
		UpdateData(FALSE);
	}
	else
	{
		//指定用户访问权限
		ptheApp -> m_bHasSuperAuthority = recordset.m_privilege;
		recordset.Close();
		CDialog::OnOK();
	}
	//添加代码结束
}

BOOL CLoginDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//添加代码
	CUser recordset;
	CString strSQL;
	UpdateData(TRUE);
	strSQL = "select*from user";
	if(! recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return FALSE;
	}
	while(! recordset.IsEOF())
	{
		m_ctrUser.AddString(recordset.m_customer);
		recordset.MoveNext();
	}
	recordset.Close();
	//添加代码结束
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

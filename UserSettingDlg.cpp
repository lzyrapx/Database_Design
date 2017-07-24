// UserSettingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "UserSettingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserSettingDlg dialog


CUserSettingDlg::CUserSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserSettingDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserSettingDlg)
	m_bAuthority = FALSE;
	m_strUserName = _T("");
	m_strPassword = _T("");
	m_strConfirm = _T("");
	//}}AFX_DATA_INIT
}


void CUserSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserSettingDlg)
	DDX_Control(pDX, IDC_LIST_USERLIST, m_ctrUserList);
	DDX_Control(pDX, IDC_EDIT_PASSWORD, m_ctrPassword);
	DDX_Control(pDX, IDC_EDIT_USERNAME, m_ctrUserName);
	DDX_Control(pDX, IDOK, m_bntOK);
	DDX_Control(pDX, IDC_BUTTON_ADD, m_bntAdd);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_bntDelete);
	DDX_Control(pDX, IDC_BUTTON_CANCEL, m_bntCancel);
	DDX_Check(pDX, IDC_CHECK_AUTHORITY, m_bAuthority);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_strUserName);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_strPassword);
	DDX_Text(pDX, IDC_EDIT_CONFIRM, m_strConfirm);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserSettingDlg, CDialog)
	//{{AFX_MSG_MAP(CUserSettingDlg)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_NOTIFY(NM_CLICK, IDC_LIST_USERLIST, OnClickListUserlist)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserSettingDlg message handlers

void CUserSettingDlg::OnButtonCancel() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	m_strUserName="";
	m_strPassword="";
	m_strConfirm="";
	m_bAuthority=FALSE;
	m_ctrUserName.EnableWindow(FALSE);
	UpdateData(FALSE);
	//添加代码结束	
}

void CUserSettingDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	UpdateData(TRUE);
	//判断输入的用户是否存在
	if(m_strUserName=="")
	{
		MessageBox("亲，请您选择一个应经存在的用户！");
		return;
	}
	CString strSQL;
	strSQL.Format("select * from user where customer='%s'",m_strUserName);
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败！","数据库错误",MB_OK);
		return;
	}
	//删除该用户
	m_recordset.Delete();
	m_recordset.Close();
	//刷新用户列表
	DataUpdate();
	m_strUserName="";
	m_strPassword="";
	m_strConfirm="";
	m_bAuthority=FALSE;
	UpdateData(FALSE);
	//添加代码结束	
}

void CUserSettingDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	//清空当前用户信息，使界面呈现初始化状态
	m_strUserName="";
	m_strPassword="";
	m_strConfirm="";
	m_bAuthority=FALSE;
	//用户名编辑框改变禁止状态，获得输入焦点，变为可输入状态
	m_ctrUserName.EnableWindow(TRUE);
	m_ctrUserName.SetFocus();
	UpdateData(FALSE);
	//添加代码结束	
}

void CUserSettingDlg::OnOK() 
{
	// TODO: Add extra validation here
	//添加代码
	UpdateData();
	if(m_ctrUserName.IsWindowEnabled())
	{
		//检查输入用户名是否为空
		if(m_strUserName=="")
		{
			MessageBox("请填写用户名！");
			m_ctrUserName.SetFocus();
			return;
		}
	}
	else
	{
		if(m_strUserName=="")
		{
			MessageBox("请选择一个用户！");
			return;
		}
	}
	//密码不能为空
	if(m_strPassword=="")
	{
		MessageBox("密码不能为空，请输入密码！");
		m_ctrPassword.SetFocus();
		return;
	}
	//密码的验证
	if(m_strPassword!=m_strConfirm)
	{
		MessageBox("两次输入的密码不一致，请重新输入密码！");
		m_ctrPassword.SetFocus();
		m_strPassword="";
		m_strConfirm="";
		UpdateData(FALSE);
		return;
	}
	//打开后台数据库表user的记录集
	CString strSQL;
	strSQL.Format("select* from user where customer='%s'",m_strUserName);
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败！","数据库错误",MB_OK);
		return;
	}
	if(m_ctrUserName.IsWindowEnabled())
	{
		//增加新的用户
		//判断输入的用户是否应经存在
		if(m_recordset.GetRecordCount()!=0)
		{
			m_recordset.Close();
			MessageBox("该用户已经存在!");
			return;
		}
		m_recordset.AddNew();
		m_recordset.m_customer=m_strUserName;
		m_recordset.m_password=m_strPassword;
		m_recordset.m_privilege=m_bAuthority;
		m_recordset.Update();
		MessageBox("用户添加成功！请记住用户名和密码！");
		m_recordset.Close();
	}
	else
	{
		//修改用户信息
		//判断要修改的用户是否在后台数据库中不存在
		if(m_recordset.GetRecordCount()==0)
		{
			m_recordset.Close();
			MessageBox("该用户不存在！请更新数据库");
			return;
		}
		m_recordset.Edit();
		m_recordset.m_customer=m_strUserName;
		m_recordset.m_password =m_strPassword;
		m_recordset.m_privilege =m_bAuthority;
		m_recordset.Update();
		MessageBox("用户修改成功！请记住用户名和密码！");
		m_recordset.Close();
	}
	m_ctrUserName.EnableWindow(FALSE);
	//调用类的私有函数，更新用户列表
	DataUpdate();
	//添加代码结束	
	//CDialog::OnOK();
}

void CUserSettingDlg::OnClickListUserlist(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	//添加代码
	CString strSQL;
	UpdateData(TRUE);
	//从数据库PostDB中表user获取选择用户名的资料
	int i=m_ctrUserList.GetSelectionMark();
	m_strUserName=m_ctrUserList.GetItemText(i,0);
	strSQL.Format("select * from user where customer='%s'",m_strUserName);
	if(! m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败！","数据库错误",MB_OK);
		return;
	}
	//在用户列表控件的列表中显示选取的用户信息
	m_strPassword=m_recordset.m_password;
	m_strConfirm=m_strPassword;
	m_bAuthority=m_recordset.m_privilege;
	m_recordset.Close();
	UpdateData(FALSE);
	*pResult=0;
	//添加代码结束	
	*pResult = 0;
}

BOOL CUserSettingDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//添加代码
	//初始化列表控件，只生成一个用户名栏
	m_ctrUserList.InsertColumn(0,"用户名");
	m_ctrUserList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_ctrUserList.SetColumnWidth(0,120);
	//在添加用户列表中添加用户名
	DataUpdate();
	//添加代码结束	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CUserSettingDlg::DataUpdate()
{
	//添加代码
	m_ctrUserList.SetFocus();
	//清空用户列表
	m_ctrUserList.DeleteAllItems();
	m_ctrUserList.SetRedraw(FALSE);
	CString strSQL;
	UpdateData(TRUE);
	//打开后台数据库PostDB表user的记录集
	strSQL="select * from user";
	if(! m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败！","数据库错误",MB_OK);
		return;
	}
	//添加表user的用户名到用户列表中
	int i=0;
	while(! m_recordset.IsEOF())
	{
		m_ctrUserList.InsertItem(i++,m_recordset.m_customer);
		m_recordset.MoveNext();
	}
	m_recordset.Close();
	m_ctrUserList.SetRedraw(TRUE);
	//添加代码结束
}

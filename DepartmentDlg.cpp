// DepartmentDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "DepartmentDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDepartmentDlg dialog


CDepartmentDlg::CDepartmentDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDepartmentDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDepartmentDlg)
	m_strCode = _T("");
	m_strLocation = _T("");
	m_strSetting = _T("");
	m_strTeaching = _T("");
	m_strResearching = _T("");
	m_strStudent = _T("");
	m_strContent = _T("");
	m_strName = _T("");
	m_strLeader = _T("");
	//添加代码
	m_iCondition = -1;
	//添加代码结束
	//}}AFX_DATA_INIT
}


void CDepartmentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDepartmentDlg)
	DDX_Control(pDX, IDC_LIST_DEPARTMENT, m_ctrDepartment);
	DDX_Control(pDX, IDC_BUTTON_SAVE, m_bntSave);
	DDX_Text(pDX, IDC_EDIT_CODE, m_strCode);
	DDX_Text(pDX, IDC_EDIT_LOCATION, m_strLocation);
	DDX_Text(pDX, IDC_EDIT_SETTING, m_strSetting);
	DDX_Text(pDX, IDC_EDIT_TEACHING, m_strTeaching);
	DDX_Text(pDX, IDC_EDIT_RESEARCHING, m_strResearching);
	DDX_Text(pDX, IDC_EDIT_STUDENT, m_strStudent);
	DDX_Text(pDX, IDC_EDIT_CONTENT, m_strContent);
	DDX_CBString(pDX, IDC_COMBO_NAME, m_strName);
	DDX_CBString(pDX, IDC_COMBO_LEADER, m_strLeader);
	//添加代码
	DDX_CBIndex(pDX,IDC_COMBO_CONDITION,m_iCondition);
	//添加代码结束
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDepartmentDlg, CDialog)
	//{{AFX_MSG_MAP(CDepartmentDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, OnButtonUpdate)
	ON_NOTIFY(NM_CLICK, IDC_LIST_DEPARTMENT, OnClickListDepartment)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDepartmentDlg message handlers

void CDepartmentDlg::DataUpdate(CString strSQL)
{
    //添加代码
	m_ctrDepartment.SetFocus();
	m_ctrDepartment.DeleteAllItems();
	m_ctrDepartment.SetRedraw(FALSE);
	UpdateData(TRUE);
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
        MessageBox("打开数据库失败!","数据库错误",MB_OK);
        return ;
    }
    int i=0;
    while(!m_recordset.IsEOF())
    {
		m_ctrDepartment.InsertItem(i,m_recordset.m_code);
		m_ctrDepartment.SetItemText(i,1,m_recordset.m_name);
		m_ctrDepartment.SetItemText(i,2,m_recordset.m_leader);
		m_ctrDepartment.SetItemText(i,3,m_recordset.m_location);
		m_ctrDepartment.SetItemText(i,4,m_recordset.m_organization);
		m_ctrDepartment.SetItemText(i,5,m_recordset.m_teach);
		m_ctrDepartment.SetItemText(i,6,m_recordset.m_research);
		m_ctrDepartment.SetItemText(i,7,m_recordset.m_student);
		i++;
		m_recordset.MoveNext();
	}
	m_recordset.Close();
	m_ctrDepartment.SetRedraw(TRUE);
	//添加代码结束
}

void CDepartmentDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	//清空组框“院系详细信息”中的所有数据
	m_strCode = "";
	m_strName = "";
	m_strLeader = "";
	m_strLocation = "";
	m_strSetting = "";
	m_strTeaching = "";
	m_strResearching = "";
	m_strStudent = "";
	//激活保存按钮
	m_bntSave.EnableWindow();
	UpdateData(FALSE);
	//添加代码结束	
}

void CDepartmentDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
    //添加代码
	int i = m_ctrDepartment.GetSelectionMark();
    if(i<0)
    {
        MessageBox("请选择一条记录进行删除！");
        return;
    }
    CString strSQL;
    strSQL.Format("select * from department where code ='%s'", m_ctrDepartment.GetItemText(i,0));
    if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
        MessageBox("打开数据库失败!","数据库错误",MB_OK);
        return ;
    }
	//删除该院系
	m_recordset.Delete();
	m_recordset.Close();
	//更新院系列表
	strSQL = "select * from department";
	DataUpdate(strSQL);
	m_strCode = "";
	m_strName = "";
	m_strLeader = "";
	m_strLocation = "";
	m_strSetting = "";
	m_strTeaching = "";
	m_strResearching = "";
	m_strStudent = "";
	UpdateData(FALSE);
	//添加代码结束
}

void CDepartmentDlg::OnButtonSave() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	UpdateData();
	//检查表department中三个不能为空的属性
	if(m_strName == "")
	{
		MessageBox("请输入院系名称！");
		return;
	}
	if(m_strCode == "")
	{
		MessageBox("请输入院系编码！");
		return;
	}
	if(m_strLeader == "")
	{
		MessageBox("请输入院系领导！");
		return;
	}
	CString tableDepartment;
	//与后台数据表department相连，确保数据保存到指定表中
	tableDepartment = "select * from department";
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,tableDepartment))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return;
	}
	//添加数据集中的数据
	m_recordset.AddNew();
	m_recordset.m_code         = m_strCode;
	m_recordset.m_name         = m_strName;
	m_recordset.m_leader       = m_strLeader;
	m_recordset.m_location     = m_strLocation;
	m_recordset.m_organization = m_strSetting;
	m_recordset.m_teach        = m_strTeaching;
	m_recordset.m_research     = m_strResearching;
	m_recordset.m_student      = m_strStudent;
	//数据集更新
	m_recordset.Update();
	m_recordset.Close();
	//添加代码结束
}

void CDepartmentDlg::OnButtonSearch() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	UpdateData();
	CString strSQL;
	if(0 == m_iCondition)
		strSQL.Format("select * from department where code = '%s'",m_strContent);
	else if(1 == m_iCondition)
		strSQL.Format("select * from department where leader = '%s'",m_strContent);
	else
		strSQL.Format("select * from department where name = '%s'",m_strContent);
	//显示全部信息
	if(m_strContent == "")
		strSQL = "select * from department";
		DataUpdate(strSQL);
	//添加代码结束
}

void CDepartmentDlg::OnButtonUpdate() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	UpdateData();
	int i = m_ctrDepartment.GetSelectionMark();
	if(i < 0)
	{
		MessageBox("请选择一条记录进行修改！");
		return;
	}
	//非空属性添加数据的提示
	if(m_strName == "")
	{
		MessageBox("请输入院系名称！");
		return;
	}
	if(m_strCode == "")
	{
		MessageBox("请输入院系编码！");
		return;
	}
	if(m_strLeader == "")
	{
		MessageBox("请输入院系领导！");
		return;
	}
	CString strSQL;
	//提取要修改的院系编码
    strSQL.Format("select * from department where code ='%s'", m_ctrDepartment.GetItemText(i,0));
    if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
        MessageBox("打开数据库失败!","数据库错误",MB_OK);
        return ;
    }
	m_recordset.Edit();
	m_recordset.m_code         = m_strCode;
	m_recordset.m_name         = m_strName;
	m_recordset.m_leader       = m_strLeader;
	m_recordset.m_location     = m_strLocation;
	m_recordset.m_organization = m_strSetting;
	m_recordset.m_teach        = m_strTeaching;
	m_recordset.m_research     = m_strResearching;
	m_recordset.m_student      = m_strStudent;
	m_recordset.Update();
	m_recordset.Close();
	DataUpdate(strSQL);     //将用户的修改写回后台数据库PostDB.accdb的数据表department中
	//添加代码结束
}

void CDepartmentDlg::OnClickListDepartment(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	//添加代码
	CString strSQL;
	UpdateData(TRUE);
	int i = m_ctrDepartment.GetSelectionMark();
	m_strCode = m_ctrDepartment.GetItemText(i,0);
    strSQL.Format("select * from department where code ='%s'",m_strCode);
    if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
        MessageBox("打开数据库失败!","数据库错误",MB_OK);
        return ;
    }
	m_strCode         = m_recordset.m_code;
	m_strName         = m_recordset.m_name;
	m_strLeader       = m_recordset.m_leader;
	m_strLocation     = m_recordset.m_location;
	m_strSetting      = m_recordset.m_organization;
	m_strTeaching     = m_recordset.m_teach;
	m_strResearching  = m_recordset.m_research;
	m_strStudent      = m_recordset.m_student;
	m_recordset.Close();
	UpdateData(FALSE);
	//添加代码结束
	*pResult = 0;
}

BOOL CDepartmentDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//添加代码
	m_ctrDepartment.InsertColumn(0,"院系编码");
    m_ctrDepartment.SetColumnWidth(0,40);
    m_ctrDepartment.InsertColumn(1,"院系名称");
    m_ctrDepartment.SetColumnWidth(1,40);
	m_ctrDepartment.InsertColumn(2,"院系领导");
    m_ctrDepartment.SetColumnWidth(2,40);
	m_ctrDepartment.InsertColumn(3,"办公地点");
    m_ctrDepartment.SetColumnWidth(3,80);
	m_ctrDepartment.InsertColumn(4,"组织机构");
    m_ctrDepartment.SetColumnWidth(0,80);
	m_ctrDepartment.InsertColumn(5,"教学工作");
    m_ctrDepartment.SetColumnWidth(1,80);
	m_ctrDepartment.InsertColumn(6,"科研工作");
    m_ctrDepartment.SetColumnWidth(2,80);
	m_ctrDepartment.InsertColumn(7,"学生工作");
    m_ctrDepartment.SetColumnWidth(3,80);
	m_ctrDepartment.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	CString strSQL;
	strSQL = "select * from department";
	DataUpdate(strSQL);
	//添加代码结束
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

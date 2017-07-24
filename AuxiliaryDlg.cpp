// AuxiliaryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "AuxiliaryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAuxiliaryDlg dialog


CAuxiliaryDlg::CAuxiliaryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAuxiliaryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAuxiliaryDlg)
	m_strCode = _T("");
	m_strLocation = _T("");
	m_strSetting = _T("");
	m_strDuty = _T("");
	m_strContent = _T("");
	m_strName = _T("");
	m_strLeader = _T("");
	//添加代码
	m_iCondition = -1;
	//添加代码结束
	//}}AFX_DATA_INIT
}


void CAuxiliaryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAuxiliaryDlg)
	DDX_Control(pDX, IDC_LIST_AUXILIARY, m_ctrAuxiliary);
	DDX_Control(pDX, IDC_BUTTON_SAVE, m_bntSave);
	DDX_Text(pDX, IDC_EDIT_CODE, m_strCode);
	DDX_Text(pDX, IDC_EDIT_LOCATION, m_strLocation);
	DDX_Text(pDX, IDC_EDIT_SETTING, m_strSetting);
	DDX_Text(pDX, IDC_EDIT_DUTY, m_strDuty);
	DDX_Text(pDX, IDC_EDIT_CONTENT, m_strContent);
	DDX_CBString(pDX, IDC_COMBO_NAME, m_strName);
	DDX_CBString(pDX, IDC_COMBO_LEADER, m_strLeader);
	//添加代码
	DDX_CBIndex(pDX,IDC_COMBO_CONDITION,m_iCondition);
	//添加代码结束
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAuxiliaryDlg, CDialog)
	//{{AFX_MSG_MAP(CAuxiliaryDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, OnButtonUpdate)
	ON_NOTIFY(NM_CLICK, IDC_LIST_AUXILIARY, OnClickListAuxiliary)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAuxiliaryDlg message handlers

void CAuxiliaryDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	//清空组框“部门详细信息”中的所有数据
	m_strCode = "";
	m_strName = "";
	m_strLeader = "";
	m_strLocation = "";
	m_strSetting = "";
	m_strDuty = "";
	//激活保存按钮
	m_bntSave.EnableWindow();
	UpdateData(FALSE);
	//添加代码结束	
}

void CAuxiliaryDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
    //添加代码
	int i = m_ctrAuxiliary.GetSelectionMark();
    if(i<0)
    {
        MessageBox("请选择一条记录进行删除！");
        return;
    }
    CString strSQL;
    strSQL.Format("select * from auxiliary where code ='%s'", m_ctrAuxiliary.GetItemText(i,0));
    if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
        MessageBox("打开数据库失败!","数据库错误",MB_OK);
        return ;
    }
	//删除该部门
	m_recordset.Delete();
	m_recordset.Close();
	//更新部门列表
	strSQL = "select * from auxiliary";
	DataUpdate(strSQL);
	m_strCode = "";
	m_strName = "";
	m_strLeader = "";
	m_strLocation = "";
	m_strSetting = "";
	m_strDuty = "";
	UpdateData(FALSE);
	//添加代码结束	
}

void CAuxiliaryDlg::OnButtonSave() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	UpdateData();
	//检查表auxiliary中三个不能为空的属性
	if(m_strName == "")
	{
		MessageBox("请输入部门名称！");
		return;
	}
	if(m_strCode == "")
	{
		MessageBox("请输入部门编码！");
		return;
	}
	if(m_strLeader == "")
	{
		MessageBox("请输入部门领导！");
		return;
	}
	CString tableAuxiliary;
	//与后台数据表auxiliary相连，确保数据保存到指定表中
	tableAuxiliary = "select * from auxiliary";
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,tableAuxiliary))
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
	m_recordset.m_duty         = m_strDuty;
	//数据集更新
	m_recordset.Update();
	m_recordset.Close();
	//添加代码结束	
}

void CAuxiliaryDlg::OnButtonSearch() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	UpdateData();
	CString strSQL;
	if(0 == m_iCondition)
		strSQL.Format("select * from auxiliary where code = '%s'",m_strContent);
	else if(1 == m_iCondition)
		strSQL.Format("select * from auxiliary where leader = '%s'",m_strContent);
	else
		strSQL.Format("select * from auxiliary where name = '%s'",m_strContent);
	//显示全部信息
	if(m_strContent == "")
		strSQL = "select * from auxiliary";
		DataUpdate(strSQL);
	//添加代码结束	
}

void CAuxiliaryDlg::OnButtonUpdate() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	UpdateData();
	int i = m_ctrAuxiliary.GetSelectionMark();
	if(i < 0)
	{
		MessageBox("请选择一条记录进行修改！");
		return;
	}
	//非空属性添加数据的提示
	if(m_strName == "")
	{
		MessageBox("请输入部门名称！");
		return;
	}
	if(m_strCode == "")
	{
		MessageBox("请输入部门编码！");
		return;
	}
	if(m_strLeader == "")
	{
		MessageBox("请输入部门领导！");
		return;
	}
	CString strSQL;
	//提取要修改的部门编码
    strSQL.Format("select * from auxiliary where code ='%s'", m_ctrAuxiliary.GetItemText(i,0));
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
	m_recordset.m_duty         = m_strDuty;
	m_recordset.Update();
	m_recordset.Close();
	DataUpdate(strSQL);     //将用户的修改写回后台数据库PostDB.accdb的数据表auxiliary中
	//添加代码结束	
}

void CAuxiliaryDlg::OnClickListAuxiliary(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	//添加代码
	CString strSQL;
	UpdateData(TRUE);
	int i = m_ctrAuxiliary.GetSelectionMark();
	m_strCode = m_ctrAuxiliary.GetItemText(i,0);
    strSQL.Format("select * from auxiliary where code ='%s'",m_strCode);
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
	m_strDuty         = m_recordset.m_duty;
	m_recordset.Close();
	UpdateData(FALSE);
	//添加代码结束	
	*pResult = 0;
}

BOOL CAuxiliaryDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	// 添加代码
    m_ctrAuxiliary.InsertColumn(0,"部门编码");
    m_ctrAuxiliary.SetColumnWidth(0,40);
    m_ctrAuxiliary.InsertColumn(1,"部门名称");
    m_ctrAuxiliary.SetColumnWidth(1,40);
    m_ctrAuxiliary.InsertColumn(2,"部门领导");
    m_ctrAuxiliary.SetColumnWidth(2,40);
    m_ctrAuxiliary.InsertColumn(3,"办公地点");
    m_ctrAuxiliary.SetColumnWidth(3,80);
    m_ctrAuxiliary.InsertColumn(4,"组织机构");
    m_ctrAuxiliary.SetColumnWidth(0,80);
    m_ctrAuxiliary.InsertColumn(5,"岗位职责");
    m_ctrAuxiliary.SetColumnWidth(1,80);
    m_ctrAuxiliary.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
    CString strSQL;
    strSQL="select * from auxiliary";
    DataUpdate(strSQL);
    // 添加代码结束	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAuxiliaryDlg::DataUpdate(CString strSQL)
{
    //添加代码
	m_ctrAuxiliary.SetFocus();
	m_ctrAuxiliary.DeleteAllItems();
	m_ctrAuxiliary.SetRedraw(FALSE);
	UpdateData(TRUE);
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
        MessageBox("打开数据库失败!","数据库错误",MB_OK);
        return ;
    }
    int i=0;
    while(!m_recordset.IsEOF())
    {
		m_ctrAuxiliary.InsertItem(i,m_recordset.m_code);
		m_ctrAuxiliary.SetItemText(i,1,m_recordset.m_name);
		m_ctrAuxiliary.SetItemText(i,2,m_recordset.m_leader);
		m_ctrAuxiliary.SetItemText(i,3,m_recordset.m_location);
		m_ctrAuxiliary.SetItemText(i,4,m_recordset.m_organization);
		m_ctrAuxiliary.SetItemText(i,5,m_recordset.m_duty);
		i++;
		m_recordset.MoveNext();
	}
	m_recordset.Close();
	m_ctrAuxiliary.SetRedraw(TRUE);
	//添加代码结束
}

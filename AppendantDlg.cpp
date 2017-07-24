// AppendantDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "AppendantDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAppendantDlg dialog


CAppendantDlg::CAppendantDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAppendantDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAppendantDlg)
	m_strCode = _T("");
	m_strLocation = _T("");
	m_strSetting = _T("");
	m_strRegulation = _T("");
	m_strContent = _T("");
	m_strName = _T("");
	m_strLeader = _T("");
	//添加代码
	m_iCondition = -1;
	//添加代码结束
	//}}AFX_DATA_INIT
}


void CAppendantDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAppendantDlg)
	DDX_Control(pDX, IDC_LIST_APPENDANT, m_ctrAppendant);
	DDX_Control(pDX, IDC_BUTTON_SAVE, m_bntSave);
	DDX_Text(pDX, IDC_EDIT_CODE, m_strCode);
	DDX_Text(pDX, IDC_EDIT_LOCATION, m_strLocation);
	DDX_Text(pDX, IDC_EDIT_SETTING, m_strSetting);
	DDX_Text(pDX, IDC_EDIT_REGULATION, m_strRegulation);
	DDX_Text(pDX, IDC_EDIT_CONTENT, m_strContent);
	DDX_CBString(pDX, IDC_COMBO_NAME, m_strName);
	DDX_CBString(pDX, IDC_COMBO_LEADER, m_strLeader);
	//添加代码
	DDX_CBIndex(pDX,IDC_COMBO_CONDITION,m_iCondition);
	//添加代码结束
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAppendantDlg, CDialog)
	//{{AFX_MSG_MAP(CAppendantDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, OnButtonUpdate)
	ON_NOTIFY(NM_CLICK, IDC_LIST_APPENDANT, OnClickListAppendant)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAppendantDlg message handlers

void CAppendantDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	//清空组框“单位详细信息”中的所有数据
	m_strCode = "";
	m_strName = "";
	m_strLeader = "";
	m_strLocation = "";
	m_strSetting = "";
    m_strRegulation = "";
	//激活保存按钮
	m_bntSave.EnableWindow();
	UpdateData(FALSE);
	//添加代码结束	
}

void CAppendantDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
    //添加代码
	int i = m_ctrAppendant.GetSelectionMark();
    if(i<0)
    {
        MessageBox("请选择一条记录进行删除！");
        return;
    }
    CString strSQL;
    strSQL.Format("select * from appendant where code ='%s'", m_ctrAppendant.GetItemText(i,0));
    if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
        MessageBox("打开数据库失败!","数据库错误",MB_OK);
        return ;
    }
	//删除该单位
	m_recordset.Delete();
	m_recordset.Close();
	//更新单位列表
	strSQL = "select * from appendant";
	DataUpdate(strSQL);
	m_strCode = "";
	m_strName = "";
	m_strLeader = "";
	m_strLocation = "";
	m_strSetting = "";
	m_strRegulation = "";
	UpdateData(FALSE);
	//添加代码结束	
}

void CAppendantDlg::OnButtonSave() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	UpdateData();
	//检查表appendant中三个不能为空的属性
	if(m_strName == "")
	{
		MessageBox("请输入单位名称！");
		return;
	}
	if(m_strCode == "")
	{
		MessageBox("请输入单位编码！");
		return;
	}
	if(m_strLeader == "")
	{
		MessageBox("请输入单位领导！");
		return;
	}
	CString tableAppendant;
	//与后台数据表appendant相连，确保数据保存到指定表中
	tableAppendant = "select * from appendant";
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,tableAppendant))
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
	m_recordset.m_regulation   = m_strRegulation;
	//数据集更新
	m_recordset.Update();
	m_recordset.Close();
	//添加代码结束	
}

void CAppendantDlg::OnButtonSearch() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	UpdateData();
	CString strSQL;
	if(0 == m_iCondition)
		strSQL.Format("select * from appendant where code = '%s'",m_strContent);
	else if(1 == m_iCondition)
		strSQL.Format("select * from appendant where leader = '%s'",m_strContent);
	else
		strSQL.Format("select * from appendant where name = '%s'",m_strContent);
	//显示全部信息
	if(m_strContent == "")
		strSQL = "select * from appendant";
		DataUpdate(strSQL);
	//添加代码结束	
}

void CAppendantDlg::OnButtonUpdate() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	UpdateData();
	int i = m_ctrAppendant.GetSelectionMark();
	if(i < 0)
	{
		MessageBox("请选择一条记录进行修改！");
		return;
	}
	//非空属性添加数据的提示
	if(m_strName == "")
	{
		MessageBox("请输入单位名称！");
		return;
	}
	if(m_strCode == "")
	{
		MessageBox("请输入单位编码！");
		return;
	}
	if(m_strLeader == "")
	{
		MessageBox("请输入单位领导！");
		return;
	}
	CString strSQL;
	//提取要修改的单位编码
    strSQL.Format("select * from appendant where code ='%s'", m_ctrAppendant.GetItemText(i,0));
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
	m_recordset.m_regulation   = m_strRegulation;
	m_recordset.Update();
	m_recordset.Close();
	DataUpdate(strSQL);     //将用户的修改写回后台数据库PostDB.accdb的数据表appendant中
	//添加代码结束	
}

void CAppendantDlg::OnClickListAppendant(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	//添加代码
	CString strSQL;
	UpdateData(TRUE);
	int i = m_ctrAppendant.GetSelectionMark();
	m_strCode = m_ctrAppendant.GetItemText(i,0);
    strSQL.Format("select * from appendant where code ='%s'",m_strCode);
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
	m_strRegulation   = m_recordset.m_regulation;
	m_recordset.Close();
	UpdateData(FALSE);
	//添加代码结束	
	*pResult = 0;
}

BOOL CAppendantDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	// 添加代码
    m_ctrAppendant.InsertColumn(0,"单位编码");
    m_ctrAppendant.SetColumnWidth(0,40);
    m_ctrAppendant.InsertColumn(1,"单位名称");
    m_ctrAppendant.SetColumnWidth(1,40);
    m_ctrAppendant.InsertColumn(2,"单位领导");
    m_ctrAppendant.SetColumnWidth(2,40);
    m_ctrAppendant.InsertColumn(3,"办公地点");
    m_ctrAppendant.SetColumnWidth(3,80);
    m_ctrAppendant.InsertColumn(4,"组织机构");
    m_ctrAppendant.SetColumnWidth(0,80);
    m_ctrAppendant.InsertColumn(5,"规章制度");
    m_ctrAppendant.SetColumnWidth(1,80);
    m_ctrAppendant.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
    CString strSQL;
    strSQL="select * from appendant";
    DataUpdate(strSQL);
    // 添加代码结束	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAppendantDlg::DataUpdate(CString strSQL)
{
    //添加代码
	m_ctrAppendant.SetFocus();
	m_ctrAppendant.DeleteAllItems();
	m_ctrAppendant.SetRedraw(FALSE);
	UpdateData(TRUE);
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
        MessageBox("打开数据库失败!","数据库错误",MB_OK);
        return ;
    }
    int i=0;
    while(!m_recordset.IsEOF())
    {
		m_ctrAppendant.InsertItem(i,m_recordset.m_code);
		m_ctrAppendant.SetItemText(i,1,m_recordset.m_name);
		m_ctrAppendant.SetItemText(i,2,m_recordset.m_leader);
		m_ctrAppendant.SetItemText(i,3,m_recordset.m_location);
		m_ctrAppendant.SetItemText(i,4,m_recordset.m_organization);
		m_ctrAppendant.SetItemText(i,5,m_recordset.m_regulation);
		i++;
		m_recordset.MoveNext();
	}
	m_recordset.Close();
	m_ctrAppendant.SetRedraw(TRUE);
	//添加代码结束
}

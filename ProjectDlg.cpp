// ProjectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "ProjectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProjectDlg dialog


CProjectDlg::CProjectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProjectDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProjectDlg)
	m_tmRelease = 0;
	m_tmBegin = 0;
	m_tmEnd = 0;
	m_strType = _T("");
	m_strSort = _T("");
	m_strLevel = _T("");
	m_strRate = _T("");
	m_strState = _T("");
	m_strLimit = _T("");
	m_strTitle = _T("");
	m_strHost = _T("");
	m_strRank = _T("");
	m_strFirst = _T("");
	m_strUnit = _T("");
	m_strCost = _T("");
    // 添加代码
    m_strCode = "";
    // 添加代码结束
	//}}AFX_DATA_INIT
}


void CProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProjectDlg)
	DDX_Control(pDX, IDC_LIST_PROJECT, m_ctrProject);
	DDX_Control(pDX, IDC_BUTTON_SAVE, m_bntSave);
	DDX_Control(pDX, IDC_BUTTON_UPDATE, m_bntUpdate);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_bntDelete);
	DDX_Control(pDX, IDC_BUTTON_ADD, m_bntAdd);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_RELEASE, m_tmRelease);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_BEGIN, m_tmBegin);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_END, m_tmEnd);
	DDX_CBString(pDX, IDC_COMBO_TYPE, m_strType);
	DDX_CBString(pDX, IDC_COMBO_SORT, m_strSort);
	DDX_CBString(pDX, IDC_COMBO_LEVEL, m_strLevel);
	DDX_CBString(pDX, IDC_COMBO_RATE, m_strRate);
	DDX_CBString(pDX, IDC_COMBO_STATE, m_strState);
	DDX_CBString(pDX, IDC_COMBO_LIMIT, m_strLimit);
	DDX_Text(pDX, IDC_EDIT_TITLE, m_strTitle);
	DDX_Text(pDX, IDC_EDIT_HOST, m_strHost);
	DDX_Text(pDX, IDC_EDIT_RANK, m_strRank);
	DDX_Text(pDX, IDC_EDIT_FIRST, m_strFirst);
	DDX_Text(pDX, IDC_EDIT_UNIT2, m_strUnit);
	DDX_Text(pDX, IDC_EDIT_COST, m_strCost);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProjectDlg, CDialog)
	//{{AFX_MSG_MAP(CProjectDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, OnButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_NOTIFY(NM_CLICK, IDC_LIST_PROJECT, OnClickListProject)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProjectDlg message handlers

void CProjectDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
        m_strCost    = "";
        m_strFirst   = "";
        m_strLevel   = "";
        m_strHost    = "";
        m_strLimit   = "";
        m_tmBegin  = CTime::GetCurrentTime();
        m_tmEnd  = CTime::GetCurrentTime();
        m_tmRelease  = CTime::GetCurrentTime();
        m_strRank    =   "";
        m_strRate    =   "";
        m_strTitle   =   "";
        m_strType    =   "";
        m_strSort    =   "";
        m_strState   =   "";
        m_strUnit    =   "";
        m_bntSave.EnableWindow();
        m_bntAdd.EnableWindow(FALSE);
        m_bntDelete.EnableWindow(FALSE);
        m_bntUpdate.EnableWindow(FALSE);
        UpdateData(FALSE);
        // 添加代码结束
}

void CProjectDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
        int i = m_ctrProject.GetSelectionMark();
        if(i<0)
        {
            MessageBox("请选择一条记录进行删除！");
            return;
        }
        CString strSQL;
        strSQL.Format("select * from project where number = %s ",m_ctrProject.GetItemText(i,0));
        if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
        {
             MessageBox("打开数据库失败!","数据库错误",MB_OK);
             return ;
        }
        //删除该记录
        m_recordset.Delete();
        m_recordset.Close();
        //更新用户界面
        DataUpdate(m_strCode);
        m_strCost    = "";
        m_strFirst   = "";
        m_strHost    = "";
        m_strLevel   = "";
        m_strLimit   = "";
        m_strRank    = "";
        m_strRate    = "";
        m_strTitle   = "";
        m_strType    = "";
        m_strSort    = "";
        m_strState   = "";
        m_strUnit    = "";
        m_tmRelease  = CTime::GetCurrentTime();
        m_tmBegin    = CTime::GetCurrentTime();
        m_tmEnd      = CTime::GetCurrentTime();
        UpdateData(FALSE);
        // 添加代码结束
}

void CProjectDlg::OnButtonUpdate() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
        UpdateData();
        int i = m_ctrProject.GetSelectionMark();
        if(i<0)
        {
            MessageBox("请选择一条记录进行修改！");
            return;
        }
        CString strSQL;
        strSQL.Format("select * from project where number = %s",m_ctrProject.GetItemText(i,0));
        if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
        {
             MessageBox("打开数据库失败!","数据库错误",MB_OK);
             return ;
        }
        m_recordset.Edit();
        m_recordset.m_begin    = m_tmBegin;
        m_recordset.m_end      = m_tmEnd;
        m_recordset.m_release  = m_tmRelease;
        m_recordset.m_cost     = m_strCost;
        m_recordset.m_first    = m_strFirst;
        m_recordset.m_host     = m_strHost;
        m_recordset.m_level    = m_strLevel;
        m_recordset.m_limit    = m_strLimit;
        m_recordset.m_rate     = m_strRate;
        m_recordset.m_rank     = m_strRank;
        m_recordset.m_title    = m_strTitle;
        m_recordset.m_type     = m_strType;
        m_recordset.m_sort     = m_strSort;
        m_recordset.m_state    = m_strState;
        m_recordset.m_unit     = m_strUnit;
        m_recordset.Update();
        m_recordset.Close();
        DataUpdate(m_strCode);
        // 添加代码结束
}

void CProjectDlg::OnButtonSave() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
        UpdateData();
        if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE))
        {
             MessageBox("打开数据库失败!","数据库错误",MB_OK);
             return ;
        }
        m_recordset.AddNew();
        m_recordset.m_cost    = m_strCost;
        m_recordset.m_first   = m_strFirst;
        m_recordset.m_begin   = m_tmBegin;
        m_recordset.m_end     = m_tmEnd;
        m_recordset.m_release = m_tmRelease;
        m_recordset.m_level   = m_strLevel;
        m_recordset.m_host    = m_strHost;
        m_recordset.m_limit   = m_strLimit;
        m_recordset.m_rate    = m_strRate;
        m_recordset.m_rank    = m_strRank;
        m_recordset.m_title   = m_strTitle;
        m_recordset.m_type    = m_strType;
        m_recordset.m_sort    = m_strSort;
        m_recordset.m_state   = m_strState;
        m_recordset.m_unit    = m_strUnit;
        // 教工编号code也要保存进后台数据库PostDB.accdb中
        m_recordset.m_code  =   m_strCode  ;
        m_recordset.Update();
        m_recordset.Close();
        DataUpdate(m_strCode);
        // 添加代码结束
}

void CProjectDlg::OnClickListProject(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	// 添加代码
        CString strSQL;
        UpdateData(TRUE);
        int i = m_ctrProject.GetSelectionMark();
        strSQL.Format("select * from project where number =%s",m_ctrProject.GetItemText(i,0));
        if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
        {        
             MessageBox("打开数据库失败!","数据库错误",MB_OK);
             return ;
        }
        m_strCost    = m_recordset.m_cost;
        m_strFirst   = m_recordset.m_first;
        m_tmRelease  = m_recordset.m_release;
        m_tmBegin       = m_recordset.m_begin;
        m_tmEnd         = m_recordset.m_end;
        m_strLevel  = m_recordset.m_level;
        m_strHost    = m_recordset.m_host;
        m_strLimit      = m_recordset.m_limit;
        m_strRate    = m_recordset.m_rate;
        m_strRank       = m_recordset.m_rank;
        m_strTitle      = m_recordset.m_title;
        m_strType       = m_recordset.m_type;
        m_strSort       = m_recordset.m_sort;
        m_strState      = m_recordset.m_state;
        m_strUnit       = m_recordset.m_unit;
        m_recordset.Close();
        UpdateData(FALSE);
        m_bntSave.EnableWindow(FALSE);
        m_bntAdd.EnableWindow();
        m_bntDelete.EnableWindow();
        m_bntUpdate.EnableWindow();
        // 添加代码结束
	*pResult = 0;
}

BOOL CProjectDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	// 添加代码
        // 初始化项目成果对话框中的列表控件表头
        m_ctrProject.InsertColumn(0,"序号");
        m_ctrProject.SetColumnWidth(0,60);
        m_ctrProject.InsertColumn(1,"题目");
        m_ctrProject.SetColumnWidth(1,80);
        m_ctrProject.InsertColumn(2,"类型");
        m_ctrProject.SetColumnWidth(2,80);
        m_ctrProject.InsertColumn(3,"类别");
        m_ctrProject.SetColumnWidth(3,80);
        m_ctrProject.InsertColumn(4,"级别");
        m_ctrProject.SetColumnWidth(4,80);
        m_ctrProject.InsertColumn(5,"资助类别");
        m_ctrProject.SetColumnWidth(5,80);
        m_ctrProject.InsertColumn(6,"状态");
        m_ctrProject.SetColumnWidth(6,80);
        m_ctrProject.InsertColumn(7,"主持人");
        m_ctrProject.SetColumnWidth(7,80);
        m_ctrProject.InsertColumn(8,"排名");
        m_ctrProject.SetColumnWidth(8,80);
        m_ctrProject.InsertColumn(9,"第一完成单位");
        m_ctrProject.SetColumnWidth(9,80);
        m_ctrProject.InsertColumn(10,"下达时间");
        m_ctrProject.SetColumnWidth(10,80);
        m_ctrProject.InsertColumn(11,"下达单位");
        m_ctrProject.SetColumnWidth(11,80);
        m_ctrProject.InsertColumn(12,"下达经费");
        m_ctrProject.SetColumnWidth(12,80);
        m_ctrProject.InsertColumn(13,"研究期限");
        m_ctrProject.SetColumnWidth(13,80);
        m_ctrProject.InsertColumn(14,"开始时间");
        m_ctrProject.SetColumnWidth(14,80);
        m_ctrProject.InsertColumn(15,"结束时间");
        m_ctrProject.SetColumnWidth(15,80);
        m_ctrProject.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
        m_bntSave.EnableWindow(FALSE);
        m_bntAdd.EnableWindow(FALSE);
        m_bntDelete.EnableWindow(FALSE);
        m_bntUpdate.EnableWindow(FALSE);
        // 添加代码结束
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CProjectDlg::DataUpdate(CString strCode)
{
    // 添加代码
        m_ctrProject.DeleteAllItems();
        m_ctrProject.SetRedraw(FALSE);
        UpdateData(TRUE);
        CString strSQL;
        m_strCode.Format("%s",strCode);
        // SQL语句条件表达式中的code是教工的工号
        strSQL.Format( "select * from project where code = '%s'",strCode);
        if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
        {
             MessageBox("打开数据库失败!","数据库错误",MB_OK);
             return ;
        }
        int i=0;
        CString strRTime; // 对应经费下达时间
        CString strBTime; // 对应开始时间
        CString strETime; // 对应结束时间
        char buffer[20];
        while(!m_recordset.IsEOF())
        {
        // 对应列表框上的序号
        _ltoa(m_recordset.m_numder,buffer,10);
        m_ctrProject.InsertItem(i,buffer);
        // 对应列表框上的题目
        m_ctrProject.SetItemText(i,1,m_recordset.m_title);
        // 对应列表框上的类型
        m_ctrProject.SetItemText(i,2,m_recordset.m_type);
        // 对应列表框上的类别
        m_ctrProject.SetItemText(i,3,m_recordset.m_sort);
        // 对应列表框上的级别
        m_ctrProject.SetItemText(i,4,m_recordset.m_level);
        // 对应列表框上的资助类别
        m_ctrProject.SetItemText(i,5,m_recordset.m_rate);
        // 对应列表框上的状态
        m_ctrProject.SetItemText(i,6,m_recordset.m_state);
        // 对应列表框上的主持人
        m_ctrProject.SetItemText(i,7,m_recordset.m_host);
        // 对应列表框上的排名
        m_ctrProject.SetItemText(i,8,m_recordset.m_rank);
        // 对应列表框上的第一完成单位
        m_ctrProject.SetItemText(i,9,m_recordset.m_first);
        // 对应列表框上的下达时间
        strRTime.Format("%d-%d-%d",m_recordset.m_release.GetYear(),m_recordset.m_release.\
			GetMonth(),m_recordset.m_release.GetDay());
        m_ctrProject.SetItemText(i,10,strRTime);
        // 对应列表框上的下达单位
        m_ctrProject.SetItemText(i,11,m_recordset.m_unit);
        // 对应列表框上的下达经费
        m_ctrProject.SetItemText(i,12,m_recordset.m_cost);
        // 对应列表框上的研究期限
        m_ctrProject.SetItemText(i,13,m_recordset.m_limit);
        // 对应列表框上的开始时间
        strBTime.Format("%d-%d-%d",m_recordset.m_begin.GetYear(),m_recordset.m_begin.\
			GetMonth(),m_recordset.m_begin.GetDay());
        m_ctrProject.SetItemText(i,14,strBTime);
        // 对应列表框上的结束时间
        strETime.Format("%d-%d-%d",m_recordset.m_end.GetYear(),m_recordset.m_end.\
			GetMonth(),m_recordset.m_end.GetDay());
        m_ctrProject.SetItemText(i,15,strETime);
        i++;
        m_recordset.MoveNext();
        }
        m_recordset.Close();
        m_ctrProject.SetRedraw(TRUE);
        // 根据是否添加新的项目成果记录设置添加与保存两个按钮的状态
        m_bntSave.EnableWindow(FALSE);
        if(m_strCode=="")
        m_bntAdd.EnableWindow(FALSE);
        else
            m_bntAdd.EnableWindow();
            m_bntDelete.EnableWindow(FALSE);
            m_bntUpdate.EnableWindow(FALSE);
        // 添加代码结束
}

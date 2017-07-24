// RewardRecordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "RewardRecordDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRewardRecordDlg dialog


CRewardRecordDlg::CRewardRecordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRewardRecordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRewardRecordDlg)
	m_tmDate = 0;
	m_strCategory = _T("");
	m_strSort = _T("");
	m_strLevel = _T("");
	m_strTitle = _T("");
	m_strUnit = _T("");
	// 添加代码
    m_strCode = "";
    // 添加代码结束
	//}}AFX_DATA_INIT
}


void CRewardRecordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRewardRecordDlg)
	DDX_Control(pDX, IDC_LIST_REWARDRECORD, m_ctrReward);
	DDX_Control(pDX, IDC_BUTTON_SAVE, m_bntSave);
	DDX_Control(pDX, IDC_BUTTON_UPDATE, m_bntUpdate);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_bntDelete);
	DDX_Control(pDX, IDC_BUTTON_ADD, m_bntAdd);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_DATE, m_tmDate);
	DDX_CBString(pDX, IDC_COMBO_CATEGORY, m_strCategory);
	DDX_CBString(pDX, IDC_COMBO_SORT, m_strSort);
	DDX_CBString(pDX, IDC_COMBO_LEVEL, m_strLevel);
	DDX_Text(pDX, IDC_EDIT_TITLE, m_strTitle);
	DDX_Text(pDX, IDC_EDIT_UNIT, m_strUnit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRewardRecordDlg, CDialog)
	//{{AFX_MSG_MAP(CRewardRecordDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, OnButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_NOTIFY(NM_CLICK, IDC_LIST_REWARDRECORD, OnClickListRewardrecord)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRewardRecordDlg message handlers

void CRewardRecordDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
    m_strCategory = "";
    m_strLevel    = "";
    m_strSort     = "";
    m_strTitle    = "";
    m_strUnit     = "";
    m_tmDate  = CTime::GetCurrentTime();
    m_bntSave.EnableWindow();
    m_bntAdd.EnableWindow(FALSE);
    m_bntDelete.EnableWindow(FALSE);
    m_bntUpdate.EnableWindow(FALSE);
    UpdateData(FALSE);
    // 添加代码结束
}

void CRewardRecordDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
        int i = m_ctrReward.GetSelectionMark();
        if(i<0)
        {
            MessageBox("请选择一条记录进行删除！");
            return;
        }
        CString strSQL;
        strSQL.Format("select * from rewardRecord where number= %s",m_ctrReward.GetItemText(i,0));
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
        m_strCategory = "";
        m_strLevel    = "";
        m_strSort     = "";
        m_strTitle    = "";
        m_strUnit     = "";
        m_tmDate = CTime::GetCurrentTime();
        UpdateData(FALSE);
        // 添加代码结束
}

void CRewardRecordDlg::OnButtonUpdate() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
        UpdateData();
        int i = m_ctrReward.GetSelectionMark();
        if(i<0)
        {
            MessageBox("请选择一条记录进行修改！");
            return;
        }
        CString strSQL;
        strSQL.Format("select * from rewardRecord where number =%s",m_ctrReward.GetItemText(i,0));
        if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
        {
             MessageBox("打开数据库失败!","数据库错误",MB_OK);
        return ;
        }
        m_recordset.Edit();
        m_recordset.m_category = m_strCategory;
        m_recordset.m_date     = m_tmDate;
        m_recordset.m_level    = m_strLevel;
        m_recordset.m_sort     = m_strSort;
        m_recordset.m_title    = m_strTitle;
        m_recordset.m_unit     = m_strUnit;
        m_recordset.Update();
        m_recordset.Close();
        DataUpdate(m_strCode);
        // 添加代码结束
}

void CRewardRecordDlg::OnButtonSave() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
        UpdateData();
        if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE))
        {
        MessageBox("打开数据库失败!","数据库错误",MB_OK);
        return ;
        }
        if(m_strTitle=="")
        {
            MessageBox("请输入奖励名称！");
            return;
        }
        m_recordset.AddNew();
        m_recordset.m_category = m_strCategory;
        m_recordset.m_level    = m_strLevel;
        m_recordset.m_date     = m_tmDate;
        m_recordset.m_sort     = m_strSort;
        m_recordset.m_title    = m_strTitle;
        m_recordset.m_unit     = m_strUnit;
        // 教工编号code也要保存进后台数据库PostDB.accdb中
        m_recordset.m_code     = m_strCode;
        m_recordset.Update();
        m_recordset.Close();
        DataUpdate(m_strCode);
        // 添加代码结束
}

void CRewardRecordDlg::OnClickListRewardrecord(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	// 添加代码
        CString strSQL;
        UpdateData(TRUE);
        int i = m_ctrReward.GetSelectionMark();
        strSQL.Format("select * from rewardRecord where number=%s",m_ctrReward.GetItemText(i,0));
        if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
        {
             MessageBox("打开数据库失败!","数据库错误",MB_OK);
             return ;
        }
        m_strCategory = m_recordset.m_category;
        m_strLevel    = m_recordset.m_level;
        m_tmDate      = m_recordset.m_date;
        m_strSort     = m_recordset.m_sort;
        m_strTitle    = m_recordset.m_title;
        m_strUnit     = m_recordset.m_unit;
        m_recordset.Close();
        UpdateData(FALSE);
        m_bntSave.EnableWindow(FALSE);
        m_bntAdd.EnableWindow();
        m_bntDelete.EnableWindow();
        m_bntUpdate.EnableWindow();
        // 添加代码结束
	*pResult = 0;
}

BOOL CRewardRecordDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// 添加代码
        // 初始化奖励记录对话框中的列表控件表头
        m_ctrReward.InsertColumn(0,"序号");
        m_ctrReward.SetColumnWidth(0,60);
        m_ctrReward.InsertColumn(1,"奖励名称");
        m_ctrReward.SetColumnWidth(1,80);
        m_ctrReward.InsertColumn(2,"奖励等级");
        m_ctrReward.SetColumnWidth(2,80);
        m_ctrReward.InsertColumn(3,"奖励级别");
        m_ctrReward.SetColumnWidth(3,80);
        m_ctrReward.InsertColumn(4,"授奖单位");
        m_ctrReward.SetColumnWidth(4,80);
        m_ctrReward.InsertColumn(5,"奖励门类");
        m_ctrReward.SetColumnWidth(5,80);
        m_ctrReward.InsertColumn(6,"奖励时间");
        m_ctrReward.SetColumnWidth(6,80);
        m_ctrReward.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
        m_bntSave.EnableWindow(FALSE);
        m_bntAdd.EnableWindow(FALSE);
        m_bntDelete.EnableWindow(FALSE);
        m_bntUpdate.EnableWindow(FALSE);
        // 添加代码结束
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CRewardRecordDlg::DataUpdate(CString strCode)
{
    // 添加代码
        m_ctrReward.DeleteAllItems();
        m_ctrReward.SetRedraw(FALSE);
        UpdateData(TRUE);
        CString strSQL;
        m_strCode.Format("%s",strCode);
        // SQL语句条件表达式中的code是教工的工号
        strSQL.Format( "select * from rewardRecord where code = '%s'",strCode);
        if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
        {
             MessageBox("打开数据库失败!","数据库错误",MB_OK);
             return ;
        }
        int i=0;
        CString strTime; // 对应奖励时间
        char buffer[20];
        while(!m_recordset.IsEOF())
        {
        // 对应列表框上的序号
        _ltoa(m_recordset.m_number,buffer,10);
        m_ctrReward.InsertItem(i,buffer);
        // 对应列表框上的奖励名称
        m_ctrReward.SetItemText(i,1,m_recordset.m_title);
        // 对应列表框上的奖励等级
        m_ctrReward.SetItemText(i,2,m_recordset.m_sort);
        // 对应列表框上的奖励级别
        m_ctrReward.SetItemText(i,3,m_recordset.m_level);
        // 对应列表框上的授奖单位
        m_ctrReward.SetItemText(i,4,m_recordset.m_unit);
        // 对应列表框上的奖励门类
        m_ctrReward.SetItemText(i,5,m_recordset.m_category);
        // 对应列表框上的奖励时间
        strTime.Format("%d-%d-%d",m_recordset.m_date.GetYear(),m_recordset.m_date.GetMonth(),\
			m_recordset.m_date.GetDay());
        m_ctrReward.SetItemText(i,6,strTime);
        i++;
        m_recordset.MoveNext();
        }
        m_recordset.Close();
        m_ctrReward.SetRedraw(TRUE);
        // 根据是否添加新的奖励记录设置添加与保存两个按钮的状态
        m_bntSave.EnableWindow(FALSE);
        if(m_strCode=="")
        m_bntAdd.EnableWindow(FALSE);
        else
           m_bntAdd.EnableWindow();
           m_bntDelete.EnableWindow(FALSE);
           m_bntUpdate.EnableWindow(FALSE);
        // 添加代码结束
}

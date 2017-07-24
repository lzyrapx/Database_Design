// DisciplinePunishDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "DisciplinePunishDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDisciplinePunishDlg dialog


CDisciplinePunishDlg::CDisciplinePunishDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDisciplinePunishDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDisciplinePunishDlg)
	m_tmPDate = 0;
	m_tmDDate = 0;
	m_strPeriod = _T("");
	m_strSort = _T("");
	m_strPReason = _T("");
	m_strDReason = _T("");
	m_strUnit = _T("");
	// 添加代码
    m_strCode = "";
    // 添加代码结束
	//}}AFX_DATA_INIT
}


void CDisciplinePunishDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDisciplinePunishDlg)
	DDX_Control(pDX, IDC_LIST_DISCIPLINEPUNISH, m_ctrDisPunish);
	DDX_Control(pDX, IDC_BUTTON_SAVE, m_bntSave);
	DDX_Control(pDX, IDC_BUTTON_UPDATE, m_bntUpdate);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_bntDelete);
	DDX_Control(pDX, IDC_BUTTON_ADD, m_bntAdd);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_PDATE, m_tmPDate);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_DDATE, m_tmDDate);
	DDX_CBString(pDX, IDC_COMBO_PERIOD, m_strPeriod);
	DDX_CBString(pDX, IDC_COMBO_SORT, m_strSort);
	DDX_Text(pDX, IDC_EDIT_PREASON, m_strPReason);
	DDX_Text(pDX, IDC_EDIT_DREASON, m_strDReason);
	DDX_Text(pDX, IDC_EDIT_UNIT1, m_strUnit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDisciplinePunishDlg, CDialog)
	//{{AFX_MSG_MAP(CDisciplinePunishDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, OnButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_NOTIFY(NM_CLICK, IDC_LIST_DISCIPLINEPUNISH, OnClickListDisciplinepunish)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDisciplinePunishDlg message handlers

void CDisciplinePunishDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
        m_strDReason = "";
        m_strPeriod  = "";
        m_strSort    = "";
        m_strPReason = "";
        m_strUnit    = "";
        m_tmDDate  = CTime::GetCurrentTime();
        m_tmPDate  = CTime::GetCurrentTime();
        m_bntSave.EnableWindow();
        m_bntAdd.EnableWindow(FALSE);
        m_bntDelete.EnableWindow(FALSE);
        m_bntUpdate.EnableWindow(FALSE);
        UpdateData(FALSE);
        // 添加代码结束
}

void CDisciplinePunishDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
        int i = m_ctrDisPunish.GetSelectionMark();
        if(i<0)
        {
            MessageBox("请选择一条记录进行删除！");
            return;
        }
        CString strSQL;
        strSQL.Format("select * from disciplinePunish where number = %s",m_ctrDisPunish.GetItemText(i,0));
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
        m_strDReason = "";
        m_strPReason = "";
        m_strSort    = "";
        m_strPeriod  = "";
        m_strUnit    = "";
        m_tmDDate  = CTime::GetCurrentTime();
        m_tmPDate  = CTime::GetCurrentTime();
        UpdateData(FALSE);
        // 添加代码结束
}

void CDisciplinePunishDlg::OnButtonUpdate() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
        UpdateData();
        int i = m_ctrDisPunish.GetSelectionMark();
        if(i<0)
        {
            MessageBox("请选择一条记录进行修改！");
            return;
        }
        CString strSQL;
        strSQL.Format("select * from disciplinePunish where number = %s",m_ctrDisPunish.GetItemText(i,0));
        if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
        {
             MessageBox("打开数据库失败!","数据库错误",MB_OK);
             return ;
        }
        m_recordset.Edit();
        m_recordset.m_ddate   = m_tmDDate;
        m_recordset.m_pdate   = m_tmPDate;
        m_recordset.m_dreason = m_strDReason;
        m_recordset.m_sort    = m_strSort;
        m_recordset.m_period  = m_strPeriod;
        m_recordset.m_unit    = m_strUnit;
        m_recordset.m_preason = m_strPReason;
        m_recordset.Update();
        m_recordset.Close();
        DataUpdate(m_strCode);
        // 添加代码结束
}

void CDisciplinePunishDlg::OnButtonSave() 
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
        m_recordset.m_dreason = m_strDReason;
        m_recordset.m_period  = m_strPeriod;
        m_recordset.m_ddate   = m_tmDDate;
        m_recordset.m_pdate   = m_tmPDate;
        m_recordset.m_sort    = m_strSort;
        m_recordset.m_preason = m_strPReason;
        m_recordset.m_unit    = m_strUnit;
        // 教工编号code也要保存进后台数据库PostDB.accdb中
        m_recordset.m_code    = m_strCode;
        m_recordset.Update();
        m_recordset.Close();
        DataUpdate(m_strCode);
        // 添加代码结束
}

void CDisciplinePunishDlg::OnClickListDisciplinepunish(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	// 添加代码
        CString strSQL;
        UpdateData(TRUE);
        int i = m_ctrDisPunish.GetSelectionMark();
        strSQL.Format("select * from disciplinePunish where number=%s",m_ctrDisPunish.GetItemText(i,0));
        if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
        {
             MessageBox("打开数据库失败!","数据库错误",MB_OK);
             return ;
        }
        m_strDReason = m_recordset.m_dreason;
        m_strPeriod   = m_recordset.m_period;
        m_tmDDate  = m_recordset.m_ddate;
        m_tmPDate  = m_recordset.m_pdate;
        m_strSort    = m_recordset.m_sort;
        m_strPReason = m_recordset.m_preason;
        m_strUnit    = m_recordset.m_unit;
        m_recordset.Close();
        UpdateData(FALSE);
        m_bntSave.EnableWindow(FALSE);
        m_bntAdd.EnableWindow();
        m_bntDelete.EnableWindow();
        m_bntUpdate.EnableWindow();
        // 添加代码结束
	*pResult = 0;
}

BOOL CDisciplinePunishDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	// 添加代码
        // 初始化奖励记录对话框中的列表控件表头
        m_ctrDisPunish.InsertColumn(0,"序号");
        m_ctrDisPunish.SetColumnWidth(0,60);
        m_ctrDisPunish.InsertColumn(1,"违纪种类");
        m_ctrDisPunish.SetColumnWidth(1,80);
        m_ctrDisPunish.InsertColumn(2,"处分期");
        m_ctrDisPunish.SetColumnWidth(2,80);
        m_ctrDisPunish.InsertColumn(3,"违纪原因");
        m_ctrDisPunish.SetColumnWidth(3,80);
        m_ctrDisPunish.InsertColumn(4,"处罚时间");
        m_ctrDisPunish.SetColumnWidth(4,80);
        m_ctrDisPunish.InsertColumn(5,"解除时间");
        m_ctrDisPunish.SetColumnWidth(5,80);
        m_ctrDisPunish.InsertColumn(6,"解除原因");
        m_ctrDisPunish.SetColumnWidth(6,80);
        m_ctrDisPunish.InsertColumn(7,"处罚批准单位");
        m_ctrDisPunish.SetColumnWidth(7,80);
        m_ctrDisPunish.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
        m_bntSave.EnableWindow(FALSE);
        m_bntAdd.EnableWindow(FALSE);
        m_bntDelete.EnableWindow(FALSE);
        m_bntUpdate.EnableWindow(FALSE);
        // 添加代码结束
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDisciplinePunishDlg::DataUpdate(CString strCode)
{
       // 添加代码
        m_ctrDisPunish.DeleteAllItems();
        m_ctrDisPunish.SetRedraw(FALSE);
        UpdateData(TRUE);
        CString strSQL;
        m_strCode.Format("%s",strCode);
        // SQL语句条件表达式中的code是教工的工号
        strSQL.Format( "select * from disciplinePunish where code = '%s'",strCode);
        if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
        {
             MessageBox("打开数据库失败!","数据库错误",MB_OK);
             return ;
        }
        int i=0;
        CString strPTime; // 对应处罚时间
        CString strDTime; // 对应解除时间
        char buffer[20];
        while(!m_recordset.IsEOF())
        {
        // 对应列表框上的序号
        _ltoa(m_recordset.m_number,buffer,10);
        m_ctrDisPunish.InsertItem(i,buffer);
        // 对应列表框上的违纪种类
        m_ctrDisPunish.SetItemText(i,1,m_recordset.m_sort);
        // 对应列表框上的处分期
        m_ctrDisPunish.SetItemText(i,2,m_recordset.m_period);
        // 对应列表框上的违纪原因
        m_ctrDisPunish.SetItemText(i,3,m_recordset.m_preason);
        // 对应列表框上的处罚时间
        strPTime.Format("%d-%d-%d",m_recordset.m_pdate.GetYear(),m_recordset.m_pdate.\
			GetMonth(),m_recordset.m_pdate.GetDay());
        m_ctrDisPunish.SetItemText(i,4,strPTime);
        // 对应列表框上的解除时间
        strDTime.Format("%d-%d-%d",m_recordset.m_ddate.GetYear(),m_recordset.m_ddate.\
			GetMonth(),m_recordset.m_ddate.GetDay());
        m_ctrDisPunish.SetItemText(i,5,strDTime);
        // 对应列表框上的解除原因
        m_ctrDisPunish.SetItemText(i,6,m_recordset.m_dreason);
        // 对应列表框上的处罚批准单位
        m_ctrDisPunish.SetItemText(i,7,m_recordset.m_unit);
        i++;
        m_recordset.MoveNext();
        }
        m_recordset.Close();
        m_ctrDisPunish.SetRedraw(TRUE);
        // 根据是否添加新的违纪处罚记录设置添加与保存两个按钮的状态
        m_bntSave.EnableWindow(FALSE);
        if(m_strCode=="")
        m_bntAdd.EnableWindow(FALSE);
        else
            m_bntAdd.EnableWindow();
            m_bntDelete.EnableWindow(FALSE);
            m_bntUpdate.EnableWindow(FALSE);
        // 添加代码结束
}

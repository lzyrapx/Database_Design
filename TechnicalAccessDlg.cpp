// TechnicalAccessDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "TechnicalAccessDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTechnicalAccessDlg dialog


CTechnicalAccessDlg::CTechnicalAccessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTechnicalAccessDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTechnicalAccessDlg)
	m_tmGDate = 0;
	m_tmBDate = 0;
	m_tmEDate = 0;
	m_strMode = _T("");
	m_strTitle = _T("");
	m_strEmploy = _T("");
	m_strHire = _T("");
	m_strUnit = _T("");
	// 添加代码
    m_strCode = "";
    // 添加代码结束
	//}}AFX_DATA_INIT
}


void CTechnicalAccessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTechnicalAccessDlg)
	DDX_Control(pDX, IDC_LIST_TECHNICALACCESS, m_ctrTAccess);
	DDX_Control(pDX, IDC_BUTTON_SAVE, m_bntSave);
	DDX_Control(pDX, IDC_BUTTON_UPDATE, m_bntUpdate);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_bntDelete);
	DDX_Control(pDX, IDC_BUTTON_ADD, m_bntAdd);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_GDATE, m_tmGDate);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_BDATE, m_tmBDate);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_EDATE, m_tmEDate);
	DDX_CBString(pDX, IDC_COMBO_MODE, m_strMode);
	DDX_Text(pDX, IDC_EDIT_TITLE, m_strTitle);
	DDX_Text(pDX, IDC_EDIT_EMPLOY, m_strEmploy);
	DDX_Text(pDX, IDC_EDIT_HIRE, m_strHire);
	DDX_Text(pDX, IDC_EDIT_UNIT, m_strUnit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTechnicalAccessDlg, CDialog)
	//{{AFX_MSG_MAP(CTechnicalAccessDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, OnButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_NOTIFY(NM_CLICK, IDC_LIST_TECHNICALACCESS, OnClickListTechnicalaccess)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTechnicalAccessDlg message handlers

void CTechnicalAccessDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
m_strEmploy  = "";
m_strHire    = "";
m_strMode    = "";
m_strTitle   = "";
m_strUnit    = "";
m_tmBDate  = CTime::GetCurrentTime();
m_tmEDate  = CTime::GetCurrentTime();
m_tmGDate  = CTime::GetCurrentTime();
m_bntSave.EnableWindow();
m_bntAdd.EnableWindow(FALSE);
m_bntDelete.EnableWindow(FALSE);
m_bntUpdate.EnableWindow(FALSE);
UpdateData(FALSE);
// 添加代码结束
}

void CTechnicalAccessDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
int i = m_ctrTAccess.GetSelectionMark();
if(i<0)
{
MessageBox("请选择一条记录进行删除！");
return;
}
CString strSQL;
strSQL.Format("select * from technicalAssesswhere number = %s",m_ctrTAccess.GetItemText(i,0));
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
m_strEmploy    = "";
m_strHire       = "";
m_strMode     = "";
m_strTitle  = "";
m_strUnit       = "";
m_tmBDate  = CTime::GetCurrentTime();
m_tmEDate       = CTime::GetCurrentTime();
m_tmGDate       = CTime::GetCurrentTime();
UpdateData(FALSE);
// 添加代码结束
}

void CTechnicalAccessDlg::OnButtonUpdate() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
UpdateData();
int i = m_ctrTAccess.GetSelectionMark();
if(i<0)
{
MessageBox("请选择一条记录进行修改！");
return;
}
CString strSQL;
strSQL.Format("select * from technicalAssess where number = %s",m_ctrTAccess.GetItemText(i,0));
if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
{
MessageBox("打开数据库失败!","数据库错误",MB_OK);
return ;
}
m_recordset.Edit();
m_recordset.m_begin         = m_tmBDate;
m_recordset.m_end           = m_tmEDate;
m_recordset.m_assess_Date   = m_tmGDate;
m_recordset.m_employ        = m_strEmploy;
m_recordset.m_hire          = m_strHire;
m_recordset.m_mode          = m_strMode;
m_recordset.m_title         = m_strTitle;
m_recordset.m_unit          = m_strUnit;
m_recordset.Update();
m_recordset.Close();
DataUpdate(m_strCode);
// 添加代码结束
}

void CTechnicalAccessDlg::OnButtonSave() 
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
MessageBox("专业技术资格名称不能为空，请输入专业技术资格名称！");
return;
}
m_recordset.AddNew();
m_recordset.m_employ      = m_strEmploy;
m_recordset.m_hire        = m_strHire;
m_recordset.m_begin       = m_tmBDate;
m_recordset.m_end         = m_tmEDate;
m_recordset.m_assess_Date = m_tmGDate;
m_recordset.m_mode        = m_strMode;
m_recordset.m_title       = m_strTitle;
m_recordset.m_unit        =   m_strUnit;
// 教工编号code也要保存进后台数据库PostDB.accdb中
m_recordset.m_code  =   m_strCode  ;
m_recordset.Update();
m_recordset.Close();
DataUpdate(m_strCode);
// 添加代码结束
}

void CTechnicalAccessDlg::OnClickListTechnicalaccess(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	// 添加代码
CString strSQL;
UpdateData(TRUE);
int i = m_ctrTAccess.GetSelectionMark();
strSQL.Format("select * from technicalAssess where number =%s",m_ctrTAccess.GetItemText(i,0));
if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
{
MessageBox("打开数据库失败!","数据库错误",MB_OK);
return ;
}
m_strEmploy  = m_recordset.m_employ;
m_strHire    = m_recordset.m_hire;
m_tmGDate    = m_recordset.m_assess_Date;
m_tmBDate    = m_recordset.m_begin;
m_tmEDate    = m_recordset.m_end;
m_strMode    = m_recordset.m_mode;
m_strTitle   = m_recordset.m_title;
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

BOOL CTechnicalAccessDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	// 添加代码
// 初始化职称评定对话框中的列表控件表头
m_ctrTAccess.InsertColumn(0,"序号");
m_ctrTAccess.SetColumnWidth(0,60);
m_ctrTAccess.InsertColumn(1,"专业技术资格名称");
m_ctrTAccess.SetColumnWidth(1,80);
m_ctrTAccess.InsertColumn(2,"评定方式");
m_ctrTAccess.SetColumnWidth(2,80);
m_ctrTAccess.InsertColumn(3,"评定单位");
m_ctrTAccess.SetColumnWidth(3,80);
m_ctrTAccess.InsertColumn(4,"取得时间");
m_ctrTAccess.SetColumnWidth(4,80);
m_ctrTAccess.InsertColumn(5,"聘用专业技术职务");
m_ctrTAccess.SetColumnWidth(5,80);
m_ctrTAccess.InsertColumn(6,"聘用开始时间");
m_ctrTAccess.SetColumnWidth(6,80);
m_ctrTAccess.InsertColumn(7,"聘用结束时间");
m_ctrTAccess.SetColumnWidth(7,80);
m_ctrTAccess.InsertColumn(8,"聘用单位");
m_ctrTAccess.SetColumnWidth(8,80);
m_ctrTAccess.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
m_bntSave.EnableWindow(FALSE);
m_bntAdd.EnableWindow(FALSE);
m_bntDelete.EnableWindow(FALSE);
m_bntUpdate.EnableWindow(FALSE);
// 添加代码结束
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTechnicalAccessDlg::DataUpdate(CString strCode)
{
    // 添加代码
m_ctrTAccess.DeleteAllItems();
m_ctrTAccess.SetRedraw(FALSE);
UpdateData(TRUE);
CString strSQL;
m_strCode.Format("%s",strCode);
// SQL语句条件表达式中的code是教工的工号
strSQL.Format( "select * from technicalAssess where code = '%s'",strCode);
if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
{
MessageBox("打开数据库失败!","数据库错误",MB_OK);
return ;
}
int i=0;
CString strGTime; // 对应取得时间
CString strBTime; // 对应聘用开始时间
CString strETime; // 对应聘用结束时间
char buffer[20];
while(!m_recordset.IsEOF())
{
// 对应列表框上的序号
_ltoa(m_recordset.m_numder,buffer,10);
m_ctrTAccess.InsertItem(i,buffer);
// 对应列表框上的专业技术资格名称
m_ctrTAccess.SetItemText(i,1,m_recordset.m_title);
// 对应列表框上的评定方式
m_ctrTAccess.SetItemText(i,2,m_recordset.m_mode);
// 对应列表框上的评定单位
m_ctrTAccess.SetItemText(i,3,m_recordset.m_unit);
// 对应列表框上的取得时间
strGTime.Format("%d-%d-%d",m_recordset.m_assess_Date.GetYear(),m_recordset.\
	m_assess_Date.GetMonth(),m_recordset.m_assess_Date.GetDay());
m_ctrTAccess.SetItemText(i,4,strGTime);
// 对应列表框上的聘用专业技术职务
m_ctrTAccess.SetItemText(i,5,m_recordset.m_hire);
// 对应列表框上的聘用开始时间
strBTime.Format("%d-%d-%d",m_recordset.m_begin.GetYear(),m_recordset.m_begin.\
	GetMonth(),m_recordset.m_begin.GetDay());
m_ctrTAccess.SetItemText(i,6,strBTime);
// 对应列表框上的聘用结束时间
strETime.Format("%d-%d-%d",m_recordset.m_end.GetYear(),m_recordset.m_end.\
    GetMonth(),m_recordset.m_end.GetDay());
m_ctrTAccess.SetItemText(i,7,strETime);
// 对应列表框上的聘用单位
m_ctrTAccess.SetItemText(i,8,m_recordset.m_employ);
i++;
m_recordset.MoveNext();
}
m_recordset.Close();
m_ctrTAccess.SetRedraw(TRUE);
// 根据是否添加新的职称评定记录设置添加与保存两个按钮的状态
m_bntSave.EnableWindow(FALSE);
if(m_strCode=="")
m_bntAdd.EnableWindow(FALSE);
else
m_bntAdd.EnableWindow();
m_bntDelete.EnableWindow(FALSE);
m_bntUpdate.EnableWindow(FALSE);
// 添加代码结束
}

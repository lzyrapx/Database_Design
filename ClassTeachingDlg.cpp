// ClassTeachingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "ClassTeachingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClassTeachingDlg dialog


CClassTeachingDlg::CClassTeachingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClassTeachingDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClassTeachingDlg)
	m_strSemester = _T("");
	m_strSort = _T("");
	m_strObject = _T("");
	m_strAnnual = _T("");
	m_strCourse = _T("");
	m_strLocation = _T("");
	m_strClass = _T("");
	m_strHour = _T("");
	m_strLevel = _T("");
	// 添加代码
    m_strCode = "";
    // 添加代码结束
	//}}AFX_DATA_INIT
}


void CClassTeachingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClassTeachingDlg)
	DDX_Control(pDX, IDC_LIST_CLASSTEACHING, m_ctrTeaching);
	DDX_Control(pDX, IDC_BUTTON_SAVE, m_bntSave);
	DDX_Control(pDX, IDC_BUTTON_UPDATE, m_bntUpdate);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_bntDelete);
	DDX_Control(pDX, IDC_BUTTON_ADD, m_bntAdd);
	DDX_CBString(pDX, IDC_COMBO_SEMESTER, m_strSemester);
	DDX_CBString(pDX, IDC_COMBO_SORT, m_strSort);
	DDX_CBString(pDX, IDC_COMBO_OBJECT, m_strObject);
	DDX_Text(pDX, IDC_EDIT_ANNUAL, m_strAnnual);
	DDX_Text(pDX, IDC_EDIT_COURSE, m_strCourse);
	DDX_Text(pDX, IDC_EDIT_LOCATION, m_strLocation);
	DDX_Text(pDX, IDC_EDIT_CLASS, m_strClass);
	DDX_Text(pDX, IDC_EDIT_HOUR, m_strHour);
	DDX_CBString(pDX, IDC_COMBO_LEVEL, m_strLevel);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CClassTeachingDlg, CDialog)
	//{{AFX_MSG_MAP(CClassTeachingDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, OnButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_NOTIFY(NM_CLICK, IDC_LIST_CLASSTEACHING, OnClickListClassteaching)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClassTeachingDlg message handlers

void CClassTeachingDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
m_strAnnual   = "";
m_strClass    = "";
m_strCourse   = "";
m_strHour     = "";
m_strLevel    = "";
m_strLocation = "";
m_strObject   = "";
m_strSemester = "";
m_strSort     = "";
m_bntSave.EnableWindow();
m_bntAdd.EnableWindow(FALSE);
m_bntDelete.EnableWindow(FALSE);
m_bntUpdate.EnableWindow(FALSE);
UpdateData(FALSE);
// 添加代码结束
}

void CClassTeachingDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
int i = m_ctrTeaching.GetSelectionMark();
if(i<0)
{
MessageBox("请选择一条记录进行删除！");
return;
}
CString strSQL;
strSQL.Format("select * from classTeaching where number =%s",m_ctrTeaching.GetItemText(i,0));
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
m_strAnnual     = "";
m_strClass      = "";
m_strCourse     = "";
m_strHour       = "";
m_strLevel      = "";
m_strLocation   = "";
m_strObject     = "";
m_strSemester   = "";
m_strSort       = "";
UpdateData(FALSE);
// 添加代码结束
}

void CClassTeachingDlg::OnButtonUpdate() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
UpdateData();
int i = m_ctrTeaching.GetSelectionMark();
if(i<0)
{
MessageBox("请选择一条记录进行修改！");
return;
}
CString strSQL;
strSQL.Format("select * from classTeaching where number = %s",m_ctrTeaching.GetItemText(i,0));
if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
{
MessageBox("打开数据库失败!","数据库错误",MB_OK);
return ;
}
m_recordset.Edit();
m_recordset.m_annual       = m_strAnnual;
m_recordset.m_class        = m_strClass;
m_recordset.m_course       = m_strCourse;
m_recordset.m_level        = m_strLevel;
m_recordset.m_object       = m_strObject;
m_recordset.m_hour         = m_strHour;
m_recordset.m_sort         = m_strSort;
m_recordset.m_location     = m_strLocation;
m_recordset.m_semester     = m_strSemester;
m_recordset.Update();
m_recordset.Close();
DataUpdate(m_strCode);
// 添加代码结束
}

void CClassTeachingDlg::OnButtonSave() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
UpdateData();
if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE))
{
MessageBox("打开数据库失败!","数据库错误",MB_OK);
return ;
}
if(m_strCourse=="")
{
MessageBox("课程名不能为空，请输入课程名称！");
return;
}
if(m_strClass=="")
{
MessageBox("授课班级不能为空，请输入授课班级名称！");
return;
}
m_recordset.AddNew();
m_recordset.m_annual    = m_strAnnual;
m_recordset.m_class     = m_strClass;
m_recordset.m_course    = m_strCourse;
m_recordset.m_level     = m_strLevel;
m_recordset.m_object    = m_strObject;
m_recordset.m_location  = m_strLocation;
m_recordset.m_sort      = m_strSort;
m_recordset.m_semester  = m_strSemester;
m_recordset.m_hour      = m_strHour;
// 教工编号code也要保存进后台数据库PostDB.accdb中
m_recordset.m_code      = m_strCode;
m_recordset.Update();
m_recordset.Close();
DataUpdate(m_strCode);
// 添加代码结束
}

void CClassTeachingDlg::OnClickListClassteaching(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	// 添加代码
CString strSQL;
UpdateData(TRUE);
int i = m_ctrTeaching.GetSelectionMark();
strSQL.Format("select * from classTeaching where number = %s",m_ctrTeaching.GetItemText(i,0));
if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
{
MessageBox("打开数据库失败!","数据库错误",MB_OK);
return ;
}
m_strAnnual     = m_recordset.m_annual;
m_strClass      = m_recordset.m_class;
m_strCourse     = m_recordset.m_course;
m_strLevel      = m_recordset.m_level;
m_strObject     = m_recordset.m_object;
m_strHour       = m_recordset.m_hour;
m_strObject     = m_recordset.m_object;
m_strLocation   = m_recordset.m_location;
m_strSemester   = m_recordset.m_semester;
m_recordset.Close();
UpdateData(FALSE);
m_bntSave.EnableWindow(FALSE);
m_bntAdd.EnableWindow();
m_bntDelete.EnableWindow();
m_bntUpdate.EnableWindow();
// 添加代码结束
	*pResult = 0;
}

BOOL CClassTeachingDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	// 添加代码
// 初始化继续教育对话框中的列表控件表头
// 年度：、学期：、课程名：、课程性质：、课程类别：、授课班级：、授课对象：、学时：、与地点：
m_ctrTeaching.InsertColumn(0,"序号");
m_ctrTeaching.SetColumnWidth(0,60);
m_ctrTeaching.InsertColumn(1,"年度");
m_ctrTeaching.SetColumnWidth(1,80);
m_ctrTeaching.InsertColumn(2,"学期");
m_ctrTeaching.SetColumnWidth(2,80);
m_ctrTeaching.InsertColumn(3,"课程名");
m_ctrTeaching.SetColumnWidth(3,80);
m_ctrTeaching.InsertColumn(4,"课程性质");
m_ctrTeaching.SetColumnWidth(4,80);
m_ctrTeaching.InsertColumn(5,"课程类别");
m_ctrTeaching.SetColumnWidth(5,80);
m_ctrTeaching.InsertColumn(6,"授课班级");
m_ctrTeaching.SetColumnWidth(6,80);
m_ctrTeaching.InsertColumn(7,"授课对象");
m_ctrTeaching.SetColumnWidth(7,80);
m_ctrTeaching.InsertColumn(8,"学时");
m_ctrTeaching.SetColumnWidth(8,80);
m_ctrTeaching.InsertColumn(9,"地点");
m_ctrTeaching.SetColumnWidth(9,80);
m_ctrTeaching.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
m_bntSave.EnableWindow(FALSE);
m_bntAdd.EnableWindow(FALSE);
m_bntDelete.EnableWindow(FALSE);
m_bntUpdate.EnableWindow(FALSE);
// 添加代码结束
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CClassTeachingDlg::DataUpdate(CString strCode)
{
    // 添加代码
m_ctrTeaching.DeleteAllItems();
m_ctrTeaching.SetRedraw(FALSE);
UpdateData(TRUE);
CString strSQL;
m_strCode.Format("%s",strCode);
// SQL语句条件表达式中的code是教工的工号
strSQL.Format( "select * from classTeaching where code = '%s'",strCode);
if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
{
MessageBox("打开数据库失败!","数据库错误",MB_OK);
return ;
}
int i=0;
char buffer[20];
while(!m_recordset.IsEOF())
{ // 对应列表框上的序号
_ltoa(m_recordset.m_number,buffer,10);
m_ctrTeaching.InsertItem(i,buffer);
// 对应列表框上的年度
m_ctrTeaching.SetItemText(i,1,m_recordset.m_annual);
// 对应列表框上的学期
m_ctrTeaching.SetItemText(i,2,m_recordset.m_semester);
// 对应列表框上的课程名
m_ctrTeaching.SetItemText(i,3,m_recordset.m_course);
// 对应列表框上的课程性质
m_ctrTeaching.SetItemText(i,4,m_recordset.m_sort);
// 对应列表框上的课程类别
m_ctrTeaching.SetItemText(i,5,m_recordset.m_level);
// 对应列表框上的授课班级
m_ctrTeaching.SetItemText(i,6,m_recordset.m_class);
// 对应列表框上的授课对象
m_ctrTeaching.SetItemText(i,7,m_recordset.m_object);
// 对应列表框上的学时
m_ctrTeaching.SetItemText(i,8,m_recordset.m_hour);
// 对应列表框上的地点
m_ctrTeaching.SetItemText(i,9,m_recordset.m_location);
i++;
m_recordset.MoveNext();
}
m_recordset.Close();
m_ctrTeaching.SetRedraw(TRUE);
// 根据是否添加新的课堂教学记录设置添加与保存两个按钮的状态
m_bntSave.EnableWindow(FALSE);
if(m_strCode=="")
m_bntAdd.EnableWindow(FALSE);
else
m_bntAdd.EnableWindow();
m_bntDelete.EnableWindow(FALSE);
m_bntUpdate.EnableWindow(FALSE);
// 添加代码结束
}

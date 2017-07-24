// WorkExperienceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "WorkExperienceDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWorkExperienceDlg dialog


CWorkExperienceDlg::CWorkExperienceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWorkExperienceDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWorkExperienceDlg)
	m_tmBegin = 0;
	m_tmEnd = 0;
	m_strEducation = _T("");
	m_strLocation = _T("");
	m_strCompany = _T("");
	m_strProver = _T("");
	m_strDuty = _T("");
	m_strTechnical = _T("");
	m_strDepartment = _T("");
	// 添加代码
    m_strCode = "";
    // 添加代码结束
	//}}AFX_DATA_INIT
}


void CWorkExperienceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWorkExperienceDlg)
	DDX_Control(pDX, IDC_LIST_WORKEXPERIENCE, m_ctrWork);
	DDX_Control(pDX, IDC_BUTTON_SAVE, m_bntSave);
	DDX_Control(pDX, IDC_BUTTON_UPDATE, m_bntUpdate);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_bntDelete);
	DDX_Control(pDX, IDC_BUTTON_ADD, m_bntAdd);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_BEGIN, m_tmBegin);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_END, m_tmEnd);
	DDX_CBString(pDX, IDC_COMBO_EDUCATION, m_strEducation);
	DDX_Text(pDX, IDC_EDIT_LOCATION, m_strLocation);
	DDX_Text(pDX, IDC_EDIT_COMPANY, m_strCompany);
	DDX_Text(pDX, IDC_EDIT_PROVER, m_strProver);
	DDX_Text(pDX, IDC_EDIT_DUTY, m_strDuty);
	DDX_Text(pDX, IDC_EDIT_TECHNICAL, m_strTechnical);
	DDX_Text(pDX, IDC_EDIT_DEPARTMENT, m_strDepartment);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWorkExperienceDlg, CDialog)
	//{{AFX_MSG_MAP(CWorkExperienceDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, OnButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_NOTIFY(NM_CLICK, IDC_LIST_WORKEXPERIENCE, OnClickListWorkexperience)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWorkExperienceDlg message handlers

void CWorkExperienceDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
        m_strDepartment = "";
        m_strLocation   = "";
        m_strCompany    = "";
        m_strDuty       = "";
        m_strTechnical  = "";
        m_strProver     = "";
        m_tmBegin = CTime::GetCurrentTime();
        m_strEducation  =   "";
        m_tmEnd = CTime::GetCurrentTime();
        m_bntSave.EnableWindow();
        m_bntAdd.EnableWindow(FALSE);
        m_bntDelete.EnableWindow(FALSE);
        m_bntUpdate.EnableWindow(FALSE);
        UpdateData(FALSE);
        // 添加代码结束
}

void CWorkExperienceDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
        int i = m_ctrWork.GetSelectionMark();
        if(i<0)
        {
            MessageBox("请选择一条记录进行删除！");
            return;
        }
        CString strSQL;
        strSQL.Format("select * from workExperience where number= %s",m_ctrWork.GetItemText(i,0));
        if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
        {
             MessageBox("打开数据库失败!","数据库错误",MB_OK);
             return;
        }
        //删除该记录
        m_recordset.Delete();
        m_recordset.Close();
        //更新用户界面
        DataUpdate(m_strCode);
        m_strDepartment = "";
        m_strTechnical = "";
        m_strCompany = "";
        m_strDuty  = "";
        m_strProver  = "";
        m_tmBegin  = CTime::GetCurrentTime();
        m_tmEnd = CTime::GetCurrentTime();
        m_strLocation = "";
        m_strEducation = "";
        UpdateData(FALSE);
        // 添加代码结束
}

void CWorkExperienceDlg::OnButtonUpdate() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
        UpdateData();
        int i = m_ctrWork.GetSelectionMark();
        if(i<0)
        {
            MessageBox("请选择一条记录进行修改！");
            return;
        }
        CString strSQL;
        strSQL.Format("select * from workExperience where number =%s",m_ctrWork.GetItemText(i,0));
        if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
        {
             MessageBox("打开数据库失败!","数据库错误",MB_OK);
             return;
        }
        m_recordset.Edit();
        m_recordset.m_department   = m_strDepartment;
        m_recordset.m_end_Date     = m_tmEnd;
        m_recordset.m_begin_Date   = m_tmBegin;
        m_recordset.m_company      = m_strCompany;
        m_recordset.m_duty         = m_strDuty;
        m_recordset.m_technical    = m_strTechnical;
        m_recordset.m_location     = m_strLocation;
        m_recordset.m_proof        = m_strProver;
        m_recordset.m_education    = m_strEducation;
        m_recordset.Update();
        m_recordset.Close();
        DataUpdate(m_strCode);
        // 添加代码结束
}

void CWorkExperienceDlg::OnButtonSave() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
    UpdateData();
    if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE))
    {
         MessageBox("打开数据库失败!","数据库错误",MB_OK);
         return;
    }
    m_recordset.AddNew();
    m_recordset.m_department = m_strDepartment;
    m_recordset.m_location   = m_strLocation;
    m_recordset.m_begin_Date = m_tmBegin;
    m_recordset.m_company    = m_strCompany;
    m_recordset.m_duty       = m_strDuty;
    m_recordset.m_technical  = m_strTechnical;
    m_recordset.m_proof      = m_strProver;
    m_recordset.m_code       = m_strCode;
    m_recordset.m_education  = m_strEducation;
    m_recordset.m_end_Date   = m_tmEnd;
    m_recordset.Update();
    m_recordset.Close();
    DataUpdate(m_strCode);
    // 添加代码结束
}

void CWorkExperienceDlg::OnClickListWorkexperience(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	// 添加代码
    CString strSQL;
    UpdateData(TRUE);
    int i = m_ctrWork.GetSelectionMark();
    strSQL.Format("select * from workExperience where number=%s",m_ctrWork.GetItemText(i,0));
    if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
         MessageBox("打开数据库失败!","数据库错误",MB_OK);
         return;
    }
    m_strDepartment = m_recordset.m_department;
    m_strLocation   = m_recordset.m_location;
    m_tmBegin       = m_recordset.m_begin_Date;
    m_strCompany    = m_recordset.m_company;
    m_strDuty       = m_recordset.m_duty;
    m_strTechnical  = m_recordset.m_technical;
    m_strProver     = m_recordset.m_proof;
    m_strEducation  = m_recordset.m_education;
    m_tmEnd         = m_recordset.m_end_Date;
    m_recordset.Close();
    UpdateData(FALSE);
    m_bntSave.EnableWindow(FALSE);
    m_bntAdd.EnableWindow();
    m_bntDelete.EnableWindow();
    m_bntUpdate.EnableWindow();
    // 添加代码结束
	*pResult = 0;
}

BOOL CWorkExperienceDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	// 添加代码
    // 初始化工作经历对话框中的列表控件表头
    m_ctrWork.InsertColumn(0,"序号");
    m_ctrWork.SetColumnWidth(0,60);
    m_ctrWork.InsertColumn(1,"开始时间");
    m_ctrWork.SetColumnWidth(1,80);
    m_ctrWork.InsertColumn(2,"结束时间");
    m_ctrWork.SetColumnWidth(2,80);
    m_ctrWork.InsertColumn(3,"工作单位");
    m_ctrWork.SetColumnWidth(3,80);
    m_ctrWork.InsertColumn(4,"所属部门");
    m_ctrWork.SetColumnWidth(4,80);
    m_ctrWork.InsertColumn(5,"职务");
    m_ctrWork.SetColumnWidth(5,80);
    m_ctrWork.InsertColumn(6,"职称");
    m_ctrWork.SetColumnWidth(6,80);
    m_ctrWork.InsertColumn(7,"学历");
    m_ctrWork.SetColumnWidth(7,80);
    m_ctrWork.InsertColumn(8,"所在地域");
    m_ctrWork.SetColumnWidth(8,80);
    m_ctrWork.InsertColumn(9,"证明人");
    m_ctrWork.SetColumnWidth(9,80);
    m_ctrWork.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
    m_bntSave.EnableWindow(FALSE);
    m_bntAdd.EnableWindow(FALSE);
    m_bntDelete.EnableWindow(FALSE);
    m_bntUpdate.EnableWindow(FALSE);
    // 添加代码结束
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CWorkExperienceDlg::DataUpdate(CString strCode)
{
    // 添加代码
    m_ctrWork.DeleteAllItems();
    m_ctrWork.SetRedraw(FALSE);
    UpdateData(TRUE);
    CString strSQL;
    m_strCode.Format("%s",strCode);
    // SQL语句条件表达式中的code是教工的工号
    strSQL.Format( "select * from workExperience where code = '%s'",strCode);
    if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
         MessageBox("打开数据库失败!","数据库错误",MB_OK);
         return ;
    }
    int i=0;
    CString strBeginTime; // 对应开始时间
    CString strEndTime;   // 对应结束时间
    char buffer[20];
    while(!m_recordset.IsEOF())
    {
    // 对应列表框上的序号
    _ltoa(m_recordset.m_number,buffer,10);
    m_ctrWork.InsertItem(i,buffer);
    // 对应列表框上的开始时间
    strBeginTime.Format("%d-%d-%d",m_recordset.m_begin_Date.GetYear(),m_recordset.\
       m_begin_Date.GetMonth(),m_recordset.m_begin_Date.GetDay());
    m_ctrWork.SetItemText(i,1,strBeginTime);
    // 对应列表框上的结束时间
    strEndTime.Format("%d-%d-%d",m_recordset.m_end_Date.GetYear(),m_recordset.m_end_Date.\
	   GetMonth(),m_recordset.m_end_Date.GetDay());
    m_ctrWork.SetItemText(i,2,strEndTime);
    // 对应列表框上的工作单位
    m_ctrWork.SetItemText(i,3,m_recordset.m_company);
    // 对应列表框上的所属部门
    m_ctrWork.SetItemText(i,4,m_recordset.m_department);
    // 对应列表框上的职务
    m_ctrWork.SetItemText(i,5,m_recordset.m_duty);
    // 对应列表框上的职称
    m_ctrWork.SetItemText(i,6,m_recordset.m_technical);
    // 对应列表框上的学历
    m_ctrWork.SetItemText(i,7,m_recordset.m_education);
    // 对应列表框上的所在地域
    m_ctrWork.SetItemText(i,8,m_recordset.m_location);
    // 对应列表框上的证明人
    m_ctrWork.SetItemText(i,9,m_recordset.m_proof);
    i++;
    m_recordset.MoveNext();
    }
    m_recordset.Close();
    m_ctrWork.SetRedraw(TRUE);
    // 根据是否添加新的工作经历设置添加与保存两个按钮的状态
    m_bntSave.EnableWindow(FALSE);
    if(m_strCode=="")
    m_bntAdd.EnableWindow(FALSE);
    else
       m_bntAdd.EnableWindow();
       m_bntDelete.EnableWindow(FALSE);
       m_bntUpdate.EnableWindow(FALSE);
    // 添加代码结束
}

// FamilyMemberDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "FamilyMemberDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFamilyMemberDlg dialog


CFamilyMemberDlg::CFamilyMemberDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFamilyMemberDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFamilyMemberDlg)
	m_tmBirth = 0;
	m_strPolitical = _T("");
	m_strCID = _T("");
	m_strName = _T("");
	m_strDuty = _T("");
	m_strEducation = _T("");
	m_strPhone = _T("");
	m_strRelation = _T("");
	m_strCompany = _T("");
	//}}AFX_DATA_INIT
	//添加代码
	m_strCode = "";    //对应familyMember表的工号code
	//添加代码结束
}


void CFamilyMemberDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFamilyMemberDlg)
	DDX_Control(pDX, IDC_LIST_FAMILY, m_ctrFamily);
	DDX_Control(pDX, IDC_BUTTON_SAVE, m_bntSave);
	DDX_Control(pDX, IDC_BUTTON_UPDATE, m_bntUpdate);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_bntDelete);
	DDX_Control(pDX, IDC_BUTTON_ADD, m_bntAdd);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_BIRTH, m_tmBirth);
	DDX_CBString(pDX, IDC_COMBO_POLITICAL, m_strPolitical);
	DDX_Text(pDX, IDC_EDIT_CID, m_strCID);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_DUTY, m_strDuty);
	DDX_Text(pDX, IDC_EDIT_EDUCATION, m_strEducation);
	DDX_Text(pDX, IDC_EDIT_PHONE, m_strPhone);
	DDX_Text(pDX, IDC_EDIT_RELATION, m_strRelation);
	DDX_Text(pDX, IDC_EDIT_COMPANY, m_strCompany);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFamilyMemberDlg, CDialog)
	//{{AFX_MSG_MAP(CFamilyMemberDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, OnButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_NOTIFY(NM_CLICK, IDC_LIST_FAMILY, OnClickListFamily)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFamilyMemberDlg message handlers

void CFamilyMemberDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	m_strName      = "";
	m_strRelation  = "";
	m_strCompany   = ""; 
	m_strDuty      = "";
	m_strPolitical = "";
	m_strPhone     = "";
	m_tmBirth = CTime::GetCurrentTime();
	m_strEducation = ""; 
	m_strCID       = "";
	m_bntSave.EnableWindow();
	m_bntAdd.EnableWindow(FALSE);
	m_bntDelete.EnableWindow(FALSE);
	m_bntUpdate.EnableWindow(FALSE); 
	UpdateData(FALSE);
	//添加代码结束
}

void CFamilyMemberDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
    //添加代码
	int i = m_ctrFamily.GetSelectionMark();
	if(i < 0)
	{
		MessageBox("请选择一条记录进行删除！");
		return; 
	}
	CString strSQL;
    strSQL.Format("select * from familyMember where number = %s",m_ctrFamily.GetItemText(i,0));
    if(! m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
	    MessageBox("打开数据库失败！","数据库错误",MB_OK);
	    return;
    }
	//删除该记录
	m_recordset.Delete();
	m_recordset.Close();
	//更新用户界面
	DataUpdate(m_strCode);
	m_strName = "";
	m_strRelation ="";
	m_strCompany = ""; 
	m_strDuty = "";
	m_strPolitical = "";
	m_strPhone = "";
	m_tmBirth = CTime::GetCurrentTime();
	m_strCID  = "";
	m_strEducation  = "";
	UpdateData(FALSE);
	//添加代码结束	
}

void CFamilyMemberDlg::OnButtonUpdate() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	UpdateData();
	int i = m_ctrFamily.GetSelectionMark();
	if(i < 0)
	{
		MessageBox("请选择一条记录进行修改！");
		return; 
	}
	if(m_strName == "")
	{
		MessageBox("请输入姓名!");
		return; 
	}
	CString strSQL;
    strSQL.Format("select * from familyMember where number = %s",m_ctrFamily.GetItemText(i,0));
    if(! m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
	    MessageBox("打开数据库失败！","数据库错误",MB_OK);
	    return;
    }
    m_recordset.Edit(); 
	m_recordset.m_name          = m_strName;
	m_recordset.m_relation      = m_strRelation;
	m_recordset.m_birth         = m_tmBirth;
	m_recordset.m_company       = m_strCompany; 
	m_recordset.m_duty          = m_strDuty;
	m_recordset.m_political     = m_strPolitical;
	m_recordset.m_phone         = m_strPhone;
	m_recordset.m_identity_Card = m_strCID;
	m_recordset.m_education     = m_strEducation;
	m_recordset.Update();
	m_recordset.Close();
	DataUpdate(m_strCode);
	//添加代码结束
}

void CFamilyMemberDlg::OnButtonSave() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	UpdateData();
	if(m_strName == "")
	{
		MessageBox("请输入姓名!");
		return; 
	}
    if(! m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE))
    {
	    MessageBox("打开数据库失败！","数据库错误",MB_OK);
	    return;
    }
    m_recordset.AddNew(); 
	m_recordset.m_name          = m_strName;
	m_recordset.m_relation      = m_strRelation;
	m_recordset.m_birth         = m_tmBirth;
	m_recordset.m_company       = m_strCompany; 
	m_recordset.m_duty          = m_strDuty;
	m_recordset.m_political     = m_strPolitical;
	m_recordset.m_phone         = m_strPhone;
    m_recordset.m_code          = m_strCode;
	m_recordset.m_education     = m_strEducation;
	m_recordset.m_identity_Card = m_strCID;
	m_recordset.Update();
	m_recordset.Close();
	DataUpdate(m_strCode);
	//添加代码结束
}

void CFamilyMemberDlg::OnClickListFamily(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	//添加代码
	CString strSQL;
	UpdateData(TRUE);
	int i = m_ctrFamily.GetSelectionMark();
	//表familyMemberSet中主码number虽然是长整型，但where子句仍用字符，若改为%ld，
	//虽然数据类型可以匹配，但修改与保存按钮则会出现未选择当前记录的异常 
    strSQL.Format("select * from familyMember where number = %s",m_ctrFamily.GetItemText(i,0));
    if(! m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
	    MessageBox("打开数据库失败！","数据库错误",MB_OK);
	    return;
    } 
    m_strName      = m_recordset.m_name;
	m_strRelation  = m_recordset.m_relation;
	m_tmBirth      = m_recordset.m_birth;
	m_strCompany   = m_recordset.m_company; 
	m_strDuty      = m_recordset.m_duty;
	m_strPolitical = m_recordset.m_political;
	m_strPhone     = m_recordset.m_phone;
	m_strEducation = m_recordset.m_education;
	m_strCID       = m_recordset.m_identity_Card;
	m_recordset.Close();
	UpdateData(FALSE);
    m_bntSave.EnableWindow(FALSE);
	m_bntAdd.EnableWindow();
	m_bntDelete.EnableWindow();
	m_bntUpdate.EnableWindow();
	//添加代码结束
	*pResult = 0;
}

BOOL CFamilyMemberDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//添加代码
	//初始化家庭成员对话框中的列表控件表头 
	m_ctrFamily.InsertColumn(0,"序号");
    m_ctrFamily.SetColumnWidth(0,60);
    m_ctrFamily.InsertColumn(1,"姓名");
    m_ctrFamily.SetColumnWidth(1,80);
	m_ctrFamily.InsertColumn(2,"身份证号");
    m_ctrFamily.SetColumnWidth(2,80);
	m_ctrFamily.InsertColumn(3,"与教工关系");
    m_ctrFamily.SetColumnWidth(3,80);
	m_ctrFamily.InsertColumn(4,"生日");
    m_ctrFamily.SetColumnWidth(4,80);
	m_ctrFamily.InsertColumn(5,"工作单位");
    m_ctrFamily.SetColumnWidth(5,80);
	m_ctrFamily.InsertColumn(6,"联系电话");
    m_ctrFamily.SetColumnWidth(6,80);
	m_ctrFamily.InsertColumn(7,"职务");
    m_ctrFamily.SetColumnWidth(7,80);
    m_ctrFamily.InsertColumn(8,"政治面貌");
    m_ctrFamily.SetColumnWidth(8,80);
    m_ctrFamily.InsertColumn(9,"文化程度");
    m_ctrFamily.SetColumnWidth(9,80);
	m_ctrFamily.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES); 
	m_bntSave.EnableWindow(FALSE);
	m_bntAdd.EnableWindow(FALSE);
	m_bntDelete.EnableWindow(FALSE);
	m_bntUpdate.EnableWindow(FALSE);
	//添加代码结束
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CFamilyMemberDlg::DataUpdate(CString strCode)
{
    //添加代码
	m_ctrFamily.DeleteAllItems();
	m_ctrFamily.SetRedraw(FALSE);
	UpdateData(TRUE);
	CString strSQL;
	m_strCode.Format("%s",strCode);
	//SQL语句条件表达式中的code是教工的工号 
	strSQL.Format("select * from familyMember where code = %s",strCode);
    if(! m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
	    MessageBox("打开数据库失败！","数据库错误",MB_OK);
	    return;
    }
	int i = 0;
	CString strTime;
	char buffer[20];
	while(! m_recordset.IsEOF())
	{
		//对应列表框上的序号
		_ltoa(m_recordset.m_number,buffer,10);
		m_ctrFamily.InsertItem(i,buffer);
		//对应列表框上的姓名
		m_ctrFamily.SetItemText(i,1,m_recordset.m_name);
		//对应列表框上的身份证号 
		m_ctrFamily.SetItemText(i,2,m_recordset.m_identity_Card);
		//对应列表框上的教工关系 
		m_ctrFamily.SetItemText(i,3,m_recordset.m_relation);
		//对应列表框上的生日
		strTime.Format("%d - %d - %d",m_recordset.m_birth.GetYear(),m_recordset.m_birth.GetMonth(),m_recordset.m_birth.GetDay());
		m_ctrFamily.SetItemText(i,4,strTime);   
		//对应列表框上的工作单位
		m_ctrFamily.SetItemText(i,5,m_recordset.m_company);
		//对应列表框上的联系电话
		m_ctrFamily.SetItemText(i,6,m_recordset.m_phone); 
		//对应列表框上的职务
		m_ctrFamily.SetItemText(i,7,m_recordset.m_duty);
		//对应列表框上的政治面貌
		m_ctrFamily.SetItemText(i,8,m_recordset.m_political);
		//对应列表框上的文化程度
		m_ctrFamily.SetItemText(i,9,m_recordset.m_education);
		i++;
		m_recordset.MoveNext();     
	 } 
	 m_recordset.Close();
	 m_ctrFamily.SetRedraw(TRUE);
	 //根据是否添加新的家庭成员设置添加与保存两个按钮的状态
	 m_bntSave.EnableWindow(FALSE);
	 if(m_strCode == "")
	 m_bntAdd.EnableWindow(FALSE);
	 else
	     m_bntAdd.EnableWindow();
		 m_bntDelete.EnableWindow(FALSE);
		 m_bntUpdate.EnableWindow(FALSE);
    //添加代码结束
}

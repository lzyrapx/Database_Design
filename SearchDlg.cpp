// SearchDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "SearchDlg.h"
//添加代码
#include "NationInformationSet.h"
#include "PositionInformationSet.h"
#include "EducationDegreeSet.h"
#include "PoliticalStatusSet.h"
#include "DepartmentSectionSet.h"
#include "TechnicalPostSet.h"
#include "AdministrativePostSet.h"
//添加代码结束 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSearchDlg dialog


CSearchDlg::CSearchDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSearchDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSearchDlg)
	m_strEducation = _T("");
	m_strMarriage = _T("");
	m_strNation = _T("");
	m_strPolitical = _T("");
	m_strPosition = _T("");
	m_strPost = _T("");
	m_strTechnical = _T("");
	m_strUnit = _T("");
	m_strSex = _T("");
	m_iAge = 0;
	m_strName = _T("");
	m_strNative = _T("");
	//}}AFX_DATA_INIT
}


void CSearchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSearchDlg)
	DDX_Control(pDX, IDC_LIST_SEARCH, m_ctrSearch);
	DDX_Control(pDX, IDC_COMBO_UNIT, m_ctrUnit);
	DDX_Control(pDX, IDC_COMBO_TECHNICAL, m_ctrTechnical);
	DDX_Control(pDX, IDC_COMBO_POST, m_ctrPost);
	DDX_Control(pDX, IDC_COMBO_POSITION, m_ctrPosition);
	DDX_Control(pDX, IDC_COMBO_POLITICAL, m_ctrPolitical);
	DDX_Control(pDX, IDC_COMBO_NATION, m_ctrNation);
	DDX_Control(pDX, IDC_COMBO_MARRIAGE, m_ctrMarriage);
	DDX_Control(pDX, IDC_COMBO_EDUCATION, m_ctrEducation);
	DDX_CBString(pDX, IDC_COMBO_EDUCATION, m_strEducation);
	DDX_CBString(pDX, IDC_COMBO_MARRIAGE, m_strMarriage);
	DDX_CBString(pDX, IDC_COMBO_NATION, m_strNation);
	DDX_CBString(pDX, IDC_COMBO_POLITICAL, m_strPolitical);
	DDX_CBString(pDX, IDC_COMBO_POSITION, m_strPosition);
	DDX_CBString(pDX, IDC_COMBO_POST, m_strPost);
	DDX_CBString(pDX, IDC_COMBO_TECHNICAL, m_strTechnical);
	DDX_CBString(pDX, IDC_COMBO_UNIT, m_strUnit);
	DDX_CBString(pDX, IDC_COMBO_SEX, m_strSex);
	DDX_Text(pDX, IDC_EDIT_AGE, m_iAge);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_NATIVE, m_strNative);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSearchDlg, CDialog)
	//{{AFX_MSG_MAP(CSearchDlg)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSearchDlg message handlers

void CSearchDlg::OnButtonSearch() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	UpdateData();
	CString strSQL;   //构造的最终SQL查询执行语句
	CString strTemp;  //用于多重连接条件查询的临时SQL语句变量
	BOOL bNoCondition = TRUE;  //设置多重连接条件查询的开关变量
	strSQL = "select * from staff where ";  //注意where后面有空格，否则解析错误
	//按教工的姓名查询
	if(m_strName != "")
	{
		strTemp.Format("name = '%s'",m_strName);
		if(!bNoCondition)
		     strSQL += "and";
		     strSQL += strTemp;
		bNoCondition = FALSE;
	}
	//按教工的性别查询
	if(m_strSex != "")
	{
		strTemp.Format("sex = '%s'",m_strSex);
		if(!bNoCondition)
		     strSQL += "and";
		     strSQL += strTemp;
		bNoCondition = FALSE;
	}
	//按教工的年龄查询
	if(m_iAge > 0)
	{
		strTemp.Format("age = '%s'",m_iAge);
		if(!bNoCondition)
		     strSQL += "and";
		     strSQL += strTemp;
		bNoCondition = FALSE;
	}
	//按教工所在的院系部门查询
	if(m_strUnit != "")
	{
		strTemp.Format("department = '%s'",m_strUnit);
		if(!bNoCondition)
		     strSQL += "and";
		     strSQL += strTemp;
		bNoCondition = FALSE;
	}
	//按教工的职务查询
	if(m_strPost != "")
	{
		strTemp.Format("job = '%s'",m_strPost);
		if(!bNoCondition)
		     strSQL += "and";
		     strSQL += strTemp;
		bNoCondition = FALSE;
	}
	//按教工的文化程度查询
	if(m_strEducation != "")
	{
		strTemp.Format("degree = '%s'",m_strEducation);
		if(!bNoCondition)
		     strSQL += "and";
		     strSQL += strTemp;
		bNoCondition = FALSE;
	}
	//按教工的民族信息查询
	if(m_strNation != "")
	{
		strTemp.Format("race = '%s'",m_strNation);
		if(!bNoCondition)
		     strSQL += "and";
		     strSQL += strTemp;
		bNoCondition = FALSE;
	}
	//按教工的岗位查询
	if(m_strPosition != "")
	{
		strTemp.Format("name = '%s'",m_strPosition);
		if(!bNoCondition)
		     strSQL += "and";
		     strSQL += strTemp;
		bNoCondition = FALSE;
	}
	//按教工的婚姻状况查询
	if(m_strMarriage != "")
	{
		strTemp.Format("marriage = '%s'",m_strMarriage);
		if(!bNoCondition)
		     strSQL += "and";
		     strSQL += strTemp;
		bNoCondition = FALSE;
	}
	//按教工的政治面貌查询
	if(m_strPolitical != "")
	{
		strTemp.Format("party = '%s'",m_strPolitical);
		if(!bNoCondition)
		     strSQL += "and";
		     strSQL += strTemp;
		bNoCondition = FALSE;
	}
	//按教工的职称查询
	if(m_strTechnical != "")
	{
		strTemp.Format("technical = '%s'",m_strTechnical);
		if(!bNoCondition)
		     strSQL += "and";
		     strSQL += strTemp;
		bNoCondition = FALSE;
	}
	//按教工的籍贯查询
	if(m_strNative != "")
	{
		strTemp.Format("native = '%s'",m_strNative);
		if(!bNoCondition)
		     strSQL += "and";
		     strSQL += strTemp;
		bNoCondition = FALSE;
	}
	if(bNoCondition)
	{
		strSQL = "select * from staff";
	}
	m_ctrSearch.DeleteAllItems();
	m_ctrSearch.SetRedraw(FALSE);
	if(! m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
         MessageBox("打开数据库失败！","数据库错误",MB_OK);
         return ;
    }
	char buffer[20];
	int i = 0;
	while(!m_recordset.IsEOF())
	{
		m_ctrSearch.InsertItem(i,m_recordset.m_code);
		m_ctrSearch.SetItemText(i,1,m_recordset.m_name);
		m_ctrSearch.SetItemText(i,2,m_recordset.m_sex);
		_itoa(m_recordset.m_age,buffer,10);
		m_ctrSearch.SetItemText(i,3,buffer);
		m_ctrSearch.SetItemText(i,4,m_recordset.m_marriage);
		m_ctrSearch.SetItemText(i,5,m_recordset.m_job);
		m_ctrSearch.SetItemText(i,6,m_recordset.m_technical);
		m_ctrSearch.SetItemText(i,7,m_recordset.m_post);
		m_ctrSearch.SetItemText(i,8,m_recordset.m_race);
		m_ctrSearch.SetItemText(i,9,m_recordset.m_degree);
		m_ctrSearch.SetItemText(i,10,m_recordset.m_party);
		m_ctrSearch.SetItemText(i,11,m_recordset.m_identity_Card);
		i++;
		m_recordset.MoveNext();
	}
	m_recordset.Close();
	m_ctrSearch.SetRedraw(TRUE);
	//添加代码结束
}

BOOL CSearchDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//添加代码
	m_ctrSearch.InsertColumn(0,"工号");
    m_ctrSearch.SetColumnWidth(0,60);
	m_ctrSearch.InsertColumn(1,"姓名");
    m_ctrSearch.SetColumnWidth(1,80);
	m_ctrSearch.InsertColumn(2,"性别");
    m_ctrSearch.SetColumnWidth(2,60);
	m_ctrSearch.InsertColumn(3,"年龄");
    m_ctrSearch.SetColumnWidth(3,60);
	m_ctrSearch.InsertColumn(4,"婚姻状况");
    m_ctrSearch.SetColumnWidth(4,60);
	m_ctrSearch.InsertColumn(5,"职务");
    m_ctrSearch.SetColumnWidth(5,80);
	m_ctrSearch.InsertColumn(6,"职称");
    m_ctrSearch.SetColumnWidth(6,80);
	m_ctrSearch.InsertColumn(7,"教工岗位");
    m_ctrSearch.SetColumnWidth(7,90);
	m_ctrSearch.InsertColumn(8,"民族");
    m_ctrSearch.SetColumnWidth(8,80);
	m_ctrSearch.InsertColumn(9,"学历");
    m_ctrSearch.SetColumnWidth(9,90);
	m_ctrSearch.InsertColumn(10,"政治面貌");
    m_ctrSearch.SetColumnWidth(10,100);
	m_ctrSearch.InsertColumn(11,"身份证号");
    m_ctrSearch.SetColumnWidth(11,80);
	m_ctrSearch.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
    CString strSQL;
	//院系部门
	CDepartmentSectionSet DSS;
	strSQL = "select * from department";
	if(! DSS.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
	     MessageBox("打开数据库失败！","数据库错误",MB_OK);
	} 
	while(! DSS.IsEOF())
	{
		 m_ctrUnit.AddString(DSS.m_division);
		 DSS.MoveNext();
	}
	DSS.Close();
	//行政职务
	CAdministrativePostSet APS;
	strSQL = "select * from administrativePost";
	if(! APS.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
	     MessageBox("打开数据库失败！","数据库错误",MB_OK);
	} 
	while(! APS.IsEOF())
	{
		 m_ctrPost.AddString(APS.m_rank);
		 APS.MoveNext();
	}
	APS.Close();
	//教工职称
	CTechnicalPostSet TPS;
	strSQL = "select * from technicalPost";
	if(! TPS.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
	     MessageBox("打开数据库失败！","数据库错误",MB_OK);
	} 
	while(! TPS.IsEOF())
	{
		 m_ctrTechnical.AddString(TPS.m_title);
		 TPS.MoveNext();
	}
	TPS.Close();
	//教工岗位
	CPositionInformationSet PIS;
	strSQL = "select * from positionInformation";
	if(! PIS.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
	     MessageBox("打开数据库失败！","数据库错误",MB_OK);
	} 
	while(! PIS.IsEOF())
	{
		 m_ctrPosition.AddString(PIS.m_post);
		 PIS.MoveNext();
	}
	PIS.Close();
	//民族信息
	CNationInformationSet NIS;
	strSQL = "select * from nationInformation";
	if(! NIS.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
	     MessageBox("打开数据库失败！","数据库错误",MB_OK);
	} 
	while(! NIS.IsEOF())
	{
		 m_ctrNation.AddString(NIS.m_folk);
		 NIS.MoveNext();
	}
	NIS.Close();
    //政治面貌
	CPoliticalStatusSet PSS;
	strSQL = "select * from politicalStatus";
	if(! PSS.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
	     MessageBox("打开数据库失败！","数据库错误",MB_OK);
	} 
	while(! PSS.IsEOF())
	{
		 m_ctrPolitical.AddString(PSS.m_party);
		 PSS.MoveNext();
	}
	PSS.Close();
    //文化程度
	CEducationDegreeSet EDS;
	strSQL = "select * from educationDegree";
	if(! EDS.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
	     MessageBox("打开数据库失败！","数据库错误",MB_OK);
	} 
	while(! EDS.IsEOF())
	{
		 m_ctrEducation.AddString(EDS.m_degree);
		 EDS.MoveNext();
	}
	EDS.Close();
	//添加代码结束
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

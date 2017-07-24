// BaseArchiveDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "BaseArchiveDlg.h"
//添加代码       
#include "DepartmentSectionSet.h"
#include "AdministrativePostSet.h"
#include "EducationDegreeSet.h"
#include "TechnicalPostSet.h"
#include "PositionInformationSet.h"
#include "WageLevelSet.h"
#include "NationInformationSet.h"
#include "PoliticalStatusSet.h"
//添加代码结束
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaseArchiveDlg dialog


CBaseArchiveDlg::CBaseArchiveDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBaseArchiveDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBaseArchiveDlg)
	m_strCode = _T("");
	m_strName = _T("");
	m_strSex = _T("");
	m_tmBirth = 0;
	m_strMarriage = _T("");
	m_strAge = _T("");
	m_strParty = _T("");
	m_strRace = _T("");
	m_strCID = _T("");
	m_tmWorkDate = 0;
	m_strPost = _T("");
	m_strNative = _T("");
	m_tmEntryDate = 0;
	m_strSalary = _T("");
	m_strDegree = _T("");
	m_strDept = _T("");
	m_strTechnical = _T("");
	m_strJob = _T("");
	m_strOfficePhone = _T("");
	m_strMobilePhone = _T("");
	m_strEmail = _T("");
	m_strUniversity = _T("");
	m_strSubject = _T("");
	m_tmGraduate = 0;
	m_strAddress = _T("");
	//添加代码
	m_recordset = NULL;
	//添加代码结束
	//}}AFX_DATA_INIT
}


void CBaseArchiveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBaseArchiveDlg)
	DDX_Control(pDX, IDC_COMBO_JOB, m_ctrJob);
	DDX_Control(pDX, IDC_COMBO_TECHNICAL, m_ctrTechnical);
	DDX_Control(pDX, IDC_COMBO_DEPTMENT, m_ctrDept);
	DDX_Control(pDX, IDC_COMBO_DEGREE, m_ctrDegree);
	DDX_Control(pDX, IDC_COMBO_SALARY, m_ctrSalary);
	DDX_Control(pDX, IDC_COMBO_POST, m_ctrPost);
	DDX_Control(pDX, IDC_COMBO_RACE, m_ctrRace);
	DDX_Control(pDX, IDC_COMBO_PARTY, m_ctrParty);
	DDX_Control(pDX, IDC_EDIT_CODE, m_ctrCode);
	DDX_Text(pDX, IDC_EDIT_CODE, m_strCode);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_CBString(pDX, IDC_COMBO_SEX, m_strSex);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_BIRTH, m_tmBirth);
	DDX_CBString(pDX, IDC_COMBO_MARRYIAGE, m_strMarriage);
	DDX_Text(pDX, IDC_EDIT_AGE, m_strAge);
	DDX_CBString(pDX, IDC_COMBO_PARTY, m_strParty);
	DDX_CBString(pDX, IDC_COMBO_RACE, m_strRace);
	DDX_Text(pDX, IDC_EDIT_CID, m_strCID);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_WORK, m_tmWorkDate);
	DDX_CBString(pDX, IDC_COMBO_POST, m_strPost);
	DDX_Text(pDX, IDC_EDIT_NATIVE, m_strNative);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_ENTRY, m_tmEntryDate);
	DDX_CBString(pDX, IDC_COMBO_SALARY, m_strSalary);
	DDX_CBString(pDX, IDC_COMBO_DEGREE, m_strDegree);
	DDX_CBString(pDX, IDC_COMBO_DEPTMENT, m_strDept);
	DDX_CBString(pDX, IDC_COMBO_TECHNICAL, m_strTechnical);
	DDX_CBString(pDX, IDC_COMBO_JOB, m_strJob);
	DDX_Text(pDX, IDC_EDIT_OPHONE, m_strOfficePhone);
	DDX_Text(pDX, IDC_EDIT_MPHONE, m_strMobilePhone);
	DDX_Text(pDX, IDC_EDIT_EMAIL, m_strEmail);
	DDX_Text(pDX, IDC_EDIT_UNIVERSITY, m_strUniversity);
	DDX_Text(pDX, IDC_EDIT_SUBJECT, m_strSubject);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_GRADUAGE, m_tmGraduate);
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_strAddress);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBaseArchiveDlg, CDialog)
	//{{AFX_MSG_MAP(CBaseArchiveDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseArchiveDlg message handlers

BOOL CBaseArchiveDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//添加代码
	CString strSQL;
	//院系部门
	CDepartmentSectionSet DSS;
	strSQL = "select * from departmentSection";
	if(! DSS.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
	    MessageBox("打开数据库失败！","数据库错误",MB_OK);
	} 
	while(! DSS.IsEOF())
	{
		m_ctrDept.AddString(DSS.m_division);
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
		m_ctrJob.AddString(APS.m_rank);
		APS.MoveNext();
	}
	APS.Close();
	//职称类别
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
		m_ctrPost.AddString(PIS.m_post);
		PIS.MoveNext();
	}
	PIS.Close();
	//工资等级
	CWageLevelSet WLS;
	strSQL = "select * from wageLevel";
	if(! WLS.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
	    MessageBox("打开数据库失败！","数据库错误",MB_OK);
	} 
	while(! WLS.IsEOF())
	{
		m_ctrSalary.AddString(WLS.m_salary);
		WLS.MoveNext();
	}
	WLS.Close();
	//民族信息
	CNationInformationSet NIS;
	strSQL = "select * from nationInformation";
	if(! NIS.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
	    MessageBox("打开数据库失败！","数据库错误",MB_OK);
	} 
	while(! NIS.IsEOF())
	{
		m_ctrRace.AddString(NIS.m_folk);
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
		m_ctrParty.AddString(PSS.m_party);
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
		m_ctrDegree.AddString(EDS.m_degree);
		EDS.MoveNext();
	}
	EDS.Close();
	//添加代码结束
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CBaseArchiveDlg::Purge()
{
	//添加代码
	m_strCode = "";
	m_strName = "";
	m_strSex = "";
	m_tmBirth = 0;
	m_strMarriage = "";
	m_strAge = "";
	m_strParty = "";
	m_strRace = "";
	m_strCID = "";
	m_tmWorkDate = 0;
	m_strPost = "";
	m_strNative = "";
	m_tmEntryDate = 0;
	m_strSalary = "";
	m_strDegree = "";
	m_strDept = "";
	m_strTechnical = "";
	m_strJob = "";
	m_strOfficePhone = "";
	m_strMobilePhone = "";
	m_strEmail = "";
	m_strUniversity = "";
	m_strSubject = "";
	m_tmGraduate = 0;
	m_strAddress = "";
	UpdateData(FALSE);
	//添加代码结束
}

BOOL CBaseArchiveDlg::Update()
{
	//添加代码
	UpdateData();
    if(m_strCode == "")
	{
		MessageBox("教工编号不能为空，请输入教工编号！");
		return FALSE;
	}
	if(m_strName == "")
	{
		MessageBox("姓名不能为空，请输入姓名！");
		return FALSE;
	}
	CString strSQL;
    strSQL.Format("select * from staff where code ='%s'", m_strCode);
    if(!m_recordset ->Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
        MessageBox("打开数据库失败!","数据库错误",MB_OK);
        return FALSE;
    }
	if(m_recordset ->GetRecordCount() == 0)
	{
		MessageBox("该教工不存在！");
		m_recordset ->Close();
		return FALSE;
	}
	m_recordset ->Edit();
	//教工编号不变，不予修改
	m_recordset ->m_address        = m_strAddress;     //家庭住址
	m_recordset ->m_age            = atoi(m_strAge);   //年龄
	m_recordset ->m_identity_Card  = m_strCID;         //身份证号
	m_recordset ->m_degree         = m_strDegree;      //文化程度
	m_recordset ->m_department     = m_strDept;        //院系部门
	m_recordset ->m_email          = m_strEmail;       //电子邮箱
	m_recordset ->m_job            = m_strJob;         //职务
	m_recordset ->m_marriage       = m_strMarriage;    //婚姻状况
	m_recordset ->m_mobile_Phone   = m_strMobilePhone; //手机
	m_recordset ->m_name           = m_strName;        //姓名
	m_recordset ->m_native         = m_strNative;      //籍贯
	m_recordset ->m_office_Phone   = m_strOfficePhone; //办公电话
	m_recordset ->m_party          = m_strParty;       //政治面貌
	m_recordset ->m_post           = m_strPost;        //教工岗位
	m_recordset ->m_race           = m_strRace;        //民族
	m_recordset ->m_salary         = m_strSalary;      //工资等级
	m_recordset ->m_sex            = m_strSex;         //性别
	m_recordset ->m_subject        = m_strSubject;     //所学专业
	m_recordset ->m_technical      = m_strTechnical;   //职称
	m_recordset ->m_university     = m_strUniversity;  //毕业学校
	m_recordset ->m_birth          = m_tmBirth;        //生日
	m_recordset ->m_word_Date      = m_tmWorkDate;     //参加工作时间
	m_recordset ->m_enty_Date      = m_tmEntryDate;    //入职时间
	m_recordset ->m_graduate_Date  = m_tmGraduate;     //毕业时间
	m_recordset ->Update();
	m_recordset ->Close();
	return TRUE;
	//添加代码结束
}

void CBaseArchiveDlg::DataUpdate()
{
    //添加代码
	CString strSQL;
    strSQL.Format("select * from staff where code = '%s'",m_strCode);
    if(! m_recordset ->Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
	    MessageBox("打开数据库失败！","数据库错误",MB_OK);
	    return;
    }
	//建立一个20个字符长的缓冲存储年龄age
char buffer[20];
    //将年龄age的整型转换为字符串
	_itoa(m_recordset ->m_age,buffer,10);
    m_strAge  = buffer;
	m_strAddress       = m_recordset ->m_address;           //家庭住址
	m_strCID           = m_recordset ->m_identity_Card  ;    //身份证号
	m_strDegree        = m_recordset ->m_degree;             //文化程度
	m_strDept          = m_recordset ->m_department;         //院系部门
	m_strEmail         = m_recordset ->m_email;              //电子邮箱
	m_strJob           = m_recordset ->m_job;                //职务
	m_strMarriage      = m_recordset ->m_marriage;           //婚姻状况
	m_strMobilePhone   = m_recordset ->m_mobile_Phone;       //手机
	m_strName          = m_recordset ->m_name;               //姓名
	m_strNative        = m_recordset ->m_native;             //籍贯
	m_strOfficePhone   = m_recordset ->m_office_Phone;       //办公电话
	m_strParty         = m_recordset ->m_party;              //政治面貌
	m_strPost          = m_recordset ->m_post;               //教工岗位
	m_strRace          = m_recordset ->m_race;               //民族
	m_strSalary        = m_recordset ->m_salary;             //工资等级
	m_strSex           = m_recordset ->m_sex;                //性别
	m_strSubject       = m_recordset ->m_subject;            //所学专业
	m_strTechnical     = m_recordset ->m_technical;          //职称
	m_strUniversity    = m_recordset ->m_university;         //毕业学校
	m_tmBirth          = m_recordset ->m_birth;              //生日
	m_tmWorkDate       = m_recordset ->m_word_Date;          //参加工作时间
	m_tmEntryDate      = m_recordset ->m_enty_Date;          //入职时间
	m_tmGraduate       = m_recordset ->m_graduate_Date;      //毕业时间
	m_recordset ->Close();
	UpdateData(FALSE); 
	//添加代码结束
}

BOOL CBaseArchiveDlg::Save()
{
    //添加代码 
	UpdateData();
	if(m_strCode == "")
	{
		MessageBox("教工编号不能为空，请输入教工编号！");
		return FALSE; 
	}
	if(m_strName == "")
	{
		MessageBox("姓名不能为空，请输入姓名!");
		return FALSE; 
	}
	CString strSQL;
    strSQL.Format("select * from staff where code = '%s'",m_strCode);
    if(! m_recordset ->Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
	    MessageBox("打开数据库失败！","数据库错误",MB_OK);
	    return FALSE;
    }
	if(m_recordset ->GetRecordCount() != 0)
	{
		MessageBox("该教工已经存在！");
		m_recordset ->Close();
		return FALSE; 
	}
	m_recordset ->AddNew();
	m_recordset ->m_code           = m_strCode;        //教工编号
	m_recordset ->m_address        = m_strAddress;     //家庭住址
	m_recordset ->m_age            = atoi(m_strAge);   //年龄
	m_recordset ->m_identity_Card  = m_strCID;         //身份证号
	m_recordset ->m_degree         = m_strDegree;      //文化程度
	m_recordset ->m_department     = m_strDept;        //院系部门
	m_recordset ->m_email          = m_strEmail;       //电子邮箱
	m_recordset ->m_job            = m_strJob;         //职务
	m_recordset ->m_marriage       = m_strMarriage;    //婚姻状况
	m_recordset ->m_mobile_Phone   = m_strMobilePhone; //手机
	m_recordset ->m_name           = m_strName;        //姓名
	m_recordset ->m_native         = m_strNative;      //籍贯
	m_recordset ->m_office_Phone   = m_strOfficePhone; //办公电话
	m_recordset ->m_party          = m_strParty;       //政治面貌
	m_recordset ->m_post           = m_strPost;        //教工岗位
	m_recordset ->m_race           = m_strRace;        //民族
	m_recordset ->m_salary         = m_strSalary;      //工资等级
	m_recordset ->m_sex            = m_strSex;         //性别
	m_recordset ->m_subject        = m_strSubject;     //所学专业
	m_recordset ->m_technical      = m_strTechnical;   //职称
	m_recordset ->m_university     = m_strUniversity;  //毕业学校
	m_recordset ->m_birth          = m_tmBirth;        //生日
	m_recordset ->m_word_Date      = m_tmWorkDate;     //参加工作时间
	m_recordset ->m_enty_Date      = m_tmEntryDate;    //入职时间
	m_recordset ->m_graduate_Date  = m_tmGraduate;     //毕业时间
	m_recordset ->Update();
	m_recordset ->Close();
	return true;
	//添加代码结束
}

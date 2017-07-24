// BrowseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "BrowseDlg.h"
//添加代码
//增加系统第2个菜单基础数据信息对应的8个数据集类
#include "NationInformationSet.h"
#include "positionInformationSet.h"
#include "educationDegreeSet.h"
#include "politicalStatusSet.h"
#include "departmentSectionSet.h"
#include "wageLevelSet.h"
#include "technicalPostSet.h"
#include "administrativePostSet.h"
//添加代码结束
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBrowseDlg dialog


CBrowseDlg::CBrowseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBrowseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBrowseDlg)
	m_iCondition = -1;
	m_strContent = _T("");
	m_strCode = _T("");
	m_strName = _T("");
	//添加代码
	m_bNew = FALSE;
	//添加代码结束
	//}}AFX_DATA_INIT
}


void CBrowseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBrowseDlg)
	DDX_Control(pDX, IDC_LIST_BROWSE, m_ctrContain);
	DDX_Control(pDX, IDC_TAB_BROWSE, m_ctrContainer);
	DDX_Control(pDX, IDC_COMBO_CONTENT, m_ctrContent);
	DDX_Control(pDX, IDC_COMBO_CONDITION, m_ctrCondition);
	DDX_Control(pDX, IDC_BUTTON_CANCEL, m_bntCancel);
	DDX_Control(pDX, IDC_BUTTON_SAVE, m_bntSave);
	DDX_Control(pDX, IDC_BUTTON_UPDATE, m_bntUpdate);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_bntDelete);
	DDX_Control(pDX, IDC_BUTTON_ADD, m_bntAdd);
	DDX_CBIndex(pDX, IDC_COMBO_CONDITION, m_iCondition);
	DDX_CBString(pDX, IDC_COMBO_CONTENT, m_strContent);
	DDX_Text(pDX, IDC_EDIT_CODE, m_strCode);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBrowseDlg, CDialog)
	//{{AFX_MSG_MAP(CBrowseDlg)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, OnButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	ON_NOTIFY(NM_CLICK, IDC_LIST_BROWSE, OnClickListBrowse)
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_CBN_EDITUPDATE(IDC_COMBO_CONTENT, OnEditupdateComboContent)
	ON_CBN_SELCHANGE(IDC_COMBO_CONTENT, OnSelchangeComboContent)
	ON_CBN_SELCHANGE(IDC_COMBO_CONDITION, OnSelchangeComboCondition)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_BROWSE, OnSelchangeTabBrowse)
	ON_NOTIFY(TCN_SELCHANGING, IDC_TAB_BROWSE, OnSelchangingTabBrowse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBrowseDlg message handlers

void CBrowseDlg::OnButtonCancel() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	m_bntAdd.EnableWindow(TRUE);
	m_bntDelete.EnableWindow(TRUE);
	m_bntSave.EnableWindow(FALSE);
	m_bntCancel.EnableWindow(FALSE);
	m_bntUpdate.EnableWindow(TRUE);
	m_bNew = FALSE;
	//添加代码结束
}

void CBrowseDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	int i = m_ctrContain.GetSelectionMark();
    if(i<0)
    {
        MessageBox("亲，请选择一个教工进行删除！");
        return;
    }
    CString strSQL;
	//教工编号在初始化函数中设置为第1位
    strSQL.Format("select * from staff where code = %s",m_ctrContain.GetItemText(i,0));
    if(! m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
         MessageBox("打开数据库失败！","数据库错误",MB_OK);
         return ;
    }
	//删除该教工
	m_recordset.Delete();
	m_recordset.Close();
	//更新教工列表
	strSQL = "select * from staff";
	DataUpdate(strSQL);
	//清空对话框IDD_DIALOG_BROWSE当前记录信息
	m_strCode = "";
	m_strName = "";
	UpdateData(FALSE);
	//清空教工档案当前记录信息
	m_pBaseArchiveDlg.Purge();
	//清空其他10个子模块当前记录信息
	m_pFamilyMemberDlg.DataUpdate(m_strCode);
	m_pAcademicEducationDlg.DataUpdate(m_strCode);
	m_pClassTeachingDlg.DataUpdate(m_strCode);
	m_pContinueEducationDlg.DataUpdate(m_strCode);
	m_pDisciplinePunishDlg.DataUpdate(m_strCode);
	m_pPaperDlg.DataUpdate(m_strCode);
	m_pProjectDlg.DataUpdate(m_strCode);
	m_pRewardRecordDlg.DataUpdate(m_strCode);
	m_pTechnicalAccessDlg.DataUpdate(m_strCode);
	m_pWorkExperienceDlg.DataUpdate(m_strCode);
	//添加代码结束
}

void CBrowseDlg::OnButtonUpdate() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	if(! m_pBaseArchiveDlg.Update())
		return;
	m_pBaseArchiveDlg.DataUpdate();
	//更新对话框IDD_DIALOG_BROWSE当前记录信息
	m_strName = m_pBaseArchiveDlg.m_strName;
	m_strCode = m_pBaseArchiveDlg.m_strCode;
	UpdateData(FALSE);
	//更新对话框IDD_DIALOG_BROWSE列表上当前记录信息
	CString strSQL;
	strSQL = "select * from staff";
	DataUpdate(strSQL);
	//更新其余10个子模块的信息
	m_pFamilyMemberDlg.DataUpdate(m_strCode);
	m_pAcademicEducationDlg.DataUpdate(m_strCode);
	m_pClassTeachingDlg.DataUpdate(m_strCode);
	m_pContinueEducationDlg.DataUpdate(m_strCode);
	m_pDisciplinePunishDlg.DataUpdate(m_strCode);
	m_pPaperDlg.DataUpdate(m_strCode);
	m_pProjectDlg.DataUpdate(m_strCode);
	m_pRewardRecordDlg.DataUpdate(m_strCode);
	m_pTechnicalAccessDlg.DataUpdate(m_strCode);
	m_pWorkExperienceDlg.DataUpdate(m_strCode);
	//添加代码结束
}

void CBrowseDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	//选择教工档案子模块
	m_ctrContainer.SetCurSel(0);
	//首先清空教工档案子模块中的数据
	m_pBaseArchiveDlg.Purge();
	//其次激活教工档案子模块教工编号编辑框的可编辑状态
	m_pBaseArchiveDlg.m_ctrCode.EnableWindow();
	//再次设置对话框IDD_DIALOG_BROWSE的各个按钮状态
	m_bntAdd.EnableWindow(FALSE);
	m_bntDelete.EnableWindow(FALSE);
	m_bntSave.EnableWindow(TRUE);
	m_bntCancel.EnableWindow(TRUE);
	m_bntUpdate.EnableWindow(FALSE);
	m_bNew = TRUE;   //添加新教工的布尔变量为真
	//添加代码结束
}

void CBrowseDlg::OnButtonSave() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	if(! m_pBaseArchiveDlg.Save())
		return;
	m_pBaseArchiveDlg.DataUpdate();
	m_pBaseArchiveDlg.m_ctrCode.EnableWindow(FALSE);
	//设置对话框IDD_DIALOG_BROWSE中各个按钮的状态
	m_bntAdd.EnableWindow(TRUE);
	m_bntDelete.EnableWindow(TRUE);
	m_bntSave.EnableWindow(FALSE);
	m_bntCancel.EnableWindow(FALSE);
	m_bntUpdate.EnableWindow(TRUE);
	m_bNew = FALSE;    //添加新教工的布尔变量为假
	//更新对话框IDD_DIALOG_BROWSE上当前记录信息
	m_strName = m_pBaseArchiveDlg.m_strName;
	m_strCode = m_pBaseArchiveDlg.m_strCode;
	UpdateData(FALSE);
	//更新对话框IDD_DIALOG_BROWSE列表信息
	CString strSQL;
	strSQL = "select * from staff";
	DataUpdate(strSQL);
	//同时更新其余各子模块的信息
	m_pFamilyMemberDlg.DataUpdate(m_strCode);
	m_pAcademicEducationDlg.DataUpdate(m_strCode);
	m_pClassTeachingDlg.DataUpdate(m_strCode);
	m_pContinueEducationDlg.DataUpdate(m_strCode);
	m_pDisciplinePunishDlg.DataUpdate(m_strCode);
	m_pPaperDlg.DataUpdate(m_strCode);
	m_pProjectDlg.DataUpdate(m_strCode);
	m_pRewardRecordDlg.DataUpdate(m_strCode);
	m_pTechnicalAccessDlg.DataUpdate(m_strCode);
	m_pWorkExperienceDlg.DataUpdate(m_strCode);
	//添加代码结束
}

void CBrowseDlg::OnButtonSearch() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	UpdateData(TRUE);
	if(m_iCondition < 0)
	{
		MessageBox("亲，请您选择一个具体的查询条件！");
		m_ctrCondition.SetFocus();
		return;
	}
	if(m_strContent == "")
	{
		MessageBox("亲，请您输入具体的查询内容！");
		m_ctrContent.SetFocus();
		return;
	}
	CString strSQL;
	//按院系部门查询
	if(m_iCondition == 0)
	{
		strSQL.Format("select * from staff where department = %s",m_strContent);
		DataUpdate(strSQL);
	}
	//按行政职务查询
	else if(m_iCondition == 1)
	{
		strSQL.Format("select * from staff where job = %s",m_strContent);
		DataUpdate(strSQL);
	}
	//按职称类别查询
	else if(m_iCondition == 2)
	{
		strSQL.Format("select * from staff where technical = %s",m_strContent);
		DataUpdate(strSQL);
	}
	//按教工岗位查询
	else if(m_iCondition == 3)
	{
		strSQL.Format("select * from staff where post = %s",m_strContent);
		DataUpdate(strSQL);
	}
	//按工资等级查询
	else if(m_iCondition == 4)
	{
		strSQL.Format("select * from staff where salary = %s",m_strContent);
		DataUpdate(strSQL);
	}
	//按教工性别查询
	else if(m_iCondition == 5)
	{
		strSQL.Format("select * from staff where sex = %s",m_strContent);
		DataUpdate(strSQL);
	}
	//按婚姻状况查询
	else if(m_iCondition == 6)
	{
		strSQL.Format("select * from staff where marriage = %s",m_strContent);
		DataUpdate(strSQL);
	}
	//按民族信息查询
	else if(m_iCondition == 7)
	{
		strSQL.Format("select * from staff where race = %s",m_strContent);
		DataUpdate(strSQL);
	}
	//按政治面貌查询
	else if(m_iCondition == 8)
	{
		strSQL.Format("select * from staff where party = %s",m_strContent);
		DataUpdate(strSQL);
	}
	//按文化程度查询
	else if(m_iCondition == 9)
	{
		strSQL.Format("select * from staff where degree = %s",m_strContent);
		DataUpdate(strSQL);
	}
	//设置对话框IDD_DIALOG_BROWSE上各个按钮的状态
	m_bntAdd.EnableWindow(TRUE);
	m_bntDelete.EnableWindow(TRUE);
	m_bntSave.EnableWindow(FALSE);
	m_bntCancel.EnableWindow(FALSE);
	m_bntUpdate.EnableWindow(TRUE);
	m_bNew = FALSE;   //布尔真值为假
	//教工档案子模块中教工编号编辑框变为不可编辑状态
	m_pBaseArchiveDlg.m_ctrCode.EnableWindow(FALSE);
	//添加代码结束
}

void CBrowseDlg::OnClickListBrowse(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	//添加代码
	int i = m_ctrContain.GetSelectionMark();
	m_strCode = m_ctrContain.GetItemText(i,0);  //编号为第1位
	m_strName = m_ctrContain.GetItemText(i,1);  //姓名为第2位
	m_pBaseArchiveDlg.m_strCode = m_strCode;
	m_pBaseArchiveDlg.DataUpdate();
	UpdateData(FALSE);
    //设置主模块对话框中各个按钮的状态
	m_bntAdd.EnableWindow(TRUE);
	m_bntDelete.EnableWindow(TRUE);
	m_bntSave.EnableWindow(FALSE);
	m_bntCancel.EnableWindow(FALSE);
	m_bntUpdate.EnableWindow(TRUE);
	m_bNew = FALSE;   //逻辑真值为假
	//教工档案子模块中的工号编辑状态关闭
    m_pBaseArchiveDlg.m_ctrCode.EnableWindow(FALSE);
	//更新各子模块的信息
	m_pFamilyMemberDlg.DataUpdate(m_strCode);
	m_pAcademicEducationDlg.DataUpdate(m_strCode);
	m_pClassTeachingDlg.DataUpdate(m_strCode);
	m_pContinueEducationDlg.DataUpdate(m_strCode);
	m_pDisciplinePunishDlg.DataUpdate(m_strCode);
	m_pPaperDlg.DataUpdate(m_strCode);
	m_pProjectDlg.DataUpdate(m_strCode);
	m_pRewardRecordDlg.DataUpdate(m_strCode);
	m_pTechnicalAccessDlg.DataUpdate(m_strCode);
	m_pWorkExperienceDlg.DataUpdate(m_strCode);
	//添加代码结束
	*pResult = 0;
}

void CBrowseDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnClose();
}

void CBrowseDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	
}

BOOL CBrowseDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//添加代码
	m_ctrContain.InsertColumn(0,"工号");
	m_ctrContain.SetColumnWidth(0,80);
	m_ctrContain.InsertColumn(1,"姓名");
	m_ctrContain.SetColumnWidth(1,80);
	m_ctrContain.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	CString strSQL;
	strSQL = "select * from staff";
	DataUpdate(strSQL);
	//在主模块的Tab控件标签页上添加11个子模块
	m_ctrContainer.AddModel("教工档案",&m_pBaseArchiveDlg,IDD_HUMAN_HBASEARCHIVE);
	m_ctrContainer.AddModel("家庭成员",&m_pFamilyMemberDlg,IDD_DIALOG_HFAMILYMEMBER);
	m_ctrContainer.AddModel("工作经历",&m_pWorkExperienceDlg,IDD_DIALOG_HWORKEXPERIENCE);
	m_ctrContainer.AddModel("奖励记录",&m_pRewardRecordDlg,IDD_DIALOG_HREWARDRECORD);
	m_ctrContainer.AddModel("违纪处罚",&m_pDisciplinePunishDlg,IDD_DIALOG_HDISCIPLINEPUNISH);
	m_ctrContainer.AddModel("论文成果",&m_pPaperDlg,IDD_DIALOG_HPAPER);
	m_ctrContainer.AddModel("项目成果",&m_pProjectDlg,IDD_DIALOG_HPROJECT);
	m_ctrContainer.AddModel("职称评定",&m_pTechnicalAccessDlg,IDD_DIALOG_HTECHNICALACCESS);
	m_ctrContainer.AddModel("学历教育",&m_pAcademicEducationDlg,IDD_DIALOG_HACADEMICEDUCATION);
	m_ctrContainer.AddModel("继续教育",&m_pContinueEducationDlg,IDD_DIALOG_HCONTINUEEDUCATION);
	m_ctrContainer.AddModel("课堂教学",&m_pClassTeachingDlg,IDD_DIALOG_HCLASSTEACHING);
	m_ctrContainer.Display();
	//添加代码结束
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CBrowseDlg::OnEditupdateComboContent() 
{
	// TODO: Add your control notification handler code here
	
}

void CBrowseDlg::OnSelchangeComboContent() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	m_bntAdd.EnableWindow(TRUE);
	m_bntDelete.EnableWindow(TRUE);
	m_bntSave.EnableWindow(FALSE);
	m_bntCancel.EnableWindow(FALSE);
	m_bntUpdate.EnableWindow(TRUE);
	m_bNew = FALSE;  
    m_pBaseArchiveDlg.m_ctrCode.EnableWindow(FALSE);
	//添加代码结束
}

void CBrowseDlg::OnSelchangeComboCondition() 
{
	// TODO: Add your control notification handler code here
	//添加代码
    UpdateData();
	CString strSQL;
	//清空主模块查询组框中组合框IDC_COMBO_CONTENT的内容
	int total = m_ctrContent.GetCount();
	for(int i = 0;i < total;i++)
	{
		m_ctrContent.DeleteString(0);
	}
	//与组合框IDC_COMBO_CONDITION对应，完成用户查询
	//按院系部门查询
	if(m_iCondition == 0)
	{
		CDepartmentSectionSet DSS;
	    strSQL = "select * from departmentSection";
	    if(! DSS.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
		{
	        MessageBox("打开数据库失败！","数据库错误",MB_OK);
			return;
		} 
	    while(! DSS.IsEOF())
		{
		    m_ctrContent.AddString(DSS.m_division);
		    DSS.MoveNext();
		}
	    DSS.Close();
	}
	//按行政职务查询
	else if(m_iCondition == 1)
	{
		CAdministrativePostSet APS;
	    strSQL = "select * from administrativePost";
	    if(! APS.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
		{
	        MessageBox("打开数据库失败！","数据库错误",MB_OK);
			return;
		} 
	    while(! APS.IsEOF())
		{
		    m_ctrContent.AddString(APS.m_rank);
		    APS.MoveNext();
		}
	    APS.Close();
	}
	//按职称类别查询
	else if(m_iCondition == 2)
	{
		CTechnicalPostSet TPS;
	    strSQL = "select * from technicalPost";
	    if(! TPS.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
		{
	        MessageBox("打开数据库失败！","数据库错误",MB_OK);
			return;
		} 
	    while(! TPS.IsEOF())
		{
		    m_ctrContent.AddString(TPS.m_title);
		    TPS.MoveNext();
		}
	    TPS.Close();
	}
	//按教工岗位查询
	else if(m_iCondition == 3)
	{
		CPositionInformationSet PIS;
	    strSQL = "select * from positionInformation";
	    if(! PIS.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
		{
	        MessageBox("打开数据库失败！","数据库错误",MB_OK);
			return;
		} 
	    while(! PIS.IsEOF())
		{
		    m_ctrContent.AddString(PIS.m_post);
		    PIS.MoveNext();
		}
	    PIS.Close();
	}
	//按工资等级查询
	else if(m_iCondition == 4)
	{
		CWageLevelSet WLS;
	    strSQL = "select * from wageLevel";
	    if(! WLS.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
		{
	        MessageBox("打开数据库失败！","数据库错误",MB_OK);
			return;
		} 
	    while(! WLS.IsEOF())
		{
		    m_ctrContent.AddString(WLS.m_salary);
		    WLS.MoveNext();
		}
	    WLS.Close();
	}
	//按教工性别查询
	else if(m_iCondition == 5)
	{
		m_ctrContent.AddString("男");
		m_ctrContent.AddString("女");
	}
	//按婚姻状况查询
	else if(m_iCondition == 6)
	{
		m_ctrContent.AddString("未婚");
		m_ctrContent.AddString("已婚");
	}
	//按民族信息查询
	else if(m_iCondition == 7)
	{
		CNationInformationSet NIS;
	    strSQL = "select * from nationInformation";
	    if(! NIS.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
		{
	        MessageBox("打开数据库失败！","数据库错误",MB_OK);
			return;
		} 
	    while(! NIS.IsEOF())
		{
		    m_ctrContent.AddString(NIS.m_folk);
		    NIS.MoveNext();
		}
	    NIS.Close();
	}
	//按政治面貌查询
	else if(m_iCondition == 8)
	{
		CPoliticalStatusSet PSS;
	    strSQL = "select * from politicalStatus";
	    if(! PSS.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
		{
	        MessageBox("打开数据库失败！","数据库错误",MB_OK);
			return;
		} 
	    while(! PSS.IsEOF())
		{
		    m_ctrContent.AddString(PSS.m_party);
		    PSS.MoveNext();
		}
	    PSS.Close();
	}
	//按文化程度查询
	else if(m_iCondition == 9)
	{
		CEducationDegreeSet EDS;
	    strSQL = "select * from educationDegree";
	    if(! EDS.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
		{
	        MessageBox("打开数据库失败！","数据库错误",MB_OK);
			return;
		} 
	    while(! EDS.IsEOF())
		{
		    m_ctrContent.AddString(EDS.m_degree);
		    EDS.MoveNext();
		}
	    EDS.Close();
	}
	//设置主模块中各个按钮的状态
	m_bntAdd.EnableWindow(TRUE);
	m_bntDelete.EnableWindow(TRUE);
	m_bntSave.EnableWindow(FALSE);
	m_bntCancel.EnableWindow(FALSE);
	m_bntUpdate.EnableWindow(TRUE);
	m_bNew = FALSE;   //程序逻辑真值为假
    m_pBaseArchiveDlg.m_ctrCode.EnableWindow(FALSE);
	//添加代码结束
}

void CBrowseDlg::OnSelchangeTabBrowse(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	//添加代码
	if(m_bNew)
	{
		m_ctrContainer.SetCurSel(1);
		m_ctrContainer.SetCurSel(0);
		m_ctrContainer.UpdateWindow();
		*pResult = 0;
		return;
	}
	//添加代码结束
	*pResult = 0;
}

void CBrowseDlg::OnSelchangingTabBrowse(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CBrowseDlg::DataUpdate(CString strSQL)
{
    //添加代码
	m_ctrContain.DeleteAllItems();
	m_ctrContain.SetRedraw(FALSE);
	UpdateData(TRUE);
	if(! m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
         MessageBox("打开数据库失败！","数据库错误",MB_OK);
         return ;
    }
	int i = 0;
	while(!m_recordset.IsEOF())
	{
		m_ctrContain.InsertItem(i,m_recordset.m_code);
		m_ctrContain.SetItemText(i++,1,m_recordset.m_name);
		m_recordset.MoveNext();
	}
	m_recordset.Close();
	m_ctrContain.SetRedraw(TRUE);
	//添加代码结束
}

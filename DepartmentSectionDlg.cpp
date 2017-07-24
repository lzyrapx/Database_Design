// DepartmentSectionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "DepartmentSectionDlg.h"
// 添加代码
#include "AddBaseInfoDlg.h"
// 添加代码结束
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDepartmentSectionDlg dialog


CDepartmentSectionDlg::CDepartmentSectionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDepartmentSectionDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDepartmentSectionDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDepartmentSectionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDepartmentSectionDlg)
	DDX_Control(pDX, IDC_LIST_DEPARTMENTSECTION, m_ctrDivision);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDepartmentSectionDlg, CDialog)
	//{{AFX_MSG_MAP(CDepartmentSectionDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDepartmentSectionDlg message handlers

void CDepartmentSectionDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
    // 添加代码
    // 调用添加信息的公用模块
    CAddBaseInfoDlg abid;
    abid.m_strLabel = " 院系部门： ";
    abid.m_strInformation = "单位：";
    if(abid.DoModal()!=IDOK)
    return;
    CString strSQL;
    strSQL.Format("select * from departmentSection where division='%s'",abid.m_strData);
    if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
        MessageBox("打开数据库失败!","数据库错误",MB_OK);
        return ;
    }
    // 判断用户添加的院系部门是否已经存在数据库中
    if(m_recordset.GetRecordCount()!=0)
    {
        m_recordset.Close();
        MessageBox("该单位已经存在！");
        return;
    }
    // 添加新的院系部门
    m_recordset.AddNew();
    m_recordset.m_division = abid.m_strData;
    m_recordset.m_description = abid.m_strDescription;
    m_recordset.Update();
    m_recordset.Close();
    DataUpdate();
    // 添加代码结束	
}

void CDepartmentSectionDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
    // 添加代码
    UpdateData(TRUE);
    int i = m_ctrDivision.GetSelectionMark();
    if(i<0)
    {
        MessageBox("请选择一个用户！");
        return;
    }
    CString strSQL;
    strSQL.Format("select * from departmentSection where division='%s'",  m_ctrDivision.GetItemText(i,1));
    if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
        MessageBox("打开数据库失败!","数据库错误",MB_OK);
        return ;
    }
    // 删除该用户
    m_recordset.Delete();
    m_recordset.Close();
    DataUpdate();
    // 添加代码结束	
}

BOOL CDepartmentSectionDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
    // 添加代码
    // 初始化院系部门对话框中的列表控件表头
    m_ctrDivision.InsertColumn(0,"序号");
    m_ctrDivision.SetColumnWidth(0,40);
    m_ctrDivision.InsertColumn(1,"单位");
    m_ctrDivision.SetColumnWidth(1,60);
    m_ctrDivision.InsertColumn(2,"描述");
    m_ctrDivision.SetColumnWidth(2,80);
    m_ctrDivision.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
    DataUpdate();
    // 添加代码结束	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDepartmentSectionDlg::DataUpdate()
{
    // 添加代码
    m_ctrDivision.SetFocus();
    m_ctrDivision.DeleteAllItems();
    m_ctrDivision.SetRedraw(FALSE);
    CString strSQL;
    char  buffer[20];
    UpdateData(TRUE);
    strSQL="select * from departmentSection";
    if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
         MessageBox("打开数据库失败!","数据库错误",MB_OK);
         return ;
    }
    int i=0;
    while(!m_recordset.IsEOF())
   {
        ltoa(m_recordset.m_ID,buffer,10);
    m_ctrDivision.InsertItem(i,buffer);
    m_ctrDivision.SetItemText(i,1,m_recordset.m_division);
    m_ctrDivision.SetItemText(i,2,m_recordset.m_description);
    i++;
    m_recordset.MoveNext();
    }
    m_recordset.Close();
    m_ctrDivision.SetRedraw(TRUE);
    // 添加代码结束
}

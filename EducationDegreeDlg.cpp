// EducationDegreeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "EducationDegreeDlg.h"
// 添加代码
#include "AddBaseInfoDlg.h"
// 添加代码结束
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEducationDegreeDlg dialog


CEducationDegreeDlg::CEducationDegreeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEducationDegreeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEducationDegreeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEducationDegreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEducationDegreeDlg)
	DDX_Control(pDX, IDC_LIST_EDUCATIONDEGREE, m_ctrDegree);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEducationDegreeDlg, CDialog)
	//{{AFX_MSG_MAP(CEducationDegreeDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEducationDegreeDlg message handlers

void CEducationDegreeDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
    // 调用添加信息的公用模块
    CAddBaseInfoDlg abid;
    abid.m_strLabel = " 文化程度： ";
    abid.m_strInformation = "学历：";
    if(abid.DoModal()!=IDOK)
         return;
    CString strSQL;
    strSQL.Format("select * from educationDegree where degree='%s'",abid.m_strData);
    if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
         MessageBox("打开数据库失败!","数据库错误",MB_OK);
         return ;
	}
    // 判断用户添加的文化程度是否已经存在数据库中
    if(m_recordset.GetRecordCount()!=0)
	{
        m_recordset.Close();
        MessageBox("该学历已经存在！");
        return;
	}
    // 添加新的文化程度
    m_recordset.AddNew();
    m_recordset.m_degree = abid.m_strData;
    m_recordset.m_description = abid.m_strDescription;
    m_recordset.Update();
    m_recordset.Close();
    DataUpdate();
    // 添加代码结束
}

void CEducationDegreeDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
    UpdateData(TRUE);
    int i = m_ctrDegree.GetSelectionMark();
    if(i<0)
	{
         MessageBox("请选择一个用户！");
         return;
	}
    CString strSQL;
    strSQL.Format("select * from educationDegree where degree='%s'",  m_ctrDegree.GetItemText(i,1));
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

BOOL CEducationDegreeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	// 添加代码
    // 初始化文化程度对话框中的列表控件表头
    m_ctrDegree.InsertColumn(0,"序号");
    m_ctrDegree.SetColumnWidth(0,40);
    m_ctrDegree.InsertColumn(1,"学历");
    m_ctrDegree.SetColumnWidth(1,60);
    m_ctrDegree.InsertColumn(2,"描述");
    m_ctrDegree.SetColumnWidth(2,80);
    m_ctrDegree.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
    DataUpdate();
    // 添加代码结束
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEducationDegreeDlg::DataUpdate()
{
    // 添加代码
    m_ctrDegree.SetFocus();
    m_ctrDegree.DeleteAllItems();
    m_ctrDegree.SetRedraw(FALSE);
    CString strSQL;
    char  buffer[20];
    UpdateData(TRUE);
    strSQL="select * from educationDegree";
    if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
         MessageBox("打开数据库失败!","数据库错误",MB_OK);
         return ;
	}
    int i=0;
    while(!m_recordset.IsEOF())
	{
        ltoa(m_recordset.m_ID,buffer,10);
        m_ctrDegree.InsertItem(i,buffer);
        m_ctrDegree.SetItemText(i,1,m_recordset.m_degree);
        m_ctrDegree.SetItemText(i,2,m_recordset.m_description);
        i++;
        m_recordset.MoveNext();
	}
    m_recordset.Close();
    m_ctrDegree.SetRedraw(TRUE);
    // 添加代码结束
}

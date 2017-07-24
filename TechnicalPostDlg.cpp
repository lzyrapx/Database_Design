// TechnicalPostDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "TechnicalPostDlg.h"
// 添加代码
#include "AddBaseInfoDlg.h"
// 添加代码结束
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTechnicalPostDlg dialog


CTechnicalPostDlg::CTechnicalPostDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTechnicalPostDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTechnicalPostDlg)
	//}}AFX_DATA_INIT
}


void CTechnicalPostDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTechnicalPostDlg)
	DDX_Control(pDX, IDC_LIST_TECHNICALPOST, m_ctrTitle);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTechnicalPostDlg, CDialog)
	//{{AFX_MSG_MAP(CTechnicalPostDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTechnicalPostDlg message handlers

void CTechnicalPostDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
    // 添加代码
    // 调用添加信息的公用模块
    CAddBaseInfoDlg abid;
    abid.m_strLabel = " 职称类别： ";
    abid.m_strInformation = "职称：";
    if(abid.DoModal()!=IDOK)
    return;
    CString strSQL;
    strSQL.Format("select * from technicalPost where title='%s'",abid.m_strData);
    if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
        MessageBox("打开数据库失败!","数据库错误",MB_OK);
        return ;
    }
    // 判断用户添加的职称类别是否已经存在数据库中
    if(m_recordset.GetRecordCount()!=0)
    {
        m_recordset.Close();
        MessageBox("该职称已经存在！");
        return;
    }
    // 添加新的职称解绑
    m_recordset.AddNew();
    m_recordset.m_title = abid.m_strData;
    m_recordset.m_description = abid.m_strDescription;
    m_recordset.Update();
    m_recordset.Close();
    DataUpdate();
    // 添加代码结束	
}

void CTechnicalPostDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
    // 添加代码
    UpdateData(TRUE);
    int i = m_ctrTitle.GetSelectionMark();
    if(i<0)
    {
        MessageBox("请选择一个用户！");
        return;
    }
    CString strSQL;
    strSQL.Format("select * from technicalPost where title='%s'",  m_ctrTitle.GetItemText(i,1));
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

BOOL CTechnicalPostDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
    // 添加代码
    // 初始化职称解绑对话框中的列表控件表头
    m_ctrTitle.InsertColumn(0,"序号");
    m_ctrTitle.SetColumnWidth(0,40);
    m_ctrTitle.InsertColumn(1,"职称");
    m_ctrTitle.SetColumnWidth(1,60);
    m_ctrTitle.InsertColumn(2,"描述");
    m_ctrTitle.SetColumnWidth(2,80);
    m_ctrTitle.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
    DataUpdate();
    // 添加代码结束	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTechnicalPostDlg::DataUpdate()
{
    // 添加代码
    m_ctrTitle.SetFocus();
    m_ctrTitle.DeleteAllItems();
    m_ctrTitle.SetRedraw(FALSE);
    CString strSQL;
    char  buffer[20];
    UpdateData(TRUE);
    strSQL="select * from technicalPost";
    if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
        MessageBox("打开数据库失败!","数据库错误",MB_OK);
    return ;
    }
    int i=0;
    while(!m_recordset.IsEOF())
    {
        ltoa(m_recordset.m_ID,buffer,10);
        m_ctrTitle.InsertItem(i,buffer);
        m_ctrTitle.SetItemText(i,1,m_recordset.m_title);
        m_ctrTitle.SetItemText(i,2,m_recordset.m_description);
        i++;
        m_recordset.MoveNext();
    }
    m_recordset.Close();
    m_ctrTitle.SetRedraw(TRUE);
    // 添加代码结束
}

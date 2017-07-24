// PoliticalStatusDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "PoliticalStatusDlg.h"
// 添加代码
#include "AddBaseInfoDlg.h"
// 添加代码结束
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPoliticalStatusDlg dialog


CPoliticalStatusDlg::CPoliticalStatusDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPoliticalStatusDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPoliticalStatusDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPoliticalStatusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPoliticalStatusDlg)
	DDX_Control(pDX, IDC_LIST_POLITICALSTATUS, m_ctrParty);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPoliticalStatusDlg, CDialog)
	//{{AFX_MSG_MAP(CPoliticalStatusDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPoliticalStatusDlg message handlers

void CPoliticalStatusDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
    // 添加代码
    // 调用添加信息的公用模块
    CAddBaseInfoDlg abid;
    abid.m_strLabel = " 政治面貌： ";
    abid.m_strInformation = "党派：";
    if(abid.DoModal()!=IDOK)
    return;
    CString strSQL;
    strSQL.Format("select * from politicalStatus where party='%s'",abid.m_strData);
    if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
         MessageBox("打开数据库失败!","数据库错误",MB_OK);
         return ;
    }
    // 判断用户添加的政治面貌是否已经存在数据库中
    if(m_recordset.GetRecordCount()!=0)
    {
         m_recordset.Close();
         MessageBox("该党派已经存在！");
         return;
    }
    // 添加新的政治面貌
    m_recordset.AddNew();
    m_recordset.m_party = abid.m_strData;
    m_recordset.m_description = abid.m_strDescription;
    m_recordset.Update();
    m_recordset.Close();
    DataUpdate();
    // 添加代码结束	
}

void CPoliticalStatusDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
    // 添加代码
    UpdateData(TRUE);
    int i = m_ctrParty.GetSelectionMark();
    if(i<0)
    {
        MessageBox("请选择一个用户！");
        return;
    }
    CString strSQL;
    strSQL.Format("select * from politicalStatus where party='%s'",  m_ctrParty.GetItemText(i,1));
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

BOOL CPoliticalStatusDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
    // 添加代码
    // 初始化政治面貌对话框中的列表控件表头
    m_ctrParty.InsertColumn(0,"序号");
    m_ctrParty.SetColumnWidth(0,40);
    m_ctrParty.InsertColumn(1,"党派");
    m_ctrParty.SetColumnWidth(1,60);    
    m_ctrParty.InsertColumn(2,"描述");
    m_ctrParty.SetColumnWidth(2,80);
    m_ctrParty.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
    DataUpdate();
    // 添加代码结束	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPoliticalStatusDlg::DataUpdate()
{
    // 添加代码
    m_ctrParty.SetFocus();
    m_ctrParty.DeleteAllItems();
    m_ctrParty.SetRedraw(FALSE);
    CString strSQL;
    char  buffer[20];
    UpdateData(TRUE);
    strSQL="select * from politicalStatus";
    if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
    {
         MessageBox("打开数据库失败!","数据库错误",MB_OK);
         return ;
    }
    int i=0;
    while(!m_recordset.IsEOF())
    {
         ltoa(m_recordset.m_ID,buffer,10);
         m_ctrParty.InsertItem(i,buffer);
         m_ctrParty.SetItemText(i,1,m_recordset.m_party);
         m_ctrParty.SetItemText(i,2,m_recordset.m_description);
         i++;
         m_recordset.MoveNext();
    }
    m_recordset.Close();
    m_ctrParty.SetRedraw(TRUE);
    // 添加代码结束
}

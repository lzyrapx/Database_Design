// PositionInformationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "PositionInformationDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPositionInformationDlg dialog


CPositionInformationDlg::CPositionInformationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPositionInformationDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPositionInformationDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPositionInformationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPositionInformationDlg)
	DDX_Control(pDX, IDC_LIST_POSITIONINFORMATON, m_ctrPost);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPositionInformationDlg, CDialog)
	//{{AFX_MSG_MAP(CPositionInformationDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPositionInformationDlg message handlers

void CPositionInformationDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
    // 调用添加信息的公用模块
    CAddBaseInfoDlg abid;
    abid.m_strLabel = " 教工岗位： ";
    abid.m_strInformation = "岗位：";
    if(abid.DoModal()!=IDOK)
    return;
    CString strSQL;
    strSQL.Format("select * from positionInformation where post='%s'",abid.m_strData);
    if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
         MessageBox("打开数据库失败!","数据库错误",MB_OK);
         return ;
	}
    // 判断用户添加的教工岗位是否已经存在数据库中
    if(m_recordset.GetRecordCount()!=0)
	{
        m_recordset.Close();
        MessageBox("该岗位已经存在！");
        return;
	}
    // 添加新的教工岗位
    m_recordset.AddNew();
    m_recordset.m_post = abid.m_strData;
    m_recordset.m_description = abid.m_strDescription;
    m_recordset.Update();
    m_recordset.Close();
    DataUpdate();
    // 添加代码结束
}

void CPositionInformationDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
    UpdateData(TRUE);
    int i = m_ctrPost.GetSelectionMark();
    if(i<0)
	{
         MessageBox("请选择一个用户！");
         return;
	}
    CString strSQL;
    strSQL.Format("select * from positionInformation where post='%s'",\
		m_ctrPost.GetItemText(i,1));
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

BOOL CPositionInformationDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	// 添加代码
    // 初始化教工感悟对话框中的列表控件表头
    m_ctrPost.InsertColumn(0,"序号");
    m_ctrPost.SetColumnWidth(0,40);
    m_ctrPost.InsertColumn(1,"岗位");
    m_ctrPost.SetColumnWidth(1,60);
    m_ctrPost.InsertColumn(2,"描述");
    m_ctrPost.SetColumnWidth(2,80);
    m_ctrPost.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
    DataUpdate();
    // 添加代码结束
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPositionInformationDlg::DataUpdate()
{
    // 添加代码
    m_ctrPost.SetFocus();
    m_ctrPost.DeleteAllItems();
    m_ctrPost.SetRedraw(FALSE);
    CString strSQL;
    char  buffer[20];
    UpdateData(TRUE);
    strSQL="select * from positionInformation";
    if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
         MessageBox("打开数据库失败!","数据库错误",MB_OK);
         return ;
	}
    int i=0;
    while(!m_recordset.IsEOF())
	{
        ltoa(m_recordset.m_ID,buffer,10);
        m_ctrPost.InsertItem(i,buffer);
        m_ctrPost.SetItemText(i,1,m_recordset.m_post);
        m_ctrPost.SetItemText(i,2,m_recordset.m_description);
        i++;
        m_recordset.MoveNext();
	}
    m_recordset.Close();
    m_ctrPost.SetRedraw(TRUE);
    // 添加代码结束
}

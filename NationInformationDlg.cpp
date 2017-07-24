// NationInformationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "NationInformationDlg.h"
//添加代码
#include "AddBaseInfoDlg.h"
//添加代码结束
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNationInformationDlg dialog


CNationInformationDlg::CNationInformationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNationInformationDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNationInformationDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CNationInformationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNationInformationDlg)
	DDX_Control(pDX, IDC_LIST_NATIONINFORMATION, m_ctrNation);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNationInformationDlg, CDialog)
	//{{AFX_MSG_MAP(CNationInformationDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNationInformationDlg message handlers

void CNationInformationDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	//调用添加信息的公用模块
	CAddBaseInfoDlg abid;
	abid.m_strLabel="民族信息:";
	abid.m_strInformation="民族:";
	if(abid.DoModal()!=IDOK)
		return;
	CString strSQL;
	strSQL.Format("select* from nationInformation where folk='%s'",abid.m_strData);
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败！","数据库错误",MB_OK);
		return;
	}
	//判断用户条件的民族信息是否已经存在数据库中
	if(m_recordset.GetRecordCount()!=0)
	{
		m_recordset.Close();
		MessageBox("该民族已经存在！");
		return;
	}
	//添加新的民族信息
	m_recordset.AddNew();
	m_recordset.m_folk=abid.m_strData;
	m_recordset.m_description=abid.m_strDescription;
	m_recordset.Update();
	m_recordset.Close();
	DataUpdate();
	//添加代码结束	
}

void CNationInformationDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	UpdateData(TRUE);
	int i=m_ctrNation.GetSelectionMark();
	if(i<0)
	{
		MessageBox("请选择一个用户!");
		return;
	}
	CString strSQL;
	strSQL.Format("select* from nationInformation where folk='%s'",\
		m_ctrNation.GetItemText(i,1));
	if(! m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败！","数据库错误",MB_OK);
		return;
	}
	//删除该用户
	m_recordset.Delete();
	m_recordset.Close();
	DataUpdate();
	//添加代码结束	
}

BOOL CNationInformationDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//添加代码
	//初始化民族信息对话框中的列表控件表头
	m_ctrNation.InsertColumn(0,"序号");
	m_ctrNation.SetColumnWidth(0,40);
	m_ctrNation.InsertColumn(1,"民族");
	m_ctrNation.SetColumnWidth(1,60);
	m_ctrNation.InsertColumn(2,"描述");
	m_ctrNation.SetColumnWidth(2,80);
	m_ctrNation.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	DataUpdate();
	//添加代码结束	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CNationInformationDlg::DataUpdate()
{
	//添加代码
	m_ctrNation.SetFocus();
	m_ctrNation.DeleteAllItems();
	m_ctrNation.SetRedraw(FALSE);
	CString strSQL;
	char buffer[20];
	UpdateData(TRUE);
	strSQL="select* from nationInformation";
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败！","数据库错误",MB_OK);
		return;
	}
	int i=0;
	while(!m_recordset.IsEOF())
	{
		_itoa(m_recordset.m_ID,buffer,10);
		m_ctrNation.InsertItem(i,buffer);
		m_ctrNation.SetItemText(i,1,m_recordset.m_folk);
		m_ctrNation.SetItemText(i,2,m_recordset.m_description);
		i++;
		m_recordset.MoveNext();
	}
	m_recordset.Close();
	m_ctrNation.SetRedraw(TRUE);
	//添加代码结束
}

// NotesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "NotesDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNotesDlg dialog


CNotesDlg::CNotesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNotesDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNotesDlg)
	m_iCondition = -1;
	m_tmDate = 0;
	m_strType = _T("");
	m_strContent = _T("");
	m_strContext = _T("");
	m_strTitle = _T("");
	m_strUnit = _T("");
	m_strWriter = _T("");
	//}}AFX_DATA_INIT
	//添加代码
	m_strNumber = "";
	//添加代码结束
}


void CNotesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNotesDlg)
	DDX_Control(pDX, IDC_LIST_NOTES, m_ctrNotes);
	DDX_Control(pDX, IDC_COMBO_CONDITION, m_ctrCondition);
	DDX_Control(pDX, IDOK, m_bntOK);
	DDX_Control(pDX, IDC_BUTTON_CANCEL, m_bntCancel);
	DDX_Control(pDX, IDC_BUTTON_UPDATE, m_bntUpdate);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_bntDelete);
	DDX_Control(pDX, IDC_BUTTON_ADD, m_bntAdd);
	DDX_CBIndex(pDX, IDC_COMBO_CONDITION, m_iCondition);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_DATE, m_tmDate);
	DDX_CBString(pDX, IDC_COMBO_TYPE, m_strType);
	DDX_Text(pDX, IDC_EDIT_CONTENT, m_strContent);
	DDX_Text(pDX, IDC_EDIT_CONTEXT, m_strContext);
	DDX_Text(pDX, IDC_EDIT_TITLE, m_strTitle);
	DDX_Text(pDX, IDC_EDIT_UNIT1, m_strUnit);
	DDX_Text(pDX, IDC_EDIT_WRITER, m_strWriter);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNotesDlg, CDialog)
	//{{AFX_MSG_MAP(CNotesDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, OnButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	ON_NOTIFY(NM_CLICK, IDC_LIST_NOTES, OnClickListNotes)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNotesDlg message handlers

void CNotesDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	m_strType = "";
	m_strTitle = "";
	m_strContext = "";
	m_strNumber = "-1";
	m_strUnit = "";
	m_strWriter = "";
	m_tmDate = CTime::GetCurrentTime();
	m_bntOK.EnableWindow();
	m_bntCancel.EnableWindow();
	UpdateData(FALSE);
	//添加代码结束
}

void CNotesDlg::OnButtonCancel() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	//将对话框中取消与保存两个按钮设置为灰色的disenable状态
	m_bntOK.EnableWindow(FALSE);
	m_bntCancel.EnableWindow(FALSE);
	//添加代码结束
}

void CNotesDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	int i = m_ctrNotes.GetSelectionMark();
	if(i < 0)
	{
		MessageBox("亲，请选择一条具体的记录删除！");
		return;
	}
	CString strSQL;
	strSQL.Format("select * from notes where number = %s",m_ctrNotes.GetItemText(i,0));
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败！","数据库错误",MB_OK);
		return;
	}
	//删除用户选择的记录
	m_recordset.Delete();
	//关闭数据集
	m_recordset.Close();
	//更新删除记录后对话框事件概要与事件内容组框控件内的数据
	strSQL = "select * from notes";
	DataUpdate(strSQL);
	m_strType = "";
	m_strTitle = "";
	m_strContext = "";
	m_strUnit = "";
	m_strWriter = "";
	m_tmDate = CTime::GetCurrentTime();
	UpdateData(FALSE);
	m_bntOK.EnableWindow(FALSE);
	m_bntCancel.EnableWindow(FALSE);
	//添加代码结束
}

void CNotesDlg::OnButtonUpdate() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	m_bntOK.EnableWindow();
	m_bntCancel.EnableWindow();
	//添加代码结束
}

void CNotesDlg::OnButtonSearch() 
{
	// TODO: Add your control notification handler code here
	//添加代码
	UpdateData();
	CString strSQL;
	if(m_iCondition == 0)
		strSQL.Format("select * from notes where type = %s",m_strContent);
	else
		strSQL.Format("select * from notes where title = %s",m_strContent);
	if(m_strContent == "")
		strSQL = "select * from notes";
	DataUpdate(strSQL);
	m_bntOK.EnableWindow(FALSE);
	m_bntCancel.EnableWindow(FALSE);
	//添加代码结束
}

void CNotesDlg::OnOK() 
{
	// TODO: Add extra validation here
	//添加代码
	UpdateData();
	if(m_strType == "")
	{
		MessageBox("事件类型不能为空，请输入！");
		return;
	}
	CString strSQL;
	strSQL.Format("select * from notes where number = %s",m_strNumber);
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败！","数据库错误",MB_OK);
		return;
	}
	//分新建与修改两种情况处理
	if(m_recordset.GetRecordCount() == 0)
	{
		m_recordset.AddNew();   //新建
		m_recordset.m_type = m_strType;
		m_recordset.m_title = m_strTitle;
		m_recordset.m_rDate = m_tmDate;
		m_recordset.m_content = m_strContext;
		m_recordset.m_writer = m_strWriter;
		m_recordset.m_wUnit = m_strUnit;
		m_recordset.Update();
	}
	else
	{
		m_recordset.Edit();    //修改
		m_recordset.m_type = m_strType;
		m_recordset.m_title = m_strTitle;
		m_recordset.m_rDate = m_tmDate;
		m_recordset.m_content = m_strContext;
		m_recordset.m_writer = m_strWriter;
		m_recordset.m_wUnit = m_strUnit;
		m_recordset.Update();
	}
    m_recordset.Close();
	strSQL = "select * from notes";
	DataUpdate(strSQL);
	m_bntOK.EnableWindow(FALSE);
	m_bntCancel.EnableWindow(FALSE);
	//添加代码结束
	CDialog::OnOK();
}

void CNotesDlg::OnClickListNotes(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	//添加代码
	m_bntOK.EnableWindow(FALSE);
	m_bntCancel.EnableWindow(FALSE);
	CString strSQL;
	UpdateData(TRUE);
	int i = m_ctrNotes.GetSelectionMark();
	m_strNumber = m_ctrNotes.GetItemText(i,0);
    strSQL.Format("select * from notes where number = %s",m_strNumber);
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败！","数据库错误",MB_OK);
		return;
	}
	m_strType = m_recordset.m_type;
	m_strTitle = m_recordset.m_title;
	m_tmDate = m_recordset.m_rDate;
	m_strContext = m_recordset.m_content;
	m_strUnit = m_recordset.m_wUnit;
	m_strWriter = m_recordset.m_writer;
	m_recordset.Close();
	UpdateData(FALSE);
	//添加代码结束
	*pResult = 0;
}

BOOL CNotesDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//添加代码
	m_ctrNotes.InsertColumn(0,"序号");
	m_ctrNotes.SetColumnWidth(0,60);
	m_ctrNotes.InsertColumn(1,"事件标题");
	m_ctrNotes.SetColumnWidth(1,90);
	m_ctrNotes.InsertColumn(2,"记录日期");
	m_ctrNotes.SetColumnWidth(2,80);
	m_ctrNotes.InsertColumn(3,"事件类型");
	m_ctrNotes.SetColumnWidth(3,90);
	m_ctrNotes.InsertColumn(4,"记录人");
	m_ctrNotes.SetColumnWidth(4,80);
	m_ctrNotes.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	CString strSQL;
	strSQL = "select * from notes";
	DataUpdate(strSQL);
    m_bntOK.EnableWindow(FALSE);
	m_bntCancel.EnableWindow(FALSE);
	//添加代码结束
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CNotesDlg::DataUpdate(CString strSQL)
{
    //添加代码
	m_ctrNotes.SetFocus();
    m_ctrNotes.DeleteAllItems();
	m_ctrNotes.SetRedraw(FALSE);
	CString strTime;
	char buffer[20];
	UpdateData(TRUE);
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败！","数据库错误",MB_OK);
		return;
	}
	int i = 0;
	while(!m_recordset.IsBOF())
	{
		ltoa(m_recordset.m_number,buffer,10);
        m_ctrNotes.InsertItem(i,buffer);
		m_ctrNotes.SetItemText(i,1,m_recordset.m_title);
		strTime.Format("%d - %d - %d",m_recordset.m_rDate.GetYear(),m_recordset.m_rDate.GetMonth(),m_recordset.m_rDate.GetDay());
		m_ctrNotes.SetItemText(i,2,strTime);
		m_ctrNotes.SetItemText(i,3,m_recordset.m_type);
		m_ctrNotes.SetItemText(i,4,m_recordset.m_writer);
		m_ctrNotes.SetItemText(i,5,m_recordset.m_content);
		i++;
		m_recordset.MoveNext();
	}
	m_recordset.Close();
	m_ctrNotes.SetRedraw(TRUE);
	//添加代码结束
}

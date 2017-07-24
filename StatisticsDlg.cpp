// StatisticsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "StatisticsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStatisticsDlg dialog


CStatisticsDlg::CStatisticsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStatisticsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStatisticsDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CStatisticsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStatisticsDlg)
	DDX_Control(pDX, IDC_RESULT, m_ctrResult);
	DDX_Control(pDX, IDC_SELECTION, m_ctrSelection);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStatisticsDlg, CDialog)
	//{{AFX_MSG_MAP(CStatisticsDlg)
	ON_NOTIFY(NM_CLICK, IDC_SELECTION, OnClickSelection)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStatisticsDlg message handlers

void CStatisticsDlg::OnClickSelection(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	//添加代码
	CString strSQL;               //构造SQL语句
	CString strAttribute = "0";   //存储属性值
	CDatabase db;
	db.Open(_T("PostDB"));
	CRecordset m_recordset(&db);
	UpdateData(TRUE);
	int iSort = m_ctrSelection.GetSelectionMark();
	int i = 0;
	switch(iSort)
	{
	//按性别统计
	case 0:
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);
		m_ctrResult.InsertColumn(0,"性别");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,80);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL = "select count(code) as amount ,sex from staff group by sex";
		if(!m_recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败！","数据库错误",MB_OK);
			return;
		}
		while(!m_recordset.IsEOF())
		{
			m_recordset.GetFieldValue("sex",strAttribute);
			m_ctrResult.InsertItem(i,strAttribute);
			m_recordset.GetFieldValue("amount",strAttribute);
			m_ctrResult.SetItemText(i,1,strAttribute);
			i++;
			m_recordset.MoveNext();
		}
		m_recordset.Close();
		break;
	//按年龄统计
	case 1:
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);
		m_ctrResult.InsertColumn(0,"年龄");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,80);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL = "select count(code) as amount ,age from staff group by age";
		if(!m_recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败！","数据库错误",MB_OK);
			return;
		}
		while(!m_recordset.IsEOF())
		{
			m_recordset.GetFieldValue("age",strAttribute);
			m_ctrResult.InsertItem(i,strAttribute);
			m_recordset.GetFieldValue("amount",strAttribute);
			m_ctrResult.SetItemText(i,1,strAttribute);
			i++;
			m_recordset.MoveNext();
		}
		m_recordset.Close();
		break;
	//按民族统计
	case 2:
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);
		m_ctrResult.InsertColumn(0,"民族");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,80);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL = "select count(code) as amount ,race from staff group by race";
		if(!m_recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败！","数据库错误",MB_OK);
			return;
		}
		while(!m_recordset.IsEOF())
		{
			m_recordset.GetFieldValue("race",strAttribute);
			m_ctrResult.InsertItem(i,strAttribute);
			m_recordset.GetFieldValue("amount",strAttribute);
			m_ctrResult.SetItemText(i,1,strAttribute);
			i++;
			m_recordset.MoveNext();
		}
		m_recordset.Close();
		break;
	//按籍贯统计
	case 3:
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);
		m_ctrResult.InsertColumn(0,"籍贯");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,80);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL = "select count(code) as amount ,native from staff group by native";
		if(!m_recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败！","数据库错误",MB_OK);
			return;
		}
		while(!m_recordset.IsEOF())
		{
			m_recordset.GetFieldValue("native",strAttribute);
			m_ctrResult.InsertItem(i,strAttribute);
			m_recordset.GetFieldValue("amount",strAttribute);
			m_ctrResult.SetItemText(i,1,strAttribute);
			i++;
			m_recordset.MoveNext();
		}
		m_recordset.Close();
		break;
	//按职务类别统计
	case 4:
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);
		m_ctrResult.InsertColumn(0,"职务");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,80);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL = "select count(code) as amount ,job from staff group by job";
		if(!m_recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败！","数据库错误",MB_OK);
			return;
		}
		while(!m_recordset.IsEOF())
		{
			m_recordset.GetFieldValue("job",strAttribute);
			m_ctrResult.InsertItem(i,strAttribute);
			m_recordset.GetFieldValue("amount",strAttribute);
			m_ctrResult.SetItemText(i,1,strAttribute);
			i++;
			m_recordset.MoveNext();
		}
		m_recordset.Close();
		break;
	//按职称类别统计
	case 5:
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);
		m_ctrResult.InsertColumn(0,"职称");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,80);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL = "select count(code) as amount ,technical from staff group by technical";
		if(!m_recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败！","数据库错误",MB_OK);
			return;
		}
		while(!m_recordset.IsEOF())
		{
			m_recordset.GetFieldValue("technical",strAttribute);
			m_ctrResult.InsertItem(i,strAttribute);
			m_recordset.GetFieldValue("amount",strAttribute);
			m_ctrResult.SetItemText(i,1,strAttribute);
			i++;
			m_recordset.MoveNext();
		}
		m_recordset.Close();
		break;
	//按学历统计
	case 6:
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);
		m_ctrResult.InsertColumn(0,"学历");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,80);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL = "select count(code) as amount ,degree from staff group by degree";
		if(!m_recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败！","数据库错误",MB_OK);
			return;
		}
		while(!m_recordset.IsEOF())
		{
			m_recordset.GetFieldValue("degree",strAttribute);
			m_ctrResult.InsertItem(i,strAttribute);
			m_recordset.GetFieldValue("amount",strAttribute);
			m_ctrResult.SetItemText(i,1,strAttribute);
			i++;
			m_recordset.MoveNext();
		}
		m_recordset.Close();
		break;
	//按政治面貌统计
	case 7:
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);
		m_ctrResult.InsertColumn(0,"政治面貌");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,80);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL = "select count(code) as amount ,party from staff group by party";
		if(!m_recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败！","数据库错误",MB_OK);
			return;
		}
		while(!m_recordset.IsEOF())
		{
			m_recordset.GetFieldValue("party",strAttribute);
			m_ctrResult.InsertItem(i,strAttribute);
			m_recordset.GetFieldValue("amount",strAttribute);
			m_ctrResult.SetItemText(i,1,strAttribute);
			i++;
			m_recordset.MoveNext();
		}
		m_recordset.Close();
		break;
	//按院系部门统计
	case 8:
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);
		m_ctrResult.InsertColumn(0,"院系部门");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,80);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL = "select count(code) as amount ,department from staff group by department";
		if(!m_recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败！","数据库错误",MB_OK);
			return;
		}
		while(!m_recordset.IsEOF())
		{
			m_recordset.GetFieldValue("department",strAttribute);
			m_ctrResult.InsertItem(i,strAttribute);
			m_recordset.GetFieldValue("amount",strAttribute);
			m_ctrResult.SetItemText(i,1,strAttribute);
			i++;
			m_recordset.MoveNext();
		}
		m_recordset.Close();
		break;
	//按教工岗位统计
	case 9:
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);
		m_ctrResult.InsertColumn(0,"教工岗位");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,80);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL = "select count(code) as amount ,post from staff group by post";
		if(!m_recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败！","数据库错误",MB_OK);
			return;
		}
		while(!m_recordset.IsEOF())
		{
			m_recordset.GetFieldValue("post",strAttribute);
			m_ctrResult.InsertItem(i,strAttribute);
			m_recordset.GetFieldValue("amount",strAttribute);
			m_ctrResult.SetItemText(i,1,strAttribute);
			i++;
			m_recordset.MoveNext();
		}
		m_recordset.Close();
		break;
	//按工资等级统计
	case 10:
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);
		m_ctrResult.InsertColumn(0,"工资等级");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,80);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL = "select count(code) as amount ,salary from staff group by salary";
		if(!m_recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败！","数据库错误",MB_OK);
			return;
		}
		while(!m_recordset.IsEOF())
		{
			m_recordset.GetFieldValue("salary",strAttribute);
			m_ctrResult.InsertItem(i,strAttribute);
			m_recordset.GetFieldValue("amount",strAttribute);
			m_ctrResult.SetItemText(i,1,strAttribute);
			i++;
			m_recordset.MoveNext();
		}
		m_recordset.Close();
		break;
	//按婚姻状况统计
	case 11:
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);
		m_ctrResult.InsertColumn(0,"婚姻状况");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,80);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL = "select count(code) as amount ,marriage from staff group by marriage";
		if(!m_recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败！","数据库错误",MB_OK);
			return;
		}
		while(!m_recordset.IsEOF())
		{
			m_recordset.GetFieldValue("marriage",strAttribute);
			m_ctrResult.InsertItem(i,strAttribute);
			m_recordset.GetFieldValue("amount",strAttribute);
			m_ctrResult.SetItemText(i,1,strAttribute);
			i++;
			m_recordset.MoveNext();
		}
		m_recordset.Close();
		break;
	//按毕业院校统计
	case 12:
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);
		m_ctrResult.InsertColumn(0,"毕业院校");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,80);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL = "select count(code) as amount ,university from staff group by university";
		if(!m_recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败！","数据库错误",MB_OK);
			return;
		}
		while(!m_recordset.IsEOF())
		{
			m_recordset.GetFieldValue("university",strAttribute);
			m_ctrResult.InsertItem(i,strAttribute);
			m_recordset.GetFieldValue("amount",strAttribute);
			m_ctrResult.SetItemText(i,1,strAttribute);
			i++;
			m_recordset.MoveNext();
		}
		m_recordset.Close();
		break;
	//按所学专业统计
	case 13:
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);
		m_ctrResult.InsertColumn(0,"所学专业");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,80);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL = "select count(code) as amount ,subject from staff group by subject";
		if(!m_recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败！","数据库错误",MB_OK);
			return;
		}
		while(!m_recordset.IsEOF())
		{
			m_recordset.GetFieldValue("subject",strAttribute);
			m_ctrResult.InsertItem(i,strAttribute);
			m_recordset.GetFieldValue("amount",strAttribute);
			m_ctrResult.SetItemText(i,1,strAttribute);
			i++;
			m_recordset.MoveNext();
		}
		m_recordset.Close();
		break;
	default:
		return;
	}
	UpdateData(FALSE);
	//添加代码结束
	*pResult = 0;
}

BOOL CStatisticsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//添加代码
	m_ctrSelection.InsertColumn(0,"统计类别");
    m_ctrSelection.SetColumnWidth(0,120);
	m_ctrSelection.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_ctrSelection.InsertItem(0,"按性别统计");
	m_ctrSelection.InsertItem(1,"按年龄统计");
	m_ctrSelection.InsertItem(2,"按民族统计");
	m_ctrSelection.InsertItem(3,"按籍贯统计");
	m_ctrSelection.InsertItem(4,"按职务统计");
	m_ctrSelection.InsertItem(5,"按职称统计");
	m_ctrSelection.InsertItem(6,"按学历统计");
	m_ctrSelection.InsertItem(7,"按政治面貌统计");
	m_ctrSelection.InsertItem(8,"按院系部门统计");
	m_ctrSelection.InsertItem(9,"按教工岗位统计");
	m_ctrSelection.InsertItem(10,"按工资等级统计");
	m_ctrSelection.InsertItem(11,"按婚姻状况统计");
	m_ctrSelection.InsertItem(12,"按毕业院校统计");
	m_ctrSelection.InsertItem(13,"按所学专业统计");
	m_ctrResult.InsertColumn(0,"");
	m_ctrResult.SetColumnWidth(0,80);
	m_ctrResult.InsertColumn(1,"");
	m_ctrResult.SetColumnWidth(1,100);
	m_ctrResult.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	//添加代码结束
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

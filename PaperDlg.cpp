// PaperDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "PaperDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaperDlg dialog


CPaperDlg::CPaperDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPaperDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPaperDlg)
	m_tmPubTime = 0;
	m_strRank = _T("");
	m_strLevel = _T("");
	m_strType = _T("");
	m_strIndex = _T("");
	m_strTitle = _T("");
	m_strPublication = _T("");
	m_strPubyear = _T("");
	m_strVolume = _T("");
	m_strIssue = _T("");
	m_strPage = _T("");
	// 添加代码
    m_strCode = "";
    // 添加代码结束
	//}}AFX_DATA_INIT
}


void CPaperDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPaperDlg)
	DDX_Control(pDX, IDC_LIST_PAPER, m_ctrPaper);
	DDX_Control(pDX, IDC_BUTTON_SAVE, m_bntSave);
	DDX_Control(pDX, IDC_BUTTON_UPDATE, m_bntUpdate);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_bntDelete);
	DDX_Control(pDX, IDC_BUTTON_ADD, m_bntAdd);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_PUBTIME, m_tmPubTime);
	DDX_CBString(pDX, IDC_COMBO_RANK, m_strRank);
	DDX_CBString(pDX, IDC_COMBO_LEVEL, m_strLevel);
	DDX_CBString(pDX, IDC_COMBO_TYPE, m_strType);
	DDX_CBString(pDX, IDC_COMBO_INDEX, m_strIndex);
	DDX_Text(pDX, IDC_EDIT_TITLE, m_strTitle);
	DDX_Text(pDX, IDC_EDIT_PUBLICATION, m_strPublication);
	DDX_Text(pDX, IDC_EDIT_PUBTIME, m_strPubyear);
	DDX_Text(pDX, IDC_EDIT_VOLUME, m_strVolume);
	DDX_Text(pDX, IDC_EDIT_ISSUE, m_strIssue);
	DDX_Text(pDX, IDC_EDIT_PAGE, m_strPage);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPaperDlg, CDialog)
	//{{AFX_MSG_MAP(CPaperDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, OnButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_NOTIFY(NM_CLICK, IDC_LIST_PAPER, OnClickListPaper)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPaperDlg message handlers

void CPaperDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
        m_strIndex       = "";
        m_strIssue       = "";
        m_strLevel       = "";
        m_strPage        = "";
        m_strPublication = "";
        m_tmPubTime  = CTime::GetCurrentTime();
        m_strPubyear     = "";
        m_strRank        = "";
        m_strTitle       = "";
        m_strType        = "";
        m_strVolume      = "";
        m_bntSave.EnableWindow();
        m_bntAdd.EnableWindow(FALSE);
        m_bntDelete.EnableWindow(FALSE);
        m_bntUpdate.EnableWindow(FALSE);
        UpdateData(FALSE);
        // 添加代码结束
}

void CPaperDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
        int i = m_ctrPaper.GetSelectionMark();
        if(i<0)
        {
            MessageBox("请选择一条记录进行删除！");
            return;
        }
        CString strSQL;
        strSQL.Format("select * from paper where number= %s ",m_ctrPaper.GetItemText(i,0));
        if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
        {
             MessageBox("打开数据库失败!","数据库错误",MB_OK);
             return ;
        }
        //删除该记录
        m_recordset.Delete();
        m_recordset.Close();
        //更新用户界面
        DataUpdate(m_strCode);
        m_strIndex       = "";
        m_strIssue       = "";
        m_strLevel       = "";
        m_strPage        = "";
        m_strPublication = "";
        m_strPubyear     = "";
        m_strRank        = "";
        m_strTitle       = "";
        m_strType        = "";
        m_strVolume      = "";
        m_tmPubTime  = CTime::GetCurrentTime();
        UpdateData(FALSE);
        // 添加代码结束
}

void CPaperDlg::OnButtonUpdate() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
        UpdateData();
        int i = m_ctrPaper.GetSelectionMark();
        if(i<0)
        {
            MessageBox("请选择一条记录进行修改！");
            return;
        }
        CString strSQL;
        strSQL.Format("select * from paper where number= %s ",m_ctrPaper.GetItemText(i,0));
        if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
        {
             MessageBox("打开数据库失败!","数据库错误",MB_OK);
        return ;
        }
        m_recordset.Edit();
        m_recordset.m_pub_time    = m_tmPubTime;
        m_recordset.m_index       = m_strIndex;
        m_recordset.m_issue       = m_strIssue;
        m_recordset.m_level       = m_strLevel;
        m_recordset.m_page        = m_strPage;
        m_recordset.m_publication = m_strPublication;
        m_recordset.m_pub_year    = m_strPubyear;
        m_recordset.m_rank        = m_strRank;
        m_recordset.m_title       = m_strTitle;
        m_recordset.m_type        = m_strType;
        m_recordset.m_volume      = m_strVolume;
        m_recordset.Update();
        m_recordset.Close();
        DataUpdate(m_strCode);
        // 添加代码结束
}

void CPaperDlg::OnButtonSave() 
{
	// TODO: Add your control notification handler code here
	// 添加代码
        UpdateData();
        if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE))
        {
             MessageBox("打开数据库失败!","数据库错误",MB_OK);
        return ;
        }
        m_recordset.AddNew();
        m_recordset.m_index       = m_strIndex;
        m_recordset.m_issue       = m_strIssue;
        m_recordset.m_pub_time    = m_tmPubTime;
        m_recordset.m_level       = m_strLevel;
        m_recordset.m_page        = m_strPage;
        m_recordset.m_publication = m_strPublication;
        m_recordset.m_pub_year    = m_strPubyear;
        m_recordset.m_rank        = m_strRank;
        m_recordset.m_title       = m_strTitle;
        m_recordset.m_type        = m_strType;
        m_recordset.m_volume      = m_strVolume;
        // 教工编号code也要保存进后台数据库PostDB.accdb中
        m_recordset.m_code        = m_strCode;
        m_recordset.Update();
        m_recordset.Close();
        DataUpdate(m_strCode);
        // 添加代码结束
}

void CPaperDlg::OnClickListPaper(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	// 添加代码
        CString strSQL;
        UpdateData(TRUE);
        int i = m_ctrPaper.GetSelectionMark();
        strSQL.Format("select * from paper where number=%s",m_ctrPaper.GetItemText(i,0));
        if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
        {
             MessageBox("打开数据库失败!","数据库错误",MB_OK);
             return ;
        }
        m_strIndex       = m_recordset.m_index;
        m_strIssue       = m_recordset.m_issue;
        m_tmPubTime      = m_recordset.m_pub_time;
        m_strLevel       = m_recordset.m_level;
        m_strPage        = m_recordset.m_page;
        m_strPublication = m_recordset.m_publication;
        m_strPubyear     = m_recordset.m_pub_year;
        m_strRank        = m_recordset.m_rank;
        m_strTitle       = m_recordset.m_title;
        m_strType        = m_recordset.m_type;
        m_strVolume      = m_recordset.m_volume;
        m_recordset.Close();
        UpdateData(FALSE);
        m_bntSave.EnableWindow(FALSE);
        m_bntAdd.EnableWindow();
        m_bntDelete.EnableWindow();
        m_bntUpdate.EnableWindow();
        // 添加代码结束
	*pResult = 0;
}

BOOL CPaperDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	// 添加代码
        // 初始化奖励记录对话框中的列表控件表头
        m_ctrPaper.InsertColumn(0,"序号");
        m_ctrPaper.SetColumnWidth(0,60);
        m_ctrPaper.InsertColumn(1,"题目");
        m_ctrPaper.SetColumnWidth(1,80);
        m_ctrPaper.InsertColumn(2,"作者排名");
        m_ctrPaper.SetColumnWidth(2,80);
        m_ctrPaper.InsertColumn(3,"刊物名称");
        m_ctrPaper.SetColumnWidth(3,80);
        m_ctrPaper.InsertColumn(4,"发表时间");
        m_ctrPaper.SetColumnWidth(4,80);
        m_ctrPaper.InsertColumn(5,"出版年");
        m_ctrPaper.SetColumnWidth(5,80);
        m_ctrPaper.InsertColumn(6,"卷");
        m_ctrPaper.SetColumnWidth(6,80);
        m_ctrPaper.InsertColumn(7,"期");
        m_ctrPaper.SetColumnWidth(7,80);
        m_ctrPaper.InsertColumn(8,"页码");
        m_ctrPaper.SetColumnWidth(8,80);
        m_ctrPaper.InsertColumn(9,"刊物级别");
        m_ctrPaper.SetColumnWidth(9,80);
        m_ctrPaper.InsertColumn(10,"文献类型");
        m_ctrPaper.SetColumnWidth(10,80);
        m_ctrPaper.InsertColumn(11,"检索类型");
        m_ctrPaper.SetColumnWidth(11,80);
        m_ctrPaper.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
        m_bntSave.EnableWindow(FALSE);
        m_bntAdd.EnableWindow(FALSE);
        m_bntDelete.EnableWindow(FALSE);
        m_bntUpdate.EnableWindow(FALSE);
        // 添加代码结束
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPaperDlg::DataUpdate(CString strCode)
{
     // 添加代码
        m_ctrPaper.DeleteAllItems();
        m_ctrPaper.SetRedraw(FALSE);
        UpdateData(TRUE);
        CString strSQL;
        m_strCode.Format("%s",strCode);
        // SQL语句条件表达式中的code是教工的工号
        strSQL.Format( "select * from paper where code = '%s'",strCode);
        if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
        {
             MessageBox("打开数据库失败!","数据库错误",MB_OK);
             return ;
        }
        int i=0;
        CString strTime; // 对应发表时间
        char buffer[20];
        while(!m_recordset.IsEOF())
        {
        // 对应列表框上的序号
        _ltoa(m_recordset.m_number,buffer,10);
        m_ctrPaper.InsertItem(i,buffer);
        // 对应列表框上的题目
        m_ctrPaper.SetItemText(i,1,m_recordset.m_title);
        // 对应列表框上的作者排名
        m_ctrPaper.SetItemText(i,2,m_recordset.m_rank);
        // 对应列表框上的刊物名称
        m_ctrPaper.SetItemText(i,3,m_recordset.m_publication);
        // 对应列表框上的发表时间
        strTime.Format("%d-%d-%d",m_recordset.m_pub_time.GetYear(),m_recordset.m_pub_time.\
			GetMonth(),m_recordset.m_pub_time.GetDay());
        m_ctrPaper.SetItemText(i,4,strTime);
        // 对应列表框上的出版年
        m_ctrPaper.SetItemText(i,5,m_recordset.m_pub_year);
        // 对应列表框上的卷
        m_ctrPaper.SetItemText(i,6,m_recordset.m_volume);
        // 对应列表框上的期
        m_ctrPaper.SetItemText(i,7,m_recordset.m_issue);
        // 对应列表框上的页码
        m_ctrPaper.SetItemText(i,8,m_recordset.m_page);
        // 对应列表框上的刊物级别
        m_ctrPaper.SetItemText(i,9,m_recordset.m_level);
        // 对应列表框上的文献类型
        m_ctrPaper.SetItemText(i,10,m_recordset.m_type);
        // 对应列表框上的检索类型
        m_ctrPaper.SetItemText(i,11,m_recordset.m_index);
        i++;
        m_recordset.MoveNext();
        }
        m_recordset.Close();
        m_ctrPaper.SetRedraw(TRUE);
        // 根据是否添加新的论文成果记录设置添加与保存两个按钮的状态
        m_bntSave.EnableWindow(FALSE);
        if(m_strCode=="")
        m_bntAdd.EnableWindow(FALSE);
        else
           m_bntAdd.EnableWindow();
           m_bntDelete.EnableWindow(FALSE);
           m_bntUpdate.EnableWindow(FALSE);
        // 添加代码结束
}

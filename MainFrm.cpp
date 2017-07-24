// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Database.h"

#include "MainFrm.h"
//添加代码
#include "LoginDlg.h"
#include "UserSettingDlg.h"
#include "NationInformationDlg.h"
#include "PositionInformationDlg.h"
#include "EducationDegreeDlg.h"
#include "PoliticalStatusDlg.h"  
#include "DepartmentSectionDlg.h"
#include "WageLevelDlg.h"
#include "TechnicalPostDlg.h"
#include "AdministrativePostDlg.h"
#include "DepartmentDlg.h"
#include "SectionDlg.h"
#include "AuxiliaryDlg.h"
#include "AppendantDlg.h"
#include "FulltimeDlg.h"
#include "BrowseDlg.h"
#include "SearchDlg.h"
#include "StatisticsDlg.h"
#include "NotesDlg.h"
#include "ContactsDlg.h"
#include "MeetingRecordDlg.h"
//添加代码结束
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_CLOSE()
	ON_COMMAND(ID_SYS_RELOAD, OnSysReload)
	ON_COMMAND(ID_SYS_USERSETTING, OnSysUsersetting)
	ON_COMMAND(ID_SYS_EXIT, OnSysExit)
	ON_UPDATE_COMMAND_UI(ID_SYS_USERSETTING, OnUpdateSysUsersetting)
	ON_COMMAND(ID_SYS_DBBACKUP, OnSysDbbackup)
	ON_UPDATE_COMMAND_UI(ID_SYS_DBBACKUP, OnUpdateSysDbbackup)
	ON_COMMAND(ID_SYS_DBRECOVER, OnSysDbrecover)
	ON_UPDATE_COMMAND_UI(ID_SYS_DBRECOVER, OnUpdateSysDbrecover)
	ON_COMMAND(ID_INF_NATION, OnInfNation)
	ON_UPDATE_COMMAND_UI(ID_INF_NATION, OnUpdateInfNation)
	ON_COMMAND(ID_INF_POSITION, OnInfPosition)
	ON_UPDATE_COMMAND_UI(ID_INF_POSITION, OnUpdateInfPosition)
	ON_COMMAND(ID_INF_EDUCATION, OnInfEducation)
	ON_UPDATE_COMMAND_UI(ID_INF_EDUCATION, OnUpdateInfEducation)
	ON_COMMAND(ID_INF_POLITICAL, OnInfPolitical)
	ON_UPDATE_COMMAND_UI(ID_INF_POLITICAL, OnUpdateInfPolitical)
	ON_COMMAND(ID_INF_DEPT, OnInfDept)
	ON_UPDATE_COMMAND_UI(ID_INF_DEPT, OnUpdateInfDept)
	ON_COMMAND(ID_INF_WAGE, OnInfWage)
	ON_UPDATE_COMMAND_UI(ID_INF_WAGE, OnUpdateInfWage)
	ON_COMMAND(ID_INF_TECHNICAL, OnInfTechnical)
	ON_UPDATE_COMMAND_UI(ID_INF_TECHNICAL, OnUpdateInfTechnical)
	ON_COMMAND(ID_INF_ADMIN, OnInfAdmin)
	ON_UPDATE_COMMAND_UI(ID_INF_ADMIN, OnUpdateInfAdmin)
	ON_COMMAND(ID_ORG_DEPT, OnOrgDept)
	ON_UPDATE_COMMAND_UI(ID_ORG_DEPT, OnUpdateOrgDept)
	ON_COMMAND(ID_ORG_SECTION, OnOrgSection)
	ON_UPDATE_COMMAND_UI(ID_ORG_SECTION, OnUpdateOrgSection)
	ON_COMMAND(ID_ORG_AUXILIARY, OnOrgAuxiliary)
	ON_UPDATE_COMMAND_UI(ID_ORG_AUXILIARY, OnUpdateOrgAuxiliary)
	ON_COMMAND(ID_ORG_APPENDANT, OnOrgAppendant)
	ON_UPDATE_COMMAND_UI(ID_ORG_APPENDANT, OnUpdateOrgAppendant)
	ON_COMMAND(ID_ORG_FULLTIME, OnOrgFulltime)
	ON_UPDATE_COMMAND_UI(ID_ORG_FULLTIME, OnUpdateOrgFulltime)
	ON_COMMAND(ID_HUMAN_BROWSE, OnHumanBrowse)
	ON_UPDATE_COMMAND_UI(ID_HUMAN_BROWSE, OnUpdateHumanBrowse)
	ON_COMMAND(ID_HUMAN_QUERY, OnHumanQuery)
	ON_UPDATE_COMMAND_UI(ID_HUMAN_QUERY, OnUpdateHumanQuery)
	ON_COMMAND(ID_HUMAN_STATISTICS, OnHumanStatistics)
	ON_COMMAND(ID_TOOL_NOTES, OnToolNotes)
	ON_COMMAND(ID_TOOL_CONTACTS, OnToolContacts)
	ON_COMMAND(ID_TOOL_MEETING, OnToolMeeting)
	ON_COMMAND(ID_HELP_ABOUT, OnHelpAbout)
	ON_COMMAND(ID_HELP_DOCUMENT, OnHelpDocument)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
//添加代码
    ID_SEPARATOR,           //增加的显示固定文本的信息行窗格
	ID_INDICATOR_CLOCK,     //增加的显示系统时间的指示器窗格
	//删除以下3个原有指示器窗格
	//ID_INDICATOR_CAPS,
	//ID_INDICATOR_NUM,
	//ID_INDICATOR_SCRL,
//添加代码结束
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	//添加代码
	//安装定时器，并将其时间间隔设为1000毫秒  
	SetTimer(1,1000,NULL);
	//设置信息行窗格文字
	m_wndStatusBar.SetPaneText(1,"高校人事信息数据库应用系统",true);
	//添加代码结束
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	//添加代码
	CTime time;
	time=CTime::GetCurrentTime();    //得到当前时间
	CString s=time.Format("%H:%M:%S");     //转换时间格式
	//显示时钟
	m_wndStatusBar.SetPaneText(m_wndStatusBar.CommandToIndex(ID_INDICATOR_CLOCK),s,true);
	//添加代码结束
	CFrameWnd::OnTimer(nIDEvent);
}

void CMainFrame::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	//添加代码
	KillTimer(1);     //销毁定时器
	//添加代码结束
	CFrameWnd::OnClose();
}

void CMainFrame::OnSysReload() 
{
	// TODO: Add your command handler code here
	//添加代码
	CLoginDlg Dlg;
	int nRes=0;
	do
	{
		nRes=Dlg.DoModal();
		//回到主界面
		if(nRes==IDOK)
			return;
		//退出系统
		if(nRes==IDCANCEL)
		{
			if(AfxMessageBox("亲，请问您确定真的要退出系统吗？",MB_OKCANCEL)==IDCANCEL)
			{
				return;
			}
			CFrameWnd::OnClose();
			return;
		}
	}while(1);
	//添加代码结束
}

void CMainFrame::OnSysUsersetting() 
{
	// TODO: Add your command handler code here
	//添加代码
	CUserSettingDlg UserDlg;
	UserDlg.DoModal();
	//添加代码结束	
}

void CMainFrame::OnSysExit() 
{
	// TODO: Add your command handler code here
	//添加代码
	CFrameWnd::OnClose();
	//添加代码结束	
}

void CMainFrame::OnUpdateSysUsersetting(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	//添加代码
	CDatabaseApp*ptheApp=(CDatabaseApp*) AfxGetApp();
	pCmdUI -> Enable(ptheApp ->m_bHasSuperAuthority);
	//添加代码结束
}

void CMainFrame::OnSysDbbackup() 
{
	// TODO: Add your command handler code here
	//添加代码
	if(AfxMessageBox("亲，您是否要对本系统的数据库进行备份？",MB_OKCANCEL)==IDCANCEL)
	{
		return;
	}
	//将备份前的后台数据库PostDB备份到当前工程项目路径的文件夹DatabaseBackup \中的PostDB.bak
	if(CopyFile(".\\PostDB.accdb",".\\DatabaseBackup\\PostDB.bak",FALSE))
		AfxMessageBox("数据库备份成功!");
	else
		AfxMessageBox("数据库备份失败！");
	//添加代码结束	
}

void CMainFrame::OnUpdateSysDbbackup(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	//添加代码
	CDatabaseApp*ptheApp=(CDatabaseApp*) AfxGetApp();
	pCmdUI -> Enable(ptheApp -> m_bHasSuperAuthority);
	//添加代码结束	
}

void CMainFrame::OnSysDbrecover() 
{
	// TODO: Add your command handler code here
	//添加代码
	//将文件夹DatabaseBackup在的备份数据库PostDB.bak覆盖后台数据库PostDB.accdb
	if(AfxMessageBox("系统的后台数据库将被此副本覆盖，您确定要还原吗？",MB_OKCANCEL)==IDCANCEL)
	{
		return;
	}
	if(CopyFile(".\\DatabaseBackup\\PostDB.bak",".\\PostDB.accdb",FALSE))
		AfxMessageBox("数据库还原成功！");
	else
		AfxMessageBox("数据库还原失败！");
	//添加代码结束	
}

void CMainFrame::OnUpdateSysDbrecover(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	//添加代码
	CDatabaseApp*ptheApp = (CDatabaseApp*) AfxGetApp();
	pCmdUI->Enable(ptheApp ->m_bHasSuperAuthority);
	//添加代码结束	
}

void CMainFrame::OnInfNation() 
{
	// TODO: Add your command handler code here
	//添加代码
	CNationInformationDlg dlg;
	dlg.DoModal();
	//添加代码结束	
}

void CMainFrame::OnUpdateInfNation(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	//添加代码
	CDatabaseApp*ptheApp=(CDatabaseApp*) AfxGetApp();
	pCmdUI -> Enable(ptheApp -> m_bHasSuperAuthority);
	//添加代码结束	
}

void CMainFrame::OnInfPosition() 
{
	// TODO: Add your command handler code here
	// 添加代码
    CPositionInformationDlg dlg;
    dlg.DoModal();
    // 添加代码结束
}

void CMainFrame::OnUpdateInfPosition(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	// 添加代码
    CDatabaseApp*  ptheApp = (CDatabaseApp *) AfxGetApp();
    pCmdUI->Enable(ptheApp->m_bHasSuperAuthority);
    // 添加代码结束
}

void CMainFrame::OnInfEducation() 
{
	// TODO: Add your command handler code here
	// 添加代码
    CEducationDegreeDlg dlg;
    dlg.DoModal();
    // 添加代码结束
}

void CMainFrame::OnUpdateInfEducation(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	// 添加代码
    CDatabaseApp*  ptheApp = (CDatabaseApp *) AfxGetApp();
    pCmdUI->Enable(ptheApp->m_bHasSuperAuthority);
    // 添加代码结束
}

void CMainFrame::OnInfPolitical() 
{
	// TODO: Add your command handler code here
	// 添加代码
    CPoliticalStatusDlg dlg;
    dlg.DoModal();
    // 添加代码结束
}

void CMainFrame::OnUpdateInfPolitical(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
    // 添加代码
    CDatabaseApp*  ptheApp = (CDatabaseApp *) AfxGetApp();
    pCmdUI->Enable(ptheApp->m_bHasSuperAuthority);
    // 添加代码结束	
}

void CMainFrame::OnInfDept() 
{
	// TODO: Add your command handler code here
    // 添加代码
    CDepartmentSectionDlg dlg;
    dlg.DoModal();
    // 添加代码结束	
}

void CMainFrame::OnUpdateInfDept(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
    // 添加代码
    CDatabaseApp*  ptheApp = (CDatabaseApp *) AfxGetApp();
    pCmdUI->Enable(ptheApp->m_bHasSuperAuthority);
    // 添加代码结束	
}

void CMainFrame::OnInfWage() 
{
	// TODO: Add your command handler code here
	// 添加代码
    CWageLevelDlg dlg;
    dlg.DoModal();
    // 添加代码结束
}

void CMainFrame::OnUpdateInfWage(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	// 添加代码
    CDatabaseApp*  ptheApp = (CDatabaseApp *) AfxGetApp();
    pCmdUI->Enable(ptheApp->m_bHasSuperAuthority);
    // 添加代码结束
}

void CMainFrame::OnInfTechnical() 
{
	// TODO: Add your command handler code here
	// 添加代码
    CTechnicalPostDlg dlg;
    dlg.DoModal();
    // 添加代码结束
}

void CMainFrame::OnUpdateInfTechnical(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	// 添加代码
    CDatabaseApp*  ptheApp = (CDatabaseApp *) AfxGetApp();
    pCmdUI->Enable(ptheApp->m_bHasSuperAuthority);
    // 添加代码结束
}

void CMainFrame::OnInfAdmin() 
{
	// TODO: Add your command handler code here
	// 添加代码
    CAdministrativePostDlg dlg;
    dlg.DoModal();
    // 添加代码结束
}

void CMainFrame::OnUpdateInfAdmin(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	// 添加代码
    CDatabaseApp*  ptheApp = (CDatabaseApp *) AfxGetApp();
    pCmdUI->Enable(ptheApp->m_bHasSuperAuthority);
    // 添加代码结束
}

void CMainFrame::OnOrgDept() 
{
	// TODO: Add your command handler code here
    // 添加代码
    CDepartmentDlg dlg;
    dlg.DoModal();
    // 添加代码结束	
}

void CMainFrame::OnUpdateOrgDept(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	// 添加代码
    CDatabaseApp*  ptheApp = (CDatabaseApp *) AfxGetApp();
    pCmdUI->Enable(ptheApp->m_bHasSuperAuthority);
    // 添加代码结束
}

void CMainFrame::OnOrgSection() 
{
	// TODO: Add your command handler code here
    // 添加代码
    CSectionDlg dlg;
    dlg.DoModal();
    // 添加代码结束	
}

void CMainFrame::OnUpdateOrgSection(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
    // 添加代码
    CDatabaseApp*  ptheApp = (CDatabaseApp *) AfxGetApp();
    pCmdUI->Enable(ptheApp->m_bHasSuperAuthority);
    // 添加代码结束	
}

void CMainFrame::OnOrgAuxiliary() 
{
	// TODO: Add your command handler code here
    // 添加代码
    CAuxiliaryDlg dlg;
    dlg.DoModal();
    // 添加代码结束	
}

void CMainFrame::OnUpdateOrgAuxiliary(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
    // 添加代码
    CDatabaseApp*  ptheApp = (CDatabaseApp *) AfxGetApp();
    pCmdUI->Enable(ptheApp->m_bHasSuperAuthority);
    // 添加代码结束	
}

void CMainFrame::OnOrgAppendant() 
{
	// TODO: Add your command handler code here
    // 添加代码
    CAppendantDlg dlg;
    dlg.DoModal();
    // 添加代码结束		
}

void CMainFrame::OnUpdateOrgAppendant(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
    // 添加代码
    CDatabaseApp*  ptheApp = (CDatabaseApp *) AfxGetApp();
    pCmdUI->Enable(ptheApp->m_bHasSuperAuthority);
    // 添加代码结束	
}

void CMainFrame::OnOrgFulltime() 
{
	// TODO: Add your command handler code here
    // 添加代码
    CFulltimeDlg dlg;
    dlg.DoModal();
    // 添加代码结束	
}

void CMainFrame::OnUpdateOrgFulltime(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
    // 添加代码
    CDatabaseApp*  ptheApp = (CDatabaseApp *) AfxGetApp();
    pCmdUI->Enable(ptheApp->m_bHasSuperAuthority);
    // 添加代码结束	
}

void CMainFrame::OnHumanBrowse() 
{
	// TODO: Add your command handler code here
	// 添加代码
    CBrowseDlg dlg;
    dlg.DoModal();
    // 添加代码结束	
}

void CMainFrame::OnUpdateHumanBrowse(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	// 添加代码
    CDatabaseApp*  ptheApp = (CDatabaseApp *) AfxGetApp();
    pCmdUI->Enable(ptheApp->m_bHasSuperAuthority);
    // 添加代码结束	
}

void CMainFrame::OnHumanQuery() 
{
	// TODO: Add your command handler code here
	// 添加代码
    CSearchDlg dlg;
    dlg.DoModal();
    // 添加代码结束
}

void CMainFrame::OnUpdateHumanQuery(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	// 添加代码
    CDatabaseApp*  ptheApp = (CDatabaseApp *) AfxGetApp();
    pCmdUI->Enable(ptheApp->m_bHasSuperAuthority);
    // 添加代码结束	
}

void CMainFrame::OnHumanStatistics() 
{
	// TODO: Add your command handler code here
	// 添加代码
    CStatisticsDlg dlg;
    dlg.DoModal();
    // 添加代码结束	
}

void CMainFrame::OnToolNotes() 
{
	// TODO: Add your command handler code here
	// 添加代码
    CNotesDlg dlg;
    dlg.DoModal();
    // 添加代码结束
}

void CMainFrame::OnToolContacts() 
{
	// TODO: Add your command handler code here
	// 添加代码
    CContactsDlg dlg;
    dlg.DoModal();
    // 添加代码结束	
}

void CMainFrame::OnToolMeeting() 
{
	// TODO: Add your command handler code here
	// 添加代码
    CMeetingRecordDlg dlg;
    dlg.DoModal();
    // 添加代码结束
}

void CMainFrame::OnHelpAbout() 
{
	// TODO: Add your command handler code here
	// 添加代码
    extern CDatabaseApp theApp;
	theApp.OnAppAbout();
    // 添加代码结束
}

void CMainFrame::OnHelpDocument() 
{
	// TODO: Add your command handler code here
	//添加代码
	ShellExecute(NULL,"open",".\\help.docx",NULL,NULL,SW_SHOW);
	//添加代码结束
}

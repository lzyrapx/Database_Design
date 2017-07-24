// Database.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Database.h"

#include "MainFrm.h"
#include "DatabaseDoc.h"
#include "DatabaseView.h"
//���Ӵ���
#include <odbcinst.h>     //SQLConfigDataSource������ODBC API���ڵ�ͷ�ļ�
#include "LoginDlg.h"
//���Ӵ������
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDatabaseApp

BEGIN_MESSAGE_MAP(CDatabaseApp, CWinApp)
	//{{AFX_MSG_MAP(CDatabaseApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDatabaseApp construction

CDatabaseApp::CDatabaseApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	//���Ӵ���
	m_bHasSuperAuthority = FALSE; //��ʼ��m_bHasSuperAuthority
	//���Ӵ������
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CDatabaseApp object

CDatabaseApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CDatabaseApp initialization

BOOL CDatabaseApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	//���Ӵ���
	/*****************************************************************/
	//     SQLConfigDataSource()����ʵ��ODBC����Դ���Զ���װ         //
	/*****************************************************************/
	//SQLConfigDataSource(NULL,ODBC_ADD_DSN,
		 //"Microsoft Access Driver(*.mdb,*.accdb)",
		 //"DSN = PostDB \0"
		 //"Description = Hotel \0"
		    //"FileType = Access \0"
		    //"DBQ =.\\PostDB.accdb \0"
		       //);
	//���Ӵ������
#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.
	//���Ӵ���
	//ϵͳ��¼����
	    CLoginDlg loginDlg;
	    if(loginDlg.DoModal()!=IDOK)
		    return FALSE;
	//���Ӵ������
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MENU1,
		RUNTIME_CLASS(CDatabaseDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CDatabaseView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	//���Ӵ���
	//Ϊϵͳ���������ӹ��IDI_ICON1
	AfxGetMainWnd() ->SetIcon(LoadIcon(IDI_ICON1),true);
	//����ϵͳ���������
	AfxGetMainWnd() ->SetWindowText("��У������Ϣ���ݿ�Ӧ��ϵͳ");
	//���Ӵ������
	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CDatabaseApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CDatabaseApp message handlers

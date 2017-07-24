// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__A14C0714_3DCD_47B1_8CE5_9E40034C0C31__INCLUDED_)
#define AFX_MAINFRM_H__A14C0714_3DCD_47B1_8CE5_9E40034C0C31__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnClose();
	afx_msg void OnSysReload();
	afx_msg void OnSysUsersetting();
	afx_msg void OnSysExit();
	afx_msg void OnUpdateSysUsersetting(CCmdUI* pCmdUI);
	afx_msg void OnSysDbbackup();
	afx_msg void OnUpdateSysDbbackup(CCmdUI* pCmdUI);
	afx_msg void OnSysDbrecover();
	afx_msg void OnUpdateSysDbrecover(CCmdUI* pCmdUI);
	afx_msg void OnInfNation();
	afx_msg void OnUpdateInfNation(CCmdUI* pCmdUI);
	afx_msg void OnInfPosition();
	afx_msg void OnUpdateInfPosition(CCmdUI* pCmdUI);
	afx_msg void OnInfEducation();
	afx_msg void OnUpdateInfEducation(CCmdUI* pCmdUI);
	afx_msg void OnInfPolitical();
	afx_msg void OnUpdateInfPolitical(CCmdUI* pCmdUI);
	afx_msg void OnInfDept();
	afx_msg void OnUpdateInfDept(CCmdUI* pCmdUI);
	afx_msg void OnInfWage();
	afx_msg void OnUpdateInfWage(CCmdUI* pCmdUI);
	afx_msg void OnInfTechnical();
	afx_msg void OnUpdateInfTechnical(CCmdUI* pCmdUI);
	afx_msg void OnInfAdmin();
	afx_msg void OnUpdateInfAdmin(CCmdUI* pCmdUI);
	afx_msg void OnOrgDept();
	afx_msg void OnUpdateOrgDept(CCmdUI* pCmdUI);
	afx_msg void OnOrgSection();
	afx_msg void OnUpdateOrgSection(CCmdUI* pCmdUI);
	afx_msg void OnOrgAuxiliary();
	afx_msg void OnUpdateOrgAuxiliary(CCmdUI* pCmdUI);
	afx_msg void OnOrgAppendant();
	afx_msg void OnUpdateOrgAppendant(CCmdUI* pCmdUI);
	afx_msg void OnOrgFulltime();
	afx_msg void OnUpdateOrgFulltime(CCmdUI* pCmdUI);
	afx_msg void OnHumanBrowse();
	afx_msg void OnUpdateHumanBrowse(CCmdUI* pCmdUI);
	afx_msg void OnHumanQuery();
	afx_msg void OnUpdateHumanQuery(CCmdUI* pCmdUI);
	afx_msg void OnHumanStatistics();
	afx_msg void OnToolNotes();
	afx_msg void OnToolContacts();
	afx_msg void OnToolMeeting();
	afx_msg void OnHelpAbout();
	afx_msg void OnHelpDocument();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__A14C0714_3DCD_47B1_8CE5_9E40034C0C31__INCLUDED_)

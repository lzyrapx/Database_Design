#if !defined(AFX_BROWSEDLG_H__ACA9301D_33F7_40CA_99D4_77BB75BDD29C__INCLUDED_)
#define AFX_BROWSEDLG_H__ACA9301D_33F7_40CA_99D4_77BB75BDD29C__INCLUDED_

#include "BaseArchiveDlg.h"	// Added by ClassView
#include "FamilyMemberDlg.h"	// Added by ClassView
#include "WorkExperienceDlg.h"	// Added by ClassView
#include "RewardRecordDlg.h"	// Added by ClassView
#include "DisciplinePunishDlg.h"	// Added by ClassView
#include "PaperDlg.h"	// Added by ClassView
#include "ProjectDlg.h"	// Added by ClassView
#include "TechnicalAccessDlg.h"	// Added by ClassView
#include "AcademicEducationDlg.h"	// Added by ClassView
#include "ContinueEducationDlg.h"	// Added by ClassView
#include "ClassTeachingDlg.h"	// Added by ClassView
#include "StaffSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BrowseDlg.h : header file
//
//添加代码
#include "Container.h"
//添加代码结束
/////////////////////////////////////////////////////////////////////////////
// CBrowseDlg dialog

class CBrowseDlg : public CDialog
{
// Construction
public:
	CBrowseDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBrowseDlg)
	enum { IDD = IDD_DIALOG_BROWSE };
	CListCtrl	m_ctrContain;
	//CTabCtrl	m_ctrContainer;
	//添加代码
	CContainer  m_ctrContainer;
	//添加代码结束
	CComboBox	m_ctrContent;
	CComboBox	m_ctrCondition;
	CButton	m_bntCancel;
	CButton	m_bntSave;
	CButton	m_bntUpdate;
	CButton	m_bntDelete;
	CButton	m_bntAdd;
	int		m_iCondition;
	CString	m_strContent;
	CString	m_strCode;
	CString	m_strName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBrowseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBrowseDlg)
	afx_msg void OnButtonCancel();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonUpdate();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonSave();
	afx_msg void OnButtonSearch();
	afx_msg void OnClickListBrowse(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClose();
	afx_msg void OnDestroy();
	virtual BOOL OnInitDialog();
	afx_msg void OnEditupdateComboContent();
	afx_msg void OnSelchangeComboContent();
	afx_msg void OnSelchangeComboCondition();
	afx_msg void OnSelchangeTabBrowse(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangingTabBrowse(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_bNew;
	CStaffSet m_recordset;
	CClassTeachingDlg m_pClassTeachingDlg;
	CContinueEducationDlg m_pContinueEducationDlg;
	CAcademicEducationDlg m_pAcademicEducationDlg;
	CTechnicalAccessDlg m_pTechnicalAccessDlg;
	CProjectDlg m_pProjectDlg;
	CPaperDlg m_pPaperDlg;
	CDisciplinePunishDlg m_pDisciplinePunishDlg;
	CRewardRecordDlg m_pRewardRecordDlg;
	CWorkExperienceDlg m_pWorkExperienceDlg;
	CFamilyMemberDlg m_pFamilyMemberDlg;
	CBaseArchiveDlg m_pBaseArchiveDlg;
	void DataUpdate(CString strSQL);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BROWSEDLG_H__ACA9301D_33F7_40CA_99D4_77BB75BDD29C__INCLUDED_)

#if !defined(AFX_PROJECTDLG_H__E19AC4A7_08A8_45FB_A9CF_20D2D8440959__INCLUDED_)
#define AFX_PROJECTDLG_H__E19AC4A7_08A8_45FB_A9CF_20D2D8440959__INCLUDED_

#include "ProjectSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProjectDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProjectDlg dialog

class CProjectDlg : public CDialog
{
// Construction
public:
	void DataUpdate(CString strCode);
	CProjectDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CProjectDlg)
	enum { IDD = IDD_DIALOG_HPROJECT };
	CListCtrl	m_ctrProject;
	CButton	m_bntSave;
	CButton	m_bntUpdate;
	CButton	m_bntDelete;
	CButton	m_bntAdd;
	CTime	m_tmRelease;
	CTime	m_tmBegin;
	CTime	m_tmEnd;
	CString	m_strType;
	CString	m_strSort;
	CString	m_strLevel;
	CString	m_strRate;
	CString	m_strState;
	CString	m_strLimit;
	CString	m_strTitle;
	CString	m_strHost;
	CString	m_strRank;
	CString	m_strFirst;
	CString	m_strUnit;
	CString	m_strCost;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProjectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProjectDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonUpdate();
	afx_msg void OnButtonSave();
	afx_msg void OnClickListProject(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CProjectSet m_recordset;
	CString m_strCode;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROJECTDLG_H__E19AC4A7_08A8_45FB_A9CF_20D2D8440959__INCLUDED_)

#if !defined(AFX_CLASSTEACHINGDLG_H__0327A5C2_5F0C_4A1E_9019_5ED13A1515A3__INCLUDED_)
#define AFX_CLASSTEACHINGDLG_H__0327A5C2_5F0C_4A1E_9019_5ED13A1515A3__INCLUDED_

#include "ClassTeachingSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClassTeachingDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CClassTeachingDlg dialog

class CClassTeachingDlg : public CDialog
{
// Construction
public:
	void DataUpdate(CString strCode);
	CClassTeachingDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CClassTeachingDlg)
	enum { IDD = IDD_DIALOG_HCLASSTEACHING };
	CListCtrl	m_ctrTeaching;
	CButton	m_bntSave;
	CButton	m_bntUpdate;
	CButton	m_bntDelete;
	CButton	m_bntAdd;
	CString	m_strSemester;
	CString	m_strSort;
	CString	m_strObject;
	CString	m_strAnnual;
	CString	m_strCourse;
	CString	m_strLocation;
	CString	m_strClass;
	CString	m_strHour;
	CString	m_strLevel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClassTeachingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CClassTeachingDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonUpdate();
	afx_msg void OnButtonSave();
	afx_msg void OnClickListClassteaching(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CClassTeachingSet m_recordset;
	CString m_strCode;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLASSTEACHINGDLG_H__0327A5C2_5F0C_4A1E_9019_5ED13A1515A3__INCLUDED_)

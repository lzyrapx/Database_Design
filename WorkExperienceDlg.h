#if !defined(AFX_WORKEXPERIENCEDLG_H__7BC57850_2302_4902_912D_9382C6D27D4F__INCLUDED_)
#define AFX_WORKEXPERIENCEDLG_H__7BC57850_2302_4902_912D_9382C6D27D4F__INCLUDED_

#include "WorkExperienceSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WorkExperienceDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWorkExperienceDlg dialog

class CWorkExperienceDlg : public CDialog
{
// Construction
public:
	void DataUpdate(CString strCode);
	CWorkExperienceDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWorkExperienceDlg)
	enum { IDD = IDD_DIALOG_HWORKEXPERIENCE };
	CListCtrl	m_ctrWork;
	CButton	m_bntSave;
	CButton	m_bntUpdate;
	CButton	m_bntDelete;
	CButton	m_bntAdd;
	CTime	m_tmBegin;
	CTime	m_tmEnd;
	CString	m_strEducation;
	CString	m_strLocation;
	CString	m_strCompany;
	CString	m_strProver;
	CString	m_strDuty;
	CString	m_strTechnical;
	CString	m_strDepartment;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWorkExperienceDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWorkExperienceDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonUpdate();
	afx_msg void OnButtonSave();
	afx_msg void OnClickListWorkexperience(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CWorkExperienceSet m_recordset;
	CString m_strCode;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORKEXPERIENCEDLG_H__7BC57850_2302_4902_912D_9382C6D27D4F__INCLUDED_)

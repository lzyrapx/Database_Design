#if !defined(AFX_ACADEMICEDUCATIONDLG_H__03E8CDDF_E314_4DFF_AEAC_90845CE7CA0A__INCLUDED_)
#define AFX_ACADEMICEDUCATIONDLG_H__03E8CDDF_E314_4DFF_AEAC_90845CE7CA0A__INCLUDED_

#include "AcademicEducationSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AcademicEducationDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAcademicEducationDlg dialog

class CAcademicEducationDlg : public CDialog
{
// Construction
public:
	void DataUpdate(CString strCode);
	CAcademicEducationDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAcademicEducationDlg)
	enum { IDD = IDD_DIALOG_HACADEMICEDUCATION };
	CListCtrl	m_ctrAEducation;
	CButton	m_bntSave;
	CButton	m_bntUpdate;
	CButton	m_bntDelete;
	CButton	m_bntAdd;
	CTime	m_tmBDate;
	CTime	m_tmEDate;
	CString	m_strDegree;
	CString	m_strDiploma;
	CString	m_strDepartment;
	CString	m_strUniversity;
	CString	m_strMajor;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAcademicEducationDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAcademicEducationDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonUpdate();
	afx_msg void OnButtonSave();
	afx_msg void OnClickListAcademiceducation(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CAcademicEducationSet m_recordset;
	CString m_strCode;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACADEMICEDUCATIONDLG_H__03E8CDDF_E314_4DFF_AEAC_90845CE7CA0A__INCLUDED_)

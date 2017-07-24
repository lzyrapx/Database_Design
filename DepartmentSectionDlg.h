#if !defined(AFX_DEPARTMENTSECTIONDLG_H__946E53DB_B05B_47BB_8738_1A9FDC263B2C__INCLUDED_)
#define AFX_DEPARTMENTSECTIONDLG_H__946E53DB_B05B_47BB_8738_1A9FDC263B2C__INCLUDED_

#include "DepartmentSectionSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DepartmentSectionDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDepartmentSectionDlg dialog

class CDepartmentSectionDlg : public CDialog
{
// Construction
public:
	CDepartmentSectionDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDepartmentSectionDlg)
	enum { IDD = IDD_DIALOG_DEPARTMENTSECTION };
	CListCtrl	m_ctrDivision;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDepartmentSectionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDepartmentSectionDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CDepartmentSectionSet m_recordset;
	void DataUpdate();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEPARTMENTSECTIONDLG_H__946E53DB_B05B_47BB_8738_1A9FDC263B2C__INCLUDED_)

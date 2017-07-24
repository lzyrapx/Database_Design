#if !defined(AFX_WAGELEVELDLG_H__DA7B7FF2_5E57_4858_BBAA_4FE0B53EC0BE__INCLUDED_)
#define AFX_WAGELEVELDLG_H__DA7B7FF2_5E57_4858_BBAA_4FE0B53EC0BE__INCLUDED_

#include "WageLevelSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WageLevelDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWageLevelDlg dialog

class CWageLevelDlg : public CDialog
{
// Construction
public:
	CWageLevelDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWageLevelDlg)
	enum { IDD = IDD_DIALOG_WAGELEVEL };
	CListCtrl	m_ctrSalary;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWageLevelDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWageLevelDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CWageLevelSet m_recordset;
	void DataUpdate();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WAGELEVELDLG_H__DA7B7FF2_5E57_4858_BBAA_4FE0B53EC0BE__INCLUDED_)

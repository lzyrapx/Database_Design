#if !defined(AFX_ADMINISTRATIVEPOSTDLG_H__586E2CA3_EDF9_4526_BA61_800EF8305CF7__INCLUDED_)
#define AFX_ADMINISTRATIVEPOSTDLG_H__586E2CA3_EDF9_4526_BA61_800EF8305CF7__INCLUDED_

#include "AdministrativePostSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AdministrativePostDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAdministrativePostDlg dialog

class CAdministrativePostDlg : public CDialog
{
// Construction
public:
	CAdministrativePostDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAdministrativePostDlg)
	enum { IDD = IDD_DIALOG_ADMINISTRATIVEPOST };
	CListCtrl	m_ctrRank;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdministrativePostDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAdministrativePostDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CAdministrativePostSet m_recordset;
	void DataUpdate();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADMINISTRATIVEPOSTDLG_H__586E2CA3_EDF9_4526_BA61_800EF8305CF7__INCLUDED_)

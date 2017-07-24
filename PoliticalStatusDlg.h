#if !defined(AFX_POLITICALSTATUSDLG_H__BBAAFC4F_779E_4804_8850_7A4B5AC86098__INCLUDED_)
#define AFX_POLITICALSTATUSDLG_H__BBAAFC4F_779E_4804_8850_7A4B5AC86098__INCLUDED_

#include "PoliticalStatusSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PoliticalStatusDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPoliticalStatusDlg dialog

class CPoliticalStatusDlg : public CDialog
{
// Construction
public:
	CPoliticalStatusDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPoliticalStatusDlg)
	enum { IDD = IDD_DIALOG_POLITICALSTATUS };
	CListCtrl	m_ctrParty;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPoliticalStatusDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPoliticalStatusDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CPoliticalStatusSet m_recordset;
	void DataUpdate();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POLITICALSTATUSDLG_H__BBAAFC4F_779E_4804_8850_7A4B5AC86098__INCLUDED_)

#if !defined(AFX_TECHNICALPOSTDLG_H__174FD124_F00E_4345_B23B_8F403FAB94F2__INCLUDED_)
#define AFX_TECHNICALPOSTDLG_H__174FD124_F00E_4345_B23B_8F403FAB94F2__INCLUDED_

#include "TechnicalPostSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TechnicalPostDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTechnicalPostDlg dialog

class CTechnicalPostDlg : public CDialog
{
// Construction
public:
	CTechnicalPostDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTechnicalPostDlg)
	enum { IDD = IDD_DIALOG_TECHNICALPOST };
	CListCtrl	m_ctrTitle;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTechnicalPostDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTechnicalPostDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CTechnicalPostSet m_recordset;
	void DataUpdate();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TECHNICALPOSTDLG_H__174FD124_F00E_4345_B23B_8F403FAB94F2__INCLUDED_)

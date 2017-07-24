#if !defined(AFX_TECHNICALACCESSDLG_H__E7EB8768_729E_42C5_85D2_3E82A908C52C__INCLUDED_)
#define AFX_TECHNICALACCESSDLG_H__E7EB8768_729E_42C5_85D2_3E82A908C52C__INCLUDED_

#include "TechnicalAccessSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TechnicalAccessDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTechnicalAccessDlg dialog

class CTechnicalAccessDlg : public CDialog
{
// Construction
public:
	void DataUpdate(CString strCode);
	CTechnicalAccessDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTechnicalAccessDlg)
	enum { IDD = IDD_DIALOG_HTECHNICALACCESS };
	CListCtrl	m_ctrTAccess;
	CButton	m_bntSave;
	CButton	m_bntUpdate;
	CButton	m_bntDelete;
	CButton	m_bntAdd;
	CTime	m_tmGDate;
	CTime	m_tmBDate;
	CTime	m_tmEDate;
	CString	m_strMode;
	CString	m_strTitle;
	CString	m_strEmploy;
	CString	m_strHire;
	CString	m_strUnit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTechnicalAccessDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTechnicalAccessDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonUpdate();
	afx_msg void OnButtonSave();
	afx_msg void OnClickListTechnicalaccess(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CTechnicalAccessSet m_recordset;
	CString m_strCode;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TECHNICALACCESSDLG_H__E7EB8768_729E_42C5_85D2_3E82A908C52C__INCLUDED_)

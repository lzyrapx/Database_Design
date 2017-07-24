#if !defined(AFX_NOTESDLG_H__2A18F198_7AB6_4BA6_B21E_23F2B2232C5C__INCLUDED_)
#define AFX_NOTESDLG_H__2A18F198_7AB6_4BA6_B21E_23F2B2232C5C__INCLUDED_

#include "NotesSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NotesDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNotesDlg dialog

class CNotesDlg : public CDialog
{
// Construction
public:
	CNotesDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNotesDlg)
	enum { IDD = IDD_DIALOG_NOTES };
	CListCtrl	m_ctrNotes;
	CComboBox	m_ctrCondition;
	CButton	m_bntOK;
	CButton	m_bntCancel;
	CButton	m_bntUpdate;
	CButton	m_bntDelete;
	CButton	m_bntAdd;
	int		m_iCondition;
	CTime	m_tmDate;
	CString	m_strType;
	CString	m_strContent;
	CString	m_strContext;
	CString	m_strTitle;
	CString	m_strUnit;
	CString	m_strWriter;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNotesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNotesDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonCancel();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonUpdate();
	afx_msg void OnButtonSearch();
	virtual void OnOK();
	afx_msg void OnClickListNotes(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void DataUpdate(CString strSQL);
	CString m_strNumber;
	CNotesSet m_recordset;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOTESDLG_H__2A18F198_7AB6_4BA6_B21E_23F2B2232C5C__INCLUDED_)

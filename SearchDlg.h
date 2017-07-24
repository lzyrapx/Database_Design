#if !defined(AFX_SEARCHDLG_H__5BC110F8_0926_453E_A489_2D47AF116754__INCLUDED_)
#define AFX_SEARCHDLG_H__5BC110F8_0926_453E_A489_2D47AF116754__INCLUDED_

#include "StaffSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SearchDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSearchDlg dialog

class CSearchDlg : public CDialog
{
// Construction
public:
	CSearchDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSearchDlg)
	enum { IDD = IDD_DIALOG_HSEARCH };
	CListCtrl	m_ctrSearch;
	CComboBox	m_ctrUnit;
	CComboBox	m_ctrTechnical;
	CComboBox	m_ctrPost;
	CComboBox	m_ctrPosition;
	CComboBox	m_ctrPolitical;
	CComboBox	m_ctrNation;
	CComboBox	m_ctrMarriage;
	CComboBox	m_ctrEducation;
	CString	m_strEducation;
	CString	m_strMarriage;
	CString	m_strNation;
	CString	m_strPolitical;
	CString	m_strPosition;
	CString	m_strPost;
	CString	m_strTechnical;
	CString	m_strUnit;
	CString	m_strSex;
	int		m_iAge;
	CString	m_strName;
	CString	m_strNative;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSearchDlg)
	afx_msg void OnButtonSearch();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CStaffSet m_recordset;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHDLG_H__5BC110F8_0926_453E_A489_2D47AF116754__INCLUDED_)

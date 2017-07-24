#if !defined(AFX_CONTACTSDLG_H__AB11785D_C866_4CE3_B06D_67053D66FDAB__INCLUDED_)
#define AFX_CONTACTSDLG_H__AB11785D_C866_4CE3_B06D_67053D66FDAB__INCLUDED_

#include "ContactsSet.h"	// Added by ClassView
#include "NewCThinDlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ContactsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CContactsDlg dialog

class CContactsDlg : public CDialog
{
// Construction
public:
	CContactsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CContactsDlg)
	enum { IDD = IDD_DIALOG_COMMUNICATIONTHIN };
	CListCtrl	m_ctrThin;
	int		m_iCondition;
	CString	m_strContent;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CContactsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CContactsDlg)
	afx_msg void OnButtonView();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonUpdate();
	afx_msg void OnButtonSearch();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CNewCThinDlg m_pDlg;
	void DataUpdate(CString strSQL);
	CContactsSet m_recordset;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTACTSDLG_H__AB11785D_C866_4CE3_B06D_67053D66FDAB__INCLUDED_)

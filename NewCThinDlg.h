#if !defined(AFX_NEWCTHINDLG_H__E50F87FC_BD10_4E92_9B29_C7EAD42A3AED__INCLUDED_)
#define AFX_NEWCTHINDLG_H__E50F87FC_BD10_4E92_9B29_C7EAD42A3AED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewCThinDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewCThinDlg dialog

class CNewCThinDlg : public CDialog
{
// Construction
public:
	CNewCThinDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewCThinDlg)
	enum { IDD = IDD_DIALOG_NEWCTHIN };
	CString	m_strSex;
	CString	m_strName;
	CString	m_strFPhone;
	CString	m_strOPhone;
	CString	m_strUnit;
	CString	m_strMPhone;
	CString	m_strShort;
	CString	m_strQQ;
	CString	m_strWeChat;
	CString	m_strEmail;
	CString	m_strRemark;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewCThinDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewCThinDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWCTHINDLG_H__E50F87FC_BD10_4E92_9B29_C7EAD42A3AED__INCLUDED_)

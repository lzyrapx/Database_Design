#if !defined(AFX_ADDBASEINFODLG_H__CF87C88E_5719_42D7_B2EA_A514F0127DFF__INCLUDED_)
#define AFX_ADDBASEINFODLG_H__CF87C88E_5719_42D7_B2EA_A514F0127DFF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddBaseInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddBaseInfoDlg dialog

class CAddBaseInfoDlg : public CDialog
{
// Construction
public:
	CAddBaseInfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddBaseInfoDlg)
	enum { IDD = IDD_DIALOG_COMMON };
	CEdit	m_ctrDescription;
	CEdit	m_ctrData;
	CString	m_strData;
	CString	m_strDescription;
	//添加代码
	CString m_strLabel;
	CString m_strInformation;
	//添加代码结束
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddBaseInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddBaseInfoDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDBASEINFODLG_H__CF87C88E_5719_42D7_B2EA_A514F0127DFF__INCLUDED_)

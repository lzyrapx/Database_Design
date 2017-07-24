#if !defined(AFX_CONTINUEEDUCATIONDLG_H__9FE7565A_4685_464A_851F_8D26CB6B8B45__INCLUDED_)
#define AFX_CONTINUEEDUCATIONDLG_H__9FE7565A_4685_464A_851F_8D26CB6B8B45__INCLUDED_

#include "ContinueEducationSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ContinueEducationDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CContinueEducationDlg dialog

class CContinueEducationDlg : public CDialog
{
// Construction
public:
	void DataUpdate(CString strCode);
	CContinueEducationDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CContinueEducationDlg)
	enum { IDD = IDD_DIALOG_HCONTINUEEDUCATION };
	CListCtrl	m_ctrCEducation;
	CButton	m_bntSave;
	CButton	m_bntUpdate;
	CButton	m_bntDelete;
	CButton	m_bntAdd;
	CTime	m_tmBDate;
	CTime	m_tmEDate;
	CString	m_strMode;
	CString	m_strEffect;
	CString	m_strContent;
	CString	m_strUnit;
	CString	m_strLocation;
	CString	m_strCost;
	CString	m_strHour;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CContinueEducationDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CContinueEducationDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonUpdate();
	afx_msg void OnButtonSave();
	afx_msg void OnClickListContinueeducation(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CContinueEducationSet m_recordset;
	CString m_strCode;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTINUEEDUCATIONDLG_H__9FE7565A_4685_464A_851F_8D26CB6B8B45__INCLUDED_)

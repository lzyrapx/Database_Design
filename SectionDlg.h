#if !defined(AFX_SECTIONDLG_H__EBB7EDAF_1FEA_4797_A7A1_BCB59365B64E__INCLUDED_)
#define AFX_SECTIONDLG_H__EBB7EDAF_1FEA_4797_A7A1_BCB59365B64E__INCLUDED_

#include "SectionSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SectionDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSectionDlg dialog

class CSectionDlg : public CDialog
{
// Construction
public:
	CSectionDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSectionDlg)
	enum { IDD = IDD_DIALOG_SECTION };
	CListCtrl	m_ctrSection;
	CButton	m_bntSave;
	CString	m_strCode;
	CString	m_strLocation;
	CString	m_strSetting;
	CString	m_strRule;
	CString	m_strContent;
	CString	m_strLeader;
	CString	m_strName;
	//添加代码
	int m_iCondition;
	//添加代码结束
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSectionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSectionDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonSave();
	afx_msg void OnButtonSearch();
	afx_msg void OnButtonUpdate();
	afx_msg void OnClickListSection(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CSectionSet m_recordset;
	void DataUpdate(CString strSQL);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SECTIONDLG_H__EBB7EDAF_1FEA_4797_A7A1_BCB59365B64E__INCLUDED_)

#if !defined(AFX_DEPARTMENTDLG_H__FD7FD3F7_648F_4161_A81E_6361A647F8CC__INCLUDED_)
#define AFX_DEPARTMENTDLG_H__FD7FD3F7_648F_4161_A81E_6361A647F8CC__INCLUDED_

#include "DepartmentSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DepartmentDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDepartmentDlg dialog

class CDepartmentDlg : public CDialog
{
// Construction
public:
	CDepartmentDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDepartmentDlg)
	enum { IDD = IDD_DIALOG_DEPARTMENT };
	CListCtrl	m_ctrDepartment;
	CButton	m_bntSave;
	CString	m_strCode;
	CString	m_strLocation;
	CString	m_strSetting;
	CString	m_strTeaching;
	CString	m_strResearching;
	CString	m_strStudent;
	CString	m_strContent;
	CString	m_strName;
	CString	m_strLeader;
	//添加代码
	int m_iCondition;
	//添加代码结束
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDepartmentDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDepartmentDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonSave();
	afx_msg void OnButtonSearch();
	afx_msg void OnButtonUpdate();
	afx_msg void OnClickListDepartment(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CDepartmentSet m_recordset;
	void DataUpdate(CString strSQL);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEPARTMENTDLG_H__FD7FD3F7_648F_4161_A81E_6361A647F8CC__INCLUDED_)

#if !defined(AFX_APPENDANTDLG_H__4973308A_4A3F_482E_B0E1_3C75ECCC0541__INCLUDED_)
#define AFX_APPENDANTDLG_H__4973308A_4A3F_482E_B0E1_3C75ECCC0541__INCLUDED_

#include "AppendantSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AppendantDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAppendantDlg dialog

class CAppendantDlg : public CDialog
{
// Construction
public:
	CAppendantDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAppendantDlg)
	enum { IDD = IDD_DIALOG_APPENDANT };
	CListCtrl	m_ctrAppendant;
	CButton	m_bntSave;
	CString	m_strCode;
	CString	m_strLocation;
	CString	m_strSetting;
	CString	m_strRegulation;
	CString	m_strContent;
	CString	m_strName;
	CString	m_strLeader;
	//添加代码
	int m_iCondition;
	//添加代码结束
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAppendantDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAppendantDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonSave();
	afx_msg void OnButtonSearch();
	afx_msg void OnButtonUpdate();
	afx_msg void OnClickListAppendant(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CAppendantSet m_recordset;
	void DataUpdate(CString strSQL);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APPENDANTDLG_H__4973308A_4A3F_482E_B0E1_3C75ECCC0541__INCLUDED_)

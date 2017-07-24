#if !defined(AFX_USERSETTINGDLG_H__7B354819_A5C1_44F6_86AB_DC9C49E6C5F7__INCLUDED_)
#define AFX_USERSETTINGDLG_H__7B354819_A5C1_44F6_86AB_DC9C49E6C5F7__INCLUDED_

#include "User.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserSettingDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserSettingDlg dialog

class CUserSettingDlg : public CDialog
{
// Construction
public:
	CUserSettingDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUserSettingDlg)
	enum { IDD = IDD_DIALOG_USERSETTING };
	CListCtrl	m_ctrUserList;
	CEdit	m_ctrPassword;
	CEdit	m_ctrUserName;
	CButton	m_bntOK;
	CButton	m_bntAdd;
	CButton	m_bntDelete;
	CButton	m_bntCancel;
	BOOL	m_bAuthority;
	CString	m_strUserName;
	CString	m_strPassword;
	CString	m_strConfirm;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserSettingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserSettingDlg)
	afx_msg void OnButtonCancel();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonAdd();
	virtual void OnOK();
	afx_msg void OnClickListUserlist(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void DataUpdate();
	CUser m_recordset;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERSETTINGDLG_H__7B354819_A5C1_44F6_86AB_DC9C49E6C5F7__INCLUDED_)

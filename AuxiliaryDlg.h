#if !defined(AFX_AUXILIARYDLG_H__2E308937_9DEC_4FE4_BF80_6AE174D7D16B__INCLUDED_)
#define AFX_AUXILIARYDLG_H__2E308937_9DEC_4FE4_BF80_6AE174D7D16B__INCLUDED_

#include "AuxiliarySet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AuxiliaryDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAuxiliaryDlg dialog

class CAuxiliaryDlg : public CDialog
{
// Construction
public:
	CAuxiliaryDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAuxiliaryDlg)
	enum { IDD = IDD_DIALOG_AUXILIARY };
	CListCtrl	m_ctrAuxiliary;
	CButton	m_bntSave;
	CString	m_strCode;
	CString	m_strLocation;
	CString	m_strSetting;
	CString	m_strDuty;
	CString	m_strContent;
	CString	m_strName;
	CString	m_strLeader;
	//添加代码
	int m_iCondition;
	//添加代码结束
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAuxiliaryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAuxiliaryDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonSave();
	afx_msg void OnButtonSearch();
	afx_msg void OnButtonUpdate();
	afx_msg void OnClickListAuxiliary(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CAuxiliarySet m_recordset;
	void DataUpdate(CString strSQL);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUXILIARYDLG_H__2E308937_9DEC_4FE4_BF80_6AE174D7D16B__INCLUDED_)

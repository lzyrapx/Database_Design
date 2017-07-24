#if !defined(AFX_PAPERDLG_H__3EEDC6C8_4626_42CA_A0A8_D51E32C1CF79__INCLUDED_)
#define AFX_PAPERDLG_H__3EEDC6C8_4626_42CA_A0A8_D51E32C1CF79__INCLUDED_

#include "PaperSet1.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PaperDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPaperDlg dialog

class CPaperDlg : public CDialog
{
// Construction
public:
	void DataUpdate(CString strCode);
	CPaperDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPaperDlg)
	enum { IDD = IDD_DIALOG_HPAPER };
	CListCtrl	m_ctrPaper;
	CButton	m_bntSave;
	CButton	m_bntUpdate;
	CButton	m_bntDelete;
	CButton	m_bntAdd;
	CTime	m_tmPubTime;
	CString	m_strRank;
	CString	m_strLevel;
	CString	m_strType;
	CString	m_strIndex;
	CString	m_strTitle;
	CString	m_strPublication;
	CString	m_strPubyear;
	CString	m_strVolume;
	CString	m_strIssue;
	CString	m_strPage;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPaperDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPaperDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonUpdate();
	afx_msg void OnButtonSave();
	afx_msg void OnClickListPaper(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CPaperSet1 m_recordset;
	CString m_strCode;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAPERDLG_H__3EEDC6C8_4626_42CA_A0A8_D51E32C1CF79__INCLUDED_)

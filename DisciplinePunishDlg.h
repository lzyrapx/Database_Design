#if !defined(AFX_DISCIPLINEPUNISHDLG_H__762ECE38_1EA2_4135_A476_401FE39F2507__INCLUDED_)
#define AFX_DISCIPLINEPUNISHDLG_H__762ECE38_1EA2_4135_A476_401FE39F2507__INCLUDED_

#include "DisciplinePunishSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DisciplinePunishDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDisciplinePunishDlg dialog

class CDisciplinePunishDlg : public CDialog
{
// Construction
public:
	void DataUpdate(CString strCode);
	CDisciplinePunishDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDisciplinePunishDlg)
	enum { IDD = IDD_DIALOG_HDISCIPLINEPUNISH };
	CListCtrl	m_ctrDisPunish;
	CButton	m_bntSave;
	CButton	m_bntUpdate;
	CButton	m_bntDelete;
	CButton	m_bntAdd;
	CTime	m_tmPDate;
	CTime	m_tmDDate;
	CString	m_strPeriod;
	CString	m_strSort;
	CString	m_strPReason;
	CString	m_strDReason;
	CString	m_strUnit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDisciplinePunishDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDisciplinePunishDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonUpdate();
	afx_msg void OnButtonSave();
	afx_msg void OnClickListDisciplinepunish(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CDisciplinePunishSet m_recordset;
	CString m_strCode;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISCIPLINEPUNISHDLG_H__762ECE38_1EA2_4135_A476_401FE39F2507__INCLUDED_)

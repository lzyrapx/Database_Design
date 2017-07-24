#if !defined(AFX_MEETINGRECORDDLG_H__28CF4A13_2F0A_4835_B68C_CA03611CEB40__INCLUDED_)
#define AFX_MEETINGRECORDDLG_H__28CF4A13_2F0A_4835_B68C_CA03611CEB40__INCLUDED_

#include "MeetingRecordSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MeetingRecordDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMeetingRecordDlg dialog

class CMeetingRecordDlg : public CDialog
{
// Construction
public:
	CMeetingRecordDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMeetingRecordDlg)
	enum { IDD = IDD_DIALOG_MEETINGRECORD };
	CListCtrl	m_ctrMeeting;
	CComboBox	m_ctrCondition;
	CButton	m_bntOK;
	CButton	m_bntCancel;
	CButton	m_bntUpdate;
	CButton	m_bntDelete;
	CButton	m_bntAdd;
	int		m_iCondition;
	CTime	m_tmDate;
	CString	m_strSort;
	CString	m_strContent;
	CString	m_strLocation;
	CString	m_strSubject;
	CString	m_strHostUnit;
	CString	m_strWriter;
	CString	m_strPartiUnit;
	CString	m_strHost;
	CString	m_strRemark;
	CString	m_strDetails;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMeetingRecordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMeetingRecordDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonCancel();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonUpdate();
	afx_msg void OnButtonSearch();
	virtual void OnOK();
	afx_msg void OnClickListMeeting(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void DataUpdate(CString strSQL);
	CString m_strNumber;
	CMeetingRecordSet m_recordset;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEETINGRECORDDLG_H__28CF4A13_2F0A_4835_B68C_CA03611CEB40__INCLUDED_)

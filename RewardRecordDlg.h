#if !defined(AFX_REWARDRECORDDLG_H__14DEC6CE_46B0_4309_B0A6_C7A515DFF72D__INCLUDED_)
#define AFX_REWARDRECORDDLG_H__14DEC6CE_46B0_4309_B0A6_C7A515DFF72D__INCLUDED_

#include "RewardRecordSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RewardRecordDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRewardRecordDlg dialog

class CRewardRecordDlg : public CDialog
{
// Construction
public:
	void DataUpdate(CString strCode);
	CRewardRecordDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRewardRecordDlg)
	enum { IDD = IDD_DIALOG_HREWARDRECORD };
	CListCtrl	m_ctrReward;
	CButton	m_bntSave;
	CButton	m_bntUpdate;
	CButton	m_bntDelete;
	CButton	m_bntAdd;
	CTime	m_tmDate;
	CString	m_strCategory;
	CString	m_strSort;
	CString	m_strLevel;
	CString	m_strTitle;
	CString	m_strUnit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRewardRecordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRewardRecordDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonUpdate();
	afx_msg void OnButtonSave();
	afx_msg void OnClickListRewardrecord(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CRewardRecordSet m_recordset;
	CString m_strCode;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REWARDRECORDDLG_H__14DEC6CE_46B0_4309_B0A6_C7A515DFF72D__INCLUDED_)

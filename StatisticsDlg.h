#if !defined(AFX_STATISTICSDLG_H__7977B144_08B0_4040_A8C2_E7A38FE9B118__INCLUDED_)
#define AFX_STATISTICSDLG_H__7977B144_08B0_4040_A8C2_E7A38FE9B118__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StatisticsDlg.h : header file
//
//添加代码
#include "StaffSet.h"
//添加代码结束
/////////////////////////////////////////////////////////////////////////////
// CStatisticsDlg dialog

class CStatisticsDlg : public CDialog
{
// Construction
public:
	CStatisticsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CStatisticsDlg)
	enum { IDD = IDD_DIALOG_HSTATISTICS };
	CListCtrl	m_ctrResult;
	CListCtrl	m_ctrSelection;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStatisticsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStatisticsDlg)
	afx_msg void OnClickSelection(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATISTICSDLG_H__7977B144_08B0_4040_A8C2_E7A38FE9B118__INCLUDED_)

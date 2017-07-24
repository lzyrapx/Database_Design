#if !defined(AFX_NATIONINFORMATIONDLG_H__854E6774_CBB3_4FD3_A229_C1768BF6C18E__INCLUDED_)
#define AFX_NATIONINFORMATIONDLG_H__854E6774_CBB3_4FD3_A229_C1768BF6C18E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NationInformationDlg.h : header file
//
//添加代码
#include "NationInformationSet.h"
//添加代码结束

/////////////////////////////////////////////////////////////////////////////
// CNationInformationDlg dialog

class CNationInformationDlg : public CDialog
{
// Construction
public:
	CNationInformationDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNationInformationDlg)
	enum { IDD = IDD_DIALOG_NATIONINFORMATION };
	CListCtrl	m_ctrNation;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNationInformationDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNationInformationDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void DataUpdate();
	//添加代码
	CNationInformationSet m_recordset;
	//添加代码结束
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NATIONINFORMATIONDLG_H__854E6774_CBB3_4FD3_A229_C1768BF6C18E__INCLUDED_)

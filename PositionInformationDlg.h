#if !defined(AFX_POSITIONINFORMATIONDLG_H__94050210_6FD0_4855_ABFF_C39AE81C26E0__INCLUDED_)
#define AFX_POSITIONINFORMATIONDLG_H__94050210_6FD0_4855_ABFF_C39AE81C26E0__INCLUDED_

#include "PositionInformationSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PositionInformationDlg.h : header file
//

// 添加代码
#include "PositionInformationSet.h"   
// 添加代码结束
// 添加代码
#include "AddBaseInfoDlg.h"
// 添加代码结束

/////////////////////////////////////////////////////////////////////////////
// CPositionInformationDlg dialog

class CPositionInformationDlg : public CDialog
{
// Construction
public:
	CPositionInformationDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPositionInformationDlg)
	enum { IDD = IDD_DIALOG_POSITIONINFORMATION };
	CListCtrl	m_ctrPost;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPositionInformationDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPositionInformationDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void DataUpdate();
	CPositionInformationSet m_recordset;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POSITIONINFORMATIONDLG_H__94050210_6FD0_4855_ABFF_C39AE81C26E0__INCLUDED_)

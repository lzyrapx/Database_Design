#if !defined(AFX_FULLTIMEDLG_H__3DBCA24F_52FB_44D3_9992_2183E560B96F__INCLUDED_)
#define AFX_FULLTIMEDLG_H__3DBCA24F_52FB_44D3_9992_2183E560B96F__INCLUDED_

#include "FulltimeSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FulltimeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFulltimeDlg dialog

class CFulltimeDlg : public CDialog
{
// Construction
public:
	CFulltimeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFulltimeDlg)
	enum { IDD = IDD_DIALOG_FULLTIME };
	CListCtrl	m_ctrFulltime;
	CButton	m_bntSave;
	CString	m_strCode;
	CString	m_strLocation;
	CString	m_strSetting;
	CString	m_strFruit;
	CString	m_strContent;
	CString	m_strName;
	CString	m_strLeader;
	//添加代码
	int m_iCondition;
	//添加代码结束
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFulltimeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFulltimeDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonSave();
	afx_msg void OnButtonSearch();
	afx_msg void OnButtonUpdate();
	afx_msg void OnClickListFulltime(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CFulltimeSet m_recordset;
	void DataUpdate(CString strSQL);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FULLTIMEDLG_H__3DBCA24F_52FB_44D3_9992_2183E560B96F__INCLUDED_)

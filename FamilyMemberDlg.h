#if !defined(AFX_FAMILYMEMBERDLG_H__6A207309_9B01_47C4_9DE1_F9F5EB5E688F__INCLUDED_)
#define AFX_FAMILYMEMBERDLG_H__6A207309_9B01_47C4_9DE1_F9F5EB5E688F__INCLUDED_

#include "FamilyMemberSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FamilyMemberDlg.h : header file
//
//添加代码
//如果前面添加CFamilyMemberSet变量m_recordset时ClassView未自动添加则需手动添加
#include "FamilyMemberSet.h"
/////////////////////////////////////////////////////////////////////////////
// CFamilyMemberDlg dialog

class CFamilyMemberDlg : public CDialog
{
// Construction
public:
	void DataUpdate(CString strCode);
	CString m_strCode;
	CFamilyMemberDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFamilyMemberDlg)
	enum { IDD = IDD_DIALOG_HFAMILYMEMBER };
	CListCtrl	m_ctrFamily;
	CButton	m_bntSave;
	CButton	m_bntUpdate;
	CButton	m_bntDelete;
	CButton	m_bntAdd;
	CTime	m_tmBirth;
	CString	m_strPolitical;
	CString	m_strCID;
	CString	m_strName;
	CString	m_strDuty;
	CString	m_strEducation;
	CString	m_strPhone;
	CString	m_strRelation;
	CString	m_strCompany;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFamilyMemberDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFamilyMemberDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonUpdate();
	afx_msg void OnButtonSave();
	afx_msg void OnClickListFamily(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CFamilyMemberSet m_recordset;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FAMILYMEMBERDLG_H__6A207309_9B01_47C4_9DE1_F9F5EB5E688F__INCLUDED_)

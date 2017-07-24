#if !defined(AFX_BASEARCHIVEDLG_H__922D045F_51C5_4D0A_BB38_E48064219526__INCLUDED_)
#define AFX_BASEARCHIVEDLG_H__922D045F_51C5_4D0A_BB38_E48064219526__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BaseArchiveDlg.h : header file
//
//添加代码
#include "StaffSet.h"
//添加代码结束
/////////////////////////////////////////////////////////////////////////////
// CBaseArchiveDlg dialog

class CBaseArchiveDlg : public CDialog
{
// Construction
public:
	BOOL Save();
	void DataUpdate();
	BOOL Update();
	void Purge();
	CStaffSet * m_recordset;
	CBaseArchiveDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBaseArchiveDlg)
	enum { IDD = IDD_HUMAN_HBASEARCHIVE };
	CComboBox	m_ctrJob;
	CComboBox	m_ctrTechnical;
	CComboBox	m_ctrDept;
	CComboBox	m_ctrDegree;
	CComboBox	m_ctrSalary;
	CComboBox	m_ctrPost;
	CComboBox	m_ctrRace;
	CComboBox	m_ctrParty;
	CEdit	m_ctrCode;
	CString	m_strCode;
	CString	m_strName;
	CString	m_strSex;
	CTime	m_tmBirth;
	CString	m_strMarriage;
	CString	m_strAge;
	CString	m_strParty;
	CString	m_strRace;
	CString	m_strCID;
	CTime	m_tmWorkDate;
	CString	m_strPost;
	CString	m_strNative;
	CTime	m_tmEntryDate;
	CString	m_strSalary;
	CString	m_strDegree;
	CString	m_strDept;
	CString	m_strTechnical;
	CString	m_strJob;
	CString	m_strOfficePhone;
	CString	m_strMobilePhone;
	CString	m_strEmail;
	CString	m_strUniversity;
	CString	m_strSubject;
	CTime	m_tmGraduate;
	CString	m_strAddress;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseArchiveDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBaseArchiveDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASEARCHIVEDLG_H__922D045F_51C5_4D0A_BB38_E48064219526__INCLUDED_)

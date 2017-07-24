#if !defined(AFX_EDUCATIONDEGREEDLG_H__999FE0F2_E2E0_41A2_83A4_BD15E130BB90__INCLUDED_)
#define AFX_EDUCATIONDEGREEDLG_H__999FE0F2_E2E0_41A2_83A4_BD15E130BB90__INCLUDED_

#include "EducationDegreeSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EducationDegreeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEducationDegreeDlg dialog

class CEducationDegreeDlg : public CDialog
{
// Construction
public:
	CEducationDegreeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEducationDegreeDlg)
	enum { IDD = IDD_DIALOG_EDUCATIONDEGREE };
	CListCtrl	m_ctrDegree;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEducationDegreeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEducationDegreeDlg)
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CEducationDegreeSet m_recordset;
	void DataUpdate();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDUCATIONDEGREEDLG_H__999FE0F2_E2E0_41A2_83A4_BD15E130BB90__INCLUDED_)

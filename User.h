#if !defined(AFX_USER_H__95C11223_60A6_4E3B_BF21_77A23530337F__INCLUDED_)
#define AFX_USER_H__95C11223_60A6_4E3B_BF21_77A23530337F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// User.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUser recordset

class CUser : public CRecordset
{
public:
	CUser(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CUser)

// Field/Param Data
	//{{AFX_FIELD(CUser, CRecordset)
	CString	m_customer;
	CString	m_password;
	BOOL	m_privilege;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUser)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USER_H__95C11223_60A6_4E3B_BF21_77A23530337F__INCLUDED_)

#if !defined(AFX_DEPARTMENTSECTIONSET_H__5A13B86E_A34F_47C6_BDB7_104704AB73D2__INCLUDED_)
#define AFX_DEPARTMENTSECTIONSET_H__5A13B86E_A34F_47C6_BDB7_104704AB73D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DepartmentSectionSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDepartmentSectionSet recordset

class CDepartmentSectionSet : public CRecordset
{
public:
	CDepartmentSectionSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CDepartmentSectionSet)

// Field/Param Data
	//{{AFX_FIELD(CDepartmentSectionSet, CRecordset)
	long	m_ID;
	CString	m_division;
	CString	m_description;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDepartmentSectionSet)
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

#endif // !defined(AFX_DEPARTMENTSECTIONSET_H__5A13B86E_A34F_47C6_BDB7_104704AB73D2__INCLUDED_)

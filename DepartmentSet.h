#if !defined(AFX_DEPARTMENTSET_H__FB05A97C_FF79_4498_AAE6_C4D5AD5C0692__INCLUDED_)
#define AFX_DEPARTMENTSET_H__FB05A97C_FF79_4498_AAE6_C4D5AD5C0692__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DepartmentSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDepartmentSet recordset

class CDepartmentSet : public CRecordset
{
public:
	CDepartmentSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CDepartmentSet)

// Field/Param Data
	//{{AFX_FIELD(CDepartmentSet, CRecordset)
	CString	m_code;
	CString	m_name;
	CString	m_leader;
	CString	m_location;
	CString	m_organization;
	CString	m_teach;
	CString	m_research;
	CString	m_student;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDepartmentSet)
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

#endif // !defined(AFX_DEPARTMENTSET_H__FB05A97C_FF79_4498_AAE6_C4D5AD5C0692__INCLUDED_)

#if !defined(AFX_CLASSTEACHINGSET_H__2164BD1C_B10E_448A_A035_C6E9D4A1D851__INCLUDED_)
#define AFX_CLASSTEACHINGSET_H__2164BD1C_B10E_448A_A035_C6E9D4A1D851__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClassTeachingSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CClassTeachingSet recordset

class CClassTeachingSet : public CRecordset
{
public:
	CClassTeachingSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CClassTeachingSet)

// Field/Param Data
	//{{AFX_FIELD(CClassTeachingSet, CRecordset)
	long	m_number;
	CString	m_code;
	CString	m_annual;
	CString	m_semester;
	CString	m_course;
	CString	m_sort;
	CString	m_level;
	CString	m_class;
	CString	m_object;
	CString	m_location;
	CString	m_hour;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClassTeachingSet)
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

#endif // !defined(AFX_CLASSTEACHINGSET_H__2164BD1C_B10E_448A_A035_C6E9D4A1D851__INCLUDED_)

#if !defined(AFX_ACADEMICEDUCATIONSET_H__D4F83D4D_721C_46F5_A991_38147B8BE811__INCLUDED_)
#define AFX_ACADEMICEDUCATIONSET_H__D4F83D4D_721C_46F5_A991_38147B8BE811__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AcademicEducationSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAcademicEducationSet recordset

class CAcademicEducationSet : public CRecordset
{
public:
	CAcademicEducationSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CAcademicEducationSet)

// Field/Param Data
	//{{AFX_FIELD(CAcademicEducationSet, CRecordset)
	long	m_number;
	CString	m_code;
	CTime	m_begin;
	CTime	m_end;
	CString	m_university;
	CString	m_department;
	CString	m_major;
	CString	m_diploma;
	CString	m_degree;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAcademicEducationSet)
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

#endif // !defined(AFX_ACADEMICEDUCATIONSET_H__D4F83D4D_721C_46F5_A991_38147B8BE811__INCLUDED_)

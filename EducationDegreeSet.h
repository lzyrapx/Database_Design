#if !defined(AFX_EDUCATIONDEGREESET_H__CA29F401_22FE_4897_921A_A0B839FBB43E__INCLUDED_)
#define AFX_EDUCATIONDEGREESET_H__CA29F401_22FE_4897_921A_A0B839FBB43E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EducationDegreeSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEducationDegreeSet recordset

class CEducationDegreeSet : public CRecordset
{
public:
	CEducationDegreeSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CEducationDegreeSet)

// Field/Param Data
	//{{AFX_FIELD(CEducationDegreeSet, CRecordset)
	long	m_ID;
	CString	m_degree;
	CString	m_description;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEducationDegreeSet)
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

#endif // !defined(AFX_EDUCATIONDEGREESET_H__CA29F401_22FE_4897_921A_A0B839FBB43E__INCLUDED_)

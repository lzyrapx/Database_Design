#if !defined(AFX_WAGELEVELSET_H__2D0A04A9_3290_4D62_93F5_7288166AC210__INCLUDED_)
#define AFX_WAGELEVELSET_H__2D0A04A9_3290_4D62_93F5_7288166AC210__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WageLevelSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWageLevelSet recordset

class CWageLevelSet : public CRecordset
{
public:
	CWageLevelSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CWageLevelSet)

// Field/Param Data
	//{{AFX_FIELD(CWageLevelSet, CRecordset)
	long	m_ID;
	CString	m_salary;
	CString	m_description;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWageLevelSet)
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

#endif // !defined(AFX_WAGELEVELSET_H__2D0A04A9_3290_4D62_93F5_7288166AC210__INCLUDED_)

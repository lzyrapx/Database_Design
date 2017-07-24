#if !defined(AFX_SECTIONSET_H__B9F32818_BC9D_447B_8154_8089FC261FF0__INCLUDED_)
#define AFX_SECTIONSET_H__B9F32818_BC9D_447B_8154_8089FC261FF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SectionSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSectionSet recordset

class CSectionSet : public CRecordset
{
public:
	CSectionSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CSectionSet)

// Field/Param Data
	//{{AFX_FIELD(CSectionSet, CRecordset)
	CString	m_code;
	CString	m_name;
	CString	m_leader;
	CString	m_location;
	CString	m_organization;
	CString	m_rule;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSectionSet)
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

#endif // !defined(AFX_SECTIONSET_H__B9F32818_BC9D_447B_8154_8089FC261FF0__INCLUDED_)

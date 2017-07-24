#if !defined(AFX_TECHNICALPOSTSET_H__6B2A0A04_359B_4E21_B89C_C8253C08E790__INCLUDED_)
#define AFX_TECHNICALPOSTSET_H__6B2A0A04_359B_4E21_B89C_C8253C08E790__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TechnicalPostSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTechnicalPostSet recordset

class CTechnicalPostSet : public CRecordset
{
public:
	CTechnicalPostSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CTechnicalPostSet)

// Field/Param Data
	//{{AFX_FIELD(CTechnicalPostSet, CRecordset)
	long	m_ID;
	CString	m_title;
	CString	m_description;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTechnicalPostSet)
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

#endif // !defined(AFX_TECHNICALPOSTSET_H__6B2A0A04_359B_4E21_B89C_C8253C08E790__INCLUDED_)

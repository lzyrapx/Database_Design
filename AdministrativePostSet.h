#if !defined(AFX_ADMINISTRATIVEPOSTSET_H__7BB23535_FA90_460D_87D4_69E6E54F10BD__INCLUDED_)
#define AFX_ADMINISTRATIVEPOSTSET_H__7BB23535_FA90_460D_87D4_69E6E54F10BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AdministrativePostSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAdministrativePostSet recordset

class CAdministrativePostSet : public CRecordset
{
public:
	CAdministrativePostSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CAdministrativePostSet)

// Field/Param Data
	//{{AFX_FIELD(CAdministrativePostSet, CRecordset)
	long	m_ID;
	CString	m_rank;
	CString	m_description;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdministrativePostSet)
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

#endif // !defined(AFX_ADMINISTRATIVEPOSTSET_H__7BB23535_FA90_460D_87D4_69E6E54F10BD__INCLUDED_)

#if !defined(AFX_AUXILIARYSET_H__66CADB4E_8531_44A5_BD88_56ECE63E4FC5__INCLUDED_)
#define AFX_AUXILIARYSET_H__66CADB4E_8531_44A5_BD88_56ECE63E4FC5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AuxiliarySet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAuxiliarySet recordset

class CAuxiliarySet : public CRecordset
{
public:
	CAuxiliarySet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CAuxiliarySet)

// Field/Param Data
	//{{AFX_FIELD(CAuxiliarySet, CRecordset)
	CString	m_code;
	CString	m_name;
	CString	m_leader;
	CString	m_location;
	CString	m_organization;
	CString	m_duty;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAuxiliarySet)
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

#endif // !defined(AFX_AUXILIARYSET_H__66CADB4E_8531_44A5_BD88_56ECE63E4FC5__INCLUDED_)

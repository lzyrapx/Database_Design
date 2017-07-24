#if !defined(AFX_FAMILYMEMBERSET_H__19823A3A_90E1_493A_9E5D_7C45E5906456__INCLUDED_)
#define AFX_FAMILYMEMBERSET_H__19823A3A_90E1_493A_9E5D_7C45E5906456__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FamilyMemberSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFamilyMemberSet recordset

class CFamilyMemberSet : public CRecordset
{
public:
	CFamilyMemberSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CFamilyMemberSet)

// Field/Param Data
	//{{AFX_FIELD(CFamilyMemberSet, CRecordset)
	long	m_number;
	CString	m_code;
	CString	m_name;
	CString	m_identity_Card;
	CString	m_relation;
	CTime	m_birth;
	CString	m_company;
	CString	m_phone;
	CString	m_duty;
	CString	m_political;
	CString	m_education;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFamilyMemberSet)
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

#endif // !defined(AFX_FAMILYMEMBERSET_H__19823A3A_90E1_493A_9E5D_7C45E5906456__INCLUDED_)

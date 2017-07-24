#if !defined(AFX_STAFFSET_H__D52D9B1D_0E1D_4D91_91C0_2AC36780F97E__INCLUDED_)
#define AFX_STAFFSET_H__D52D9B1D_0E1D_4D91_91C0_2AC36780F97E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StaffSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStaffSet recordset

class CStaffSet : public CRecordset
{
public:
	CStaffSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CStaffSet)

// Field/Param Data
	//{{AFX_FIELD(CStaffSet, CRecordset)
	CString	m_code;
	CString	m_name;
	CString	m_sex;
	CTime	m_birth;
	CString	m_marriage;
	int		m_age;
	CString	m_party;
	CString	m_race;
	CString	m_identity_Card;
	CTime	m_word_Date;
	CString	m_post;
	CString	m_native;
	CTime	m_enty_Date;
	CString	m_salary;
	CString	m_degree;
	CString	m_department;
	CString	m_technical;
	CString	m_job;
	CString	m_office_Phone;
	CString	m_mobile_Phone;
	CString	m_email;
	CString	m_university;
	CString	m_subject;
	CTime	m_graduate_Date;
	CString	m_address;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStaffSet)
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

#endif // !defined(AFX_STAFFSET_H__D52D9B1D_0E1D_4D91_91C0_2AC36780F97E__INCLUDED_)

#if !defined(AFX_CONTACTSSET_H__ED8B7501_2542_4043_B4D1_E14F2B61AF77__INCLUDED_)
#define AFX_CONTACTSSET_H__ED8B7501_2542_4043_B4D1_E14F2B61AF77__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ContactsSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CContactsSet recordset

class CContactsSet : public CRecordset
{
public:
	CContactsSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CContactsSet)

// Field/Param Data
	//{{AFX_FIELD(CContactsSet, CRecordset)
	long	m_number;
	CString	m_name;
	CString	m_sex;
	CString	m_fPhone;
	CString	m_oPhone;
	CString	m_mPhone;
	CString	m_short;
	CString	m_QQ;
	CString	m_weChat;
	CString	m_email;
	CString	m_unit;
	CString	m_remark;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CContactsSet)
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

#endif // !defined(AFX_CONTACTSSET_H__ED8B7501_2542_4043_B4D1_E14F2B61AF77__INCLUDED_)

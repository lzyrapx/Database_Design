#if !defined(AFX_TECHNICALACCESSSET_H__3F7F0E2F_7232_4BBD_A673_328A30FAB56B__INCLUDED_)
#define AFX_TECHNICALACCESSSET_H__3F7F0E2F_7232_4BBD_A673_328A30FAB56B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TechnicalAccessSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTechnicalAccessSet recordset

class CTechnicalAccessSet : public CRecordset
{
public:
	CTechnicalAccessSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CTechnicalAccessSet)

// Field/Param Data
	//{{AFX_FIELD(CTechnicalAccessSet, CRecordset)
	long	m_numder;
	CString	m_code;
	CString	m_title;
	CString	m_mode;
	CString	m_unit;
	CTime	m_assess_Date;
	CString	m_hire;
	CTime	m_begin;
	CTime	m_end;
	CString	m_employ;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTechnicalAccessSet)
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

#endif // !defined(AFX_TECHNICALACCESSSET_H__3F7F0E2F_7232_4BBD_A673_328A30FAB56B__INCLUDED_)

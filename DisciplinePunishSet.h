#if !defined(AFX_DISCIPLINEPUNISHSET_H__3A418E52_D33B_4697_9B7E_15206F03D694__INCLUDED_)
#define AFX_DISCIPLINEPUNISHSET_H__3A418E52_D33B_4697_9B7E_15206F03D694__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DisciplinePunishSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDisciplinePunishSet recordset

class CDisciplinePunishSet : public CRecordset
{
public:
	CDisciplinePunishSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CDisciplinePunishSet)

// Field/Param Data
	//{{AFX_FIELD(CDisciplinePunishSet, CRecordset)
	long	m_number;
	CString	m_code;
	CString	m_sort;
	CString	m_period;
	CString	m_preason;
	CTime	m_pdate;
	CTime	m_ddate;
	CString	m_dreason;
	CString	m_unit;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDisciplinePunishSet)
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

#endif // !defined(AFX_DISCIPLINEPUNISHSET_H__3A418E52_D33B_4697_9B7E_15206F03D694__INCLUDED_)

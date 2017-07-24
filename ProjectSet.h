#if !defined(AFX_PROJECTSET_H__40C3396A_671E_44C8_B8BC_41DF5FEB6EE4__INCLUDED_)
#define AFX_PROJECTSET_H__40C3396A_671E_44C8_B8BC_41DF5FEB6EE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProjectSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProjectSet recordset

class CProjectSet : public CRecordset
{
public:
	CProjectSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CProjectSet)

// Field/Param Data
	//{{AFX_FIELD(CProjectSet, CRecordset)
	long	m_numder;
	CString	m_code;
	CString	m_title;
	CString	m_type;
	CString	m_sort;
	CString	m_level;
	CString	m_rate;
	CString	m_state;
	CString	m_host;
	CString	m_rank;
	CString	m_first;
	CTime	m_release;
	CString	m_unit;
	CString	m_cost;
	CString	m_limit;
	CTime	m_begin;
	CTime	m_end;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProjectSet)
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

#endif // !defined(AFX_PROJECTSET_H__40C3396A_671E_44C8_B8BC_41DF5FEB6EE4__INCLUDED_)

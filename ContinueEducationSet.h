#if !defined(AFX_CONTINUEEDUCATIONSET_H__592C103D_76ED_4BD6_8E97_7962A4880C30__INCLUDED_)
#define AFX_CONTINUEEDUCATIONSET_H__592C103D_76ED_4BD6_8E97_7962A4880C30__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ContinueEducationSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CContinueEducationSet recordset

class CContinueEducationSet : public CRecordset
{
public:
	CContinueEducationSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CContinueEducationSet)

// Field/Param Data
	//{{AFX_FIELD(CContinueEducationSet, CRecordset)
	long	m_number;
	CString	m_code;
	CTime	m_begin;
	CTime	m_end;
	CString	m_mode;
	CString	m_effect;
	CString	m_content;
	CString	m_unit;
	CString	m_location;
	CString	m_cost;
	CString	m_hour;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CContinueEducationSet)
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

#endif // !defined(AFX_CONTINUEEDUCATIONSET_H__592C103D_76ED_4BD6_8E97_7962A4880C30__INCLUDED_)

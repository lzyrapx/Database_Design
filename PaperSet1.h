#if !defined(AFX_PAPERSET1_H__9342C773_E64C_49C6_93A9_4EA33B7B87E3__INCLUDED_)
#define AFX_PAPERSET1_H__9342C773_E64C_49C6_93A9_4EA33B7B87E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PaperSet1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPaperSet1 recordset

class CPaperSet1 : public CRecordset
{
public:
	CPaperSet1(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CPaperSet1)

// Field/Param Data
	//{{AFX_FIELD(CPaperSet1, CRecordset)
	long	m_number;
	CString	m_code;
	CString	m_title;
	CString	m_rank;
	CString	m_publication;
	CTime	m_pub_time;
	CString	m_pub_year;
	CString	m_volume;
	CString	m_issue;
	CString	m_page;
	CString	m_level;
	CString	m_type;
	CString	m_index;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPaperSet1)
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

#endif // !defined(AFX_PAPERSET1_H__9342C773_E64C_49C6_93A9_4EA33B7B87E3__INCLUDED_)

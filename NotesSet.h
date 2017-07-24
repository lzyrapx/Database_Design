#if !defined(AFX_NOTESSET_H__30434C18_4785_422F_AB14_402F8F4A8D1E__INCLUDED_)
#define AFX_NOTESSET_H__30434C18_4785_422F_AB14_402F8F4A8D1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NotesSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNotesSet recordset

class CNotesSet : public CRecordset
{
public:
	CNotesSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CNotesSet)

// Field/Param Data
	//{{AFX_FIELD(CNotesSet, CRecordset)
	long	m_number;
	CTime	m_rDate;
	CString	m_writer;
	CString	m_wUnit;
	CString	m_type;
	CString	m_title;
	CString	m_content;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNotesSet)
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

#endif // !defined(AFX_NOTESSET_H__30434C18_4785_422F_AB14_402F8F4A8D1E__INCLUDED_)

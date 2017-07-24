#if !defined(AFX_APPENDANTSET_H__DF456878_3D30_47B2_9566_3737B5C88969__INCLUDED_)
#define AFX_APPENDANTSET_H__DF456878_3D30_47B2_9566_3737B5C88969__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AppendantSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAppendantSet recordset

class CAppendantSet : public CRecordset
{
public:
	CAppendantSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CAppendantSet)

// Field/Param Data
	//{{AFX_FIELD(CAppendantSet, CRecordset)
	CString	m_code;
	CString	m_name;
	CString	m_leader;
	CString	m_location;
	CString	m_organization;
	CString	m_regulation;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAppendantSet)
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

#endif // !defined(AFX_APPENDANTSET_H__DF456878_3D30_47B2_9566_3737B5C88969__INCLUDED_)

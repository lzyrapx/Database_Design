#if !defined(AFX_FULLTIMESET_H__E3131A38_E9CF_485E_9BFB_3D65E13A7CE2__INCLUDED_)
#define AFX_FULLTIMESET_H__E3131A38_E9CF_485E_9BFB_3D65E13A7CE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FulltimeSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFulltimeSet recordset

class CFulltimeSet : public CRecordset
{
public:
	CFulltimeSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CFulltimeSet)

// Field/Param Data
	//{{AFX_FIELD(CFulltimeSet, CRecordset)
	CString	m_code;
	CString	m_name;
	CString	m_leader;
	CString	m_location;
	CString	m_organization;
	CString	m_fruit;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFulltimeSet)
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

#endif // !defined(AFX_FULLTIMESET_H__E3131A38_E9CF_485E_9BFB_3D65E13A7CE2__INCLUDED_)

#if !defined(AFX_POLITICALSTATUSSET_H__6DF892DE_0310_42C9_88C9_30CCFE7DC8EB__INCLUDED_)
#define AFX_POLITICALSTATUSSET_H__6DF892DE_0310_42C9_88C9_30CCFE7DC8EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PoliticalStatusSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPoliticalStatusSet recordset

class CPoliticalStatusSet : public CRecordset
{
public:
	CPoliticalStatusSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CPoliticalStatusSet)

// Field/Param Data
	//{{AFX_FIELD(CPoliticalStatusSet, CRecordset)
	long	m_ID;
	CString	m_party;
	CString	m_description;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPoliticalStatusSet)
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

#endif // !defined(AFX_POLITICALSTATUSSET_H__6DF892DE_0310_42C9_88C9_30CCFE7DC8EB__INCLUDED_)

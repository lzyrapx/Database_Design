#if !defined(AFX_NATIONINFORMATIONSET_H__C42DF671_42AA_486B_AD7F_487FACB6D05B__INCLUDED_)
#define AFX_NATIONINFORMATIONSET_H__C42DF671_42AA_486B_AD7F_487FACB6D05B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NationInformationSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNationInformationSet recordset

class CNationInformationSet : public CRecordset
{
public:
	CNationInformationSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CNationInformationSet)

// Field/Param Data
	//{{AFX_FIELD(CNationInformationSet, CRecordset)
	long	m_ID;
	CString	m_folk;
	CString	m_description;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNationInformationSet)
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

#endif // !defined(AFX_NATIONINFORMATIONSET_H__C42DF671_42AA_486B_AD7F_487FACB6D05B__INCLUDED_)

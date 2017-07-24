#if !defined(AFX_POSITIONINFORMATIONSET_H__FD2099AD_925F_4B2B_8CD1_9D3F8D1B5CE6__INCLUDED_)
#define AFX_POSITIONINFORMATIONSET_H__FD2099AD_925F_4B2B_8CD1_9D3F8D1B5CE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PositionInformationSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPositionInformationSet recordset

class CPositionInformationSet : public CRecordset
{
public:
	CPositionInformationSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CPositionInformationSet)

// Field/Param Data
	//{{AFX_FIELD(CPositionInformationSet, CRecordset)
	long	m_ID;
	CString	m_post;
	CString	m_description;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPositionInformationSet)
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

#endif // !defined(AFX_POSITIONINFORMATIONSET_H__FD2099AD_925F_4B2B_8CD1_9D3F8D1B5CE6__INCLUDED_)

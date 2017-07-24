#if !defined(AFX_WORKEXPERIENCESET_H__F6E44129_9A6A_412B_B7EA_7360DD3B7475__INCLUDED_)
#define AFX_WORKEXPERIENCESET_H__F6E44129_9A6A_412B_B7EA_7360DD3B7475__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WorkExperienceSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWorkExperienceSet recordset

class CWorkExperienceSet : public CRecordset
{
public:
	CWorkExperienceSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CWorkExperienceSet)

// Field/Param Data
	//{{AFX_FIELD(CWorkExperienceSet, CRecordset)
	long	m_number;
	CString	m_code;
	CTime	m_begin_Date;
	CTime	m_end_Date;
	CString	m_company;
	CString	m_department;
	CString	m_duty;
	CString	m_technical;
	CString	m_education;
	CString	m_location;
	CString	m_proof;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWorkExperienceSet)
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

#endif // !defined(AFX_WORKEXPERIENCESET_H__F6E44129_9A6A_412B_B7EA_7360DD3B7475__INCLUDED_)

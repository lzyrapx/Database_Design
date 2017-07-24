#if !defined(AFX_REWARDRECORDSET_H__F6E707B3_D838_46E2_84EA_AD8D9DCF2FA4__INCLUDED_)
#define AFX_REWARDRECORDSET_H__F6E707B3_D838_46E2_84EA_AD8D9DCF2FA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RewardRecordSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRewardRecordSet recordset

class CRewardRecordSet : public CRecordset
{
public:
	CRewardRecordSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CRewardRecordSet)

// Field/Param Data
	//{{AFX_FIELD(CRewardRecordSet, CRecordset)
	long	m_number;
	CString	m_code;
	CString	m_title;
	CString	m_sort;
	CString	m_level;
	CString	m_unit;
	CString	m_category;
	CTime	m_date;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRewardRecordSet)
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

#endif // !defined(AFX_REWARDRECORDSET_H__F6E707B3_D838_46E2_84EA_AD8D9DCF2FA4__INCLUDED_)

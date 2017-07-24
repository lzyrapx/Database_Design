#if !defined(AFX_MEETINGRECORDSET_H__9B6CE3A8_7AA4_4A79_889E_D799960F5888__INCLUDED_)
#define AFX_MEETINGRECORDSET_H__9B6CE3A8_7AA4_4A79_889E_D799960F5888__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MeetingRecordSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMeetingRecordSet recordset

class CMeetingRecordSet : public CRecordset
{
public:
	CMeetingRecordSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CMeetingRecordSet)

// Field/Param Data
	//{{AFX_FIELD(CMeetingRecordSet, CRecordset)
	long	m_number;
	CTime	m_mDate;
	CString	m_location;
	CString	m_sort;
	CString	m_subject;
	CString	m_host_Unit;
	CString	m_participate_Unit;
	CString	m_host;
	CString	m_writer;
	CString	m_content;
	CString	m_remark;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMeetingRecordSet)
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

#endif // !defined(AFX_MEETINGRECORDSET_H__9B6CE3A8_7AA4_4A79_889E_D799960F5888__INCLUDED_)

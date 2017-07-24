// MeetingRecordSet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "MeetingRecordSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMeetingRecordSet

IMPLEMENT_DYNAMIC(CMeetingRecordSet, CRecordset)

CMeetingRecordSet::CMeetingRecordSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CMeetingRecordSet)
	m_number = 0;
	m_location = _T("");
	m_sort = _T("");
	m_subject = _T("");
	m_host_Unit = _T("");
	m_participate_Unit = _T("");
	m_host = _T("");
	m_writer = _T("");
	m_content = _T("");
	m_remark = _T("");
	m_nFields = 11;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CMeetingRecordSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CMeetingRecordSet::GetDefaultSQL()
{
	return _T("[meetingRecord]");
}

void CMeetingRecordSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CMeetingRecordSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[number]"), m_number);
	RFX_Date(pFX, _T("[mDate]"), m_mDate);
	RFX_Text(pFX, _T("[location]"), m_location);
	RFX_Text(pFX, _T("[sort]"), m_sort);
	RFX_Text(pFX, _T("[subject]"), m_subject);
	RFX_Text(pFX, _T("[host Unit]"), m_host_Unit);
	RFX_Text(pFX, _T("[participate Unit]"), m_participate_Unit);
	RFX_Text(pFX, _T("[host]"), m_host);
	RFX_Text(pFX, _T("[writer]"), m_writer);
	RFX_Text(pFX, _T("[content]"), m_content);
	RFX_Text(pFX, _T("[remark]"), m_remark);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CMeetingRecordSet diagnostics

#ifdef _DEBUG
void CMeetingRecordSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMeetingRecordSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

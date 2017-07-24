// PoliticalStatusSet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "PoliticalStatusSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPoliticalStatusSet

IMPLEMENT_DYNAMIC(CPoliticalStatusSet, CRecordset)

CPoliticalStatusSet::CPoliticalStatusSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CPoliticalStatusSet)
	m_ID = 0;
	m_party = _T("");
	m_description = _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CPoliticalStatusSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CPoliticalStatusSet::GetDefaultSQL()
{
	return _T("[politicalStatus]");
}

void CPoliticalStatusSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CPoliticalStatusSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[party]"), m_party);
	RFX_Text(pFX, _T("[description]"), m_description);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CPoliticalStatusSet diagnostics

#ifdef _DEBUG
void CPoliticalStatusSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CPoliticalStatusSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

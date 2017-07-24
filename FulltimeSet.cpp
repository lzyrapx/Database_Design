// FulltimeSet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "FulltimeSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFulltimeSet

IMPLEMENT_DYNAMIC(CFulltimeSet, CRecordset)

CFulltimeSet::CFulltimeSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CFulltimeSet)
	m_code = _T("");
	m_name = _T("");
	m_leader = _T("");
	m_location = _T("");
	m_organization = _T("");
	m_fruit = _T("");
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CFulltimeSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CFulltimeSet::GetDefaultSQL()
{
	return _T("[fulltime]");
}

void CFulltimeSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CFulltimeSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[code]"), m_code);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[leader]"), m_leader);
	RFX_Text(pFX, _T("[location]"), m_location);
	RFX_Text(pFX, _T("[organization]"), m_organization);
	RFX_Text(pFX, _T("[fruit]"), m_fruit);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CFulltimeSet diagnostics

#ifdef _DEBUG
void CFulltimeSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CFulltimeSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

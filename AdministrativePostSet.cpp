// AdministrativePostSet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "AdministrativePostSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAdministrativePostSet

IMPLEMENT_DYNAMIC(CAdministrativePostSet, CRecordset)

CAdministrativePostSet::CAdministrativePostSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CAdministrativePostSet)
	m_ID = 0;
	m_rank = _T("");
	m_description = _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CAdministrativePostSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CAdministrativePostSet::GetDefaultSQL()
{
	return _T("[administrativePost]");
}

void CAdministrativePostSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CAdministrativePostSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[rank]"), m_rank);
	RFX_Text(pFX, _T("[description]"), m_description);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CAdministrativePostSet diagnostics

#ifdef _DEBUG
void CAdministrativePostSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CAdministrativePostSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

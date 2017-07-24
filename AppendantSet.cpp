// AppendantSet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "AppendantSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAppendantSet

IMPLEMENT_DYNAMIC(CAppendantSet, CRecordset)

CAppendantSet::CAppendantSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CAppendantSet)
	m_code = _T("");
	m_name = _T("");
	m_leader = _T("");
	m_location = _T("");
	m_organization = _T("");
	m_regulation = _T("");
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CAppendantSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CAppendantSet::GetDefaultSQL()
{
	return _T("[appendant]");
}

void CAppendantSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CAppendantSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[code]"), m_code);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[leader]"), m_leader);
	RFX_Text(pFX, _T("[location]"), m_location);
	RFX_Text(pFX, _T("[organization]"), m_organization);
	RFX_Text(pFX, _T("[regulation]"), m_regulation);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CAppendantSet diagnostics

#ifdef _DEBUG
void CAppendantSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CAppendantSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

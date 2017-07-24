// SectionSet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "SectionSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSectionSet

IMPLEMENT_DYNAMIC(CSectionSet, CRecordset)

CSectionSet::CSectionSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CSectionSet)
	m_code = _T("");
	m_name = _T("");
	m_leader = _T("");
	m_location = _T("");
	m_organization = _T("");
	m_rule = _T("");
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CSectionSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CSectionSet::GetDefaultSQL()
{
	return _T("[section]");
}

void CSectionSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CSectionSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[code]"), m_code);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[leader]"), m_leader);
	RFX_Text(pFX, _T("[location]"), m_location);
	RFX_Text(pFX, _T("[organization]"), m_organization);
	RFX_Text(pFX, _T("[rule]"), m_rule);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CSectionSet diagnostics

#ifdef _DEBUG
void CSectionSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CSectionSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

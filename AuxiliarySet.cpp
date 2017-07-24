// AuxiliarySet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "AuxiliarySet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAuxiliarySet

IMPLEMENT_DYNAMIC(CAuxiliarySet, CRecordset)

CAuxiliarySet::CAuxiliarySet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CAuxiliarySet)
	m_code = _T("");
	m_name = _T("");
	m_leader = _T("");
	m_location = _T("");
	m_organization = _T("");
	m_duty = _T("");
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CAuxiliarySet::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CAuxiliarySet::GetDefaultSQL()
{
	return _T("[auxiliary]");
}

void CAuxiliarySet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CAuxiliarySet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[code]"), m_code);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[leader]"), m_leader);
	RFX_Text(pFX, _T("[location]"), m_location);
	RFX_Text(pFX, _T("[organization]"), m_organization);
	RFX_Text(pFX, _T("[duty]"), m_duty);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CAuxiliarySet diagnostics

#ifdef _DEBUG
void CAuxiliarySet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CAuxiliarySet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

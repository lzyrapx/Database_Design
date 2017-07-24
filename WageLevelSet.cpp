// WageLevelSet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "WageLevelSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWageLevelSet

IMPLEMENT_DYNAMIC(CWageLevelSet, CRecordset)

CWageLevelSet::CWageLevelSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CWageLevelSet)
	m_ID = 0;
	m_salary = _T("");
	m_description = _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CWageLevelSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CWageLevelSet::GetDefaultSQL()
{
	return _T("[wageLevel]");
}

void CWageLevelSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CWageLevelSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[salary]"), m_salary);
	RFX_Text(pFX, _T("[description]"), m_description);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CWageLevelSet diagnostics

#ifdef _DEBUG
void CWageLevelSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CWageLevelSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

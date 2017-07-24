// TechnicalPostSet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "TechnicalPostSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTechnicalPostSet

IMPLEMENT_DYNAMIC(CTechnicalPostSet, CRecordset)

CTechnicalPostSet::CTechnicalPostSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CTechnicalPostSet)
	m_ID = 0;
	m_title = _T("");
	m_description = _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CTechnicalPostSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CTechnicalPostSet::GetDefaultSQL()
{
	return _T("[technicalPost]");
}

void CTechnicalPostSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CTechnicalPostSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[title]"), m_title);
	RFX_Text(pFX, _T("[description]"), m_description);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CTechnicalPostSet diagnostics

#ifdef _DEBUG
void CTechnicalPostSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CTechnicalPostSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

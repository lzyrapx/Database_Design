// TechnicalAccessSet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "TechnicalAccessSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTechnicalAccessSet

IMPLEMENT_DYNAMIC(CTechnicalAccessSet, CRecordset)

CTechnicalAccessSet::CTechnicalAccessSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CTechnicalAccessSet)
	m_numder = 0;
	m_code = _T("");
	m_title = _T("");
	m_mode = _T("");
	m_unit = _T("");
	m_hire = _T("");
	m_employ = _T("");
	m_nFields = 10;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CTechnicalAccessSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CTechnicalAccessSet::GetDefaultSQL()
{
	return _T("[technicalAssess]");
}

void CTechnicalAccessSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CTechnicalAccessSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[numder]"), m_numder);
	RFX_Text(pFX, _T("[code]"), m_code);
	RFX_Text(pFX, _T("[title]"), m_title);
	RFX_Text(pFX, _T("[mode]"), m_mode);
	RFX_Text(pFX, _T("[unit]"), m_unit);
	RFX_Date(pFX, _T("[assess Date]"), m_assess_Date);
	RFX_Text(pFX, _T("[hire]"), m_hire);
	RFX_Date(pFX, _T("[begin]"), m_begin);
	RFX_Date(pFX, _T("[end]"), m_end);
	RFX_Text(pFX, _T("[employ]"), m_employ);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CTechnicalAccessSet diagnostics

#ifdef _DEBUG
void CTechnicalAccessSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CTechnicalAccessSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

// DisciplinePunishSet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "DisciplinePunishSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDisciplinePunishSet

IMPLEMENT_DYNAMIC(CDisciplinePunishSet, CRecordset)

CDisciplinePunishSet::CDisciplinePunishSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CDisciplinePunishSet)
	m_number = 0;
	m_code = _T("");
	m_sort = _T("");
	m_period = _T("");
	m_preason = _T("");
	m_dreason = _T("");
	m_unit = _T("");
	m_nFields = 9;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CDisciplinePunishSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CDisciplinePunishSet::GetDefaultSQL()
{
	return _T("[disciplinePunish]");
}

void CDisciplinePunishSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CDisciplinePunishSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[number]"), m_number);
	RFX_Text(pFX, _T("[code]"), m_code);
	RFX_Text(pFX, _T("[sort]"), m_sort);
	RFX_Text(pFX, _T("[period]"), m_period);
	RFX_Text(pFX, _T("[preason]"), m_preason);
	RFX_Date(pFX, _T("[pdate]"), m_pdate);
	RFX_Date(pFX, _T("[ddate]"), m_ddate);
	RFX_Text(pFX, _T("[dreason]"), m_dreason);
	RFX_Text(pFX, _T("[unit]"), m_unit);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CDisciplinePunishSet diagnostics

#ifdef _DEBUG
void CDisciplinePunishSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDisciplinePunishSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

// ProjectSet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "ProjectSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProjectSet

IMPLEMENT_DYNAMIC(CProjectSet, CRecordset)

CProjectSet::CProjectSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CProjectSet)
	m_numder = 0;
	m_code = _T("");
	m_title = _T("");
	m_type = _T("");
	m_sort = _T("");
	m_level = _T("");
	m_rate = _T("");
	m_state = _T("");
	m_host = _T("");
	m_rank = _T("");
	m_first = _T("");
	m_unit = _T("");
	m_cost = _T("");
	m_limit = _T("");
	m_nFields = 17;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CProjectSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CProjectSet::GetDefaultSQL()
{
	return _T("[project]");
}

void CProjectSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CProjectSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[numder]"), m_numder);
	RFX_Text(pFX, _T("[code]"), m_code);
	RFX_Text(pFX, _T("[title]"), m_title);
	RFX_Text(pFX, _T("[type]"), m_type);
	RFX_Text(pFX, _T("[sort]"), m_sort);
	RFX_Text(pFX, _T("[level]"), m_level);
	RFX_Text(pFX, _T("[rate]"), m_rate);
	RFX_Text(pFX, _T("[state]"), m_state);
	RFX_Text(pFX, _T("[host]"), m_host);
	RFX_Text(pFX, _T("[rank]"), m_rank);
	RFX_Text(pFX, _T("[first]"), m_first);
	RFX_Date(pFX, _T("[release]"), m_release);
	RFX_Text(pFX, _T("[unit]"), m_unit);
	RFX_Text(pFX, _T("[cost]"), m_cost);
	RFX_Text(pFX, _T("[limit]"), m_limit);
	RFX_Date(pFX, _T("[begin]"), m_begin);
	RFX_Date(pFX, _T("[end]"), m_end);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CProjectSet diagnostics

#ifdef _DEBUG
void CProjectSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CProjectSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

// RewardRecordSet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "RewardRecordSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRewardRecordSet

IMPLEMENT_DYNAMIC(CRewardRecordSet, CRecordset)

CRewardRecordSet::CRewardRecordSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CRewardRecordSet)
	m_number = 0;
	m_code = _T("");
	m_title = _T("");
	m_sort = _T("");
	m_level = _T("");
	m_unit = _T("");
	m_category = _T("");
	m_nFields = 8;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CRewardRecordSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CRewardRecordSet::GetDefaultSQL()
{
	return _T("[rewardRecord]");
}

void CRewardRecordSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CRewardRecordSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[number]"), m_number);
	RFX_Text(pFX, _T("[code]"), m_code);
	RFX_Text(pFX, _T("[title]"), m_title);
	RFX_Text(pFX, _T("[sort]"), m_sort);
	RFX_Text(pFX, _T("[level]"), m_level);
	RFX_Text(pFX, _T("[unit]"), m_unit);
	RFX_Text(pFX, _T("[category]"), m_category);
	RFX_Date(pFX, _T("[date]"), m_date);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CRewardRecordSet diagnostics

#ifdef _DEBUG
void CRewardRecordSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CRewardRecordSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

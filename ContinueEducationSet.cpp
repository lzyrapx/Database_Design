// ContinueEducationSet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "ContinueEducationSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CContinueEducationSet

IMPLEMENT_DYNAMIC(CContinueEducationSet, CRecordset)

CContinueEducationSet::CContinueEducationSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CContinueEducationSet)
	m_number = 0;
	m_code = _T("");
	m_mode = _T("");
	m_effect = _T("");
	m_content = _T("");
	m_unit = _T("");
	m_location = _T("");
	m_cost = _T("");
	m_hour = _T("");
	m_nFields = 11;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CContinueEducationSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CContinueEducationSet::GetDefaultSQL()
{
	return _T("[continueEducation]");
}

void CContinueEducationSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CContinueEducationSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[number]"), m_number);
	RFX_Text(pFX, _T("[code]"), m_code);
	RFX_Date(pFX, _T("[begin]"), m_begin);
	RFX_Date(pFX, _T("[end]"), m_end);
	RFX_Text(pFX, _T("[mode]"), m_mode);
	RFX_Text(pFX, _T("[effect]"), m_effect);
	RFX_Text(pFX, _T("[content]"), m_content);
	RFX_Text(pFX, _T("[unit]"), m_unit);
	RFX_Text(pFX, _T("[location]"), m_location);
	RFX_Text(pFX, _T("[cost]"), m_cost);
	RFX_Text(pFX, _T("[hour]"), m_hour);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CContinueEducationSet diagnostics

#ifdef _DEBUG
void CContinueEducationSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CContinueEducationSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

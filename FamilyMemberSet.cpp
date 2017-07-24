// FamilyMemberSet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "FamilyMemberSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFamilyMemberSet

IMPLEMENT_DYNAMIC(CFamilyMemberSet, CRecordset)

CFamilyMemberSet::CFamilyMemberSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CFamilyMemberSet)
	m_number = 0;
	m_code = _T("");
	m_name = _T("");
	m_identity_Card = _T("");
	m_relation = _T("");
	m_company = _T("");
	m_phone = _T("");
	m_duty = _T("");
	m_political = _T("");
	m_education = _T("");
	m_nFields = 11;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CFamilyMemberSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CFamilyMemberSet::GetDefaultSQL()
{
	return _T("[familyMember]");
}

void CFamilyMemberSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CFamilyMemberSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[number]"), m_number);
	RFX_Text(pFX, _T("[code]"), m_code);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[identity Card]"), m_identity_Card);
	RFX_Text(pFX, _T("[relation]"), m_relation);
	RFX_Date(pFX, _T("[birth]"), m_birth);
	RFX_Text(pFX, _T("[company]"), m_company);
	RFX_Text(pFX, _T("[phone]"), m_phone);
	RFX_Text(pFX, _T("[duty]"), m_duty);
	RFX_Text(pFX, _T("[political]"), m_political);
	RFX_Text(pFX, _T("[education]"), m_education);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CFamilyMemberSet diagnostics

#ifdef _DEBUG
void CFamilyMemberSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CFamilyMemberSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

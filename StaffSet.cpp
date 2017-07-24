// StaffSet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "StaffSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStaffSet

IMPLEMENT_DYNAMIC(CStaffSet, CRecordset)

CStaffSet::CStaffSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CStaffSet)
	m_code = _T("");
	m_name = _T("");
	m_sex = _T("");
	m_marriage = _T("");
	m_age = 0;
	m_party = _T("");
	m_race = _T("");
	m_identity_Card = _T("");
	m_post = _T("");
	m_native = _T("");
	m_salary = _T("");
	m_degree = _T("");
	m_department = _T("");
	m_technical = _T("");
	m_job = _T("");
	m_office_Phone = _T("");
	m_mobile_Phone = _T("");
	m_email = _T("");
	m_university = _T("");
	m_subject = _T("");
	m_address = _T("");
	m_nFields = 25;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CStaffSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CStaffSet::GetDefaultSQL()
{
	return _T("[staff]");
}

void CStaffSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CStaffSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[code]"), m_code);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[sex]"), m_sex);
	RFX_Date(pFX, _T("[birth]"), m_birth);
	RFX_Text(pFX, _T("[marriage]"), m_marriage);
	RFX_Int(pFX, _T("[age]"), m_age);
	RFX_Text(pFX, _T("[party]"), m_party);
	RFX_Text(pFX, _T("[race]"), m_race);
	RFX_Text(pFX, _T("[identity Card]"), m_identity_Card);
	RFX_Date(pFX, _T("[word Date]"), m_word_Date);
	RFX_Text(pFX, _T("[post]"), m_post);
	RFX_Text(pFX, _T("[native]"), m_native);
	RFX_Date(pFX, _T("[enty Date]"), m_enty_Date);
	RFX_Text(pFX, _T("[salary]"), m_salary);
	RFX_Text(pFX, _T("[degree]"), m_degree);
	RFX_Text(pFX, _T("[department]"), m_department);
	RFX_Text(pFX, _T("[technical]"), m_technical);
	RFX_Text(pFX, _T("[job]"), m_job);
	RFX_Text(pFX, _T("[office Phone]"), m_office_Phone);
	RFX_Text(pFX, _T("[mobile Phone]"), m_mobile_Phone);
	RFX_Text(pFX, _T("[email]"), m_email);
	RFX_Text(pFX, _T("[university]"), m_university);
	RFX_Text(pFX, _T("[subject]"), m_subject);
	RFX_Date(pFX, _T("[graduate Date]"), m_graduate_Date);
	RFX_Text(pFX, _T("[address]"), m_address);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CStaffSet diagnostics

#ifdef _DEBUG
void CStaffSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CStaffSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

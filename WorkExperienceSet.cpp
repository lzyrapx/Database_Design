// WorkExperienceSet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "WorkExperienceSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWorkExperienceSet

IMPLEMENT_DYNAMIC(CWorkExperienceSet, CRecordset)

CWorkExperienceSet::CWorkExperienceSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CWorkExperienceSet)
	m_number = 0;
	m_code = _T("");
	m_company = _T("");
	m_department = _T("");
	m_duty = _T("");
	m_technical = _T("");
	m_education = _T("");
	m_location = _T("");
	m_proof = _T("");
	m_nFields = 11;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CWorkExperienceSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=");
}

CString CWorkExperienceSet::GetDefaultSQL()
{
	return _T("[wordExperience]");
}

void CWorkExperienceSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CWorkExperienceSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[number]"), m_number);
	RFX_Text(pFX, _T("[code]"), m_code);
	RFX_Date(pFX, _T("[begin Date]"), m_begin_Date);
	RFX_Date(pFX, _T("[end Date]"), m_end_Date);
	RFX_Text(pFX, _T("[company]"), m_company);
	RFX_Text(pFX, _T("[department]"), m_department);
	RFX_Text(pFX, _T("[duty]"), m_duty);
	RFX_Text(pFX, _T("[technical]"), m_technical);
	RFX_Text(pFX, _T("[education]"), m_education);
	RFX_Text(pFX, _T("[location]"), m_location);
	RFX_Text(pFX, _T("[proof]"), m_proof);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CWorkExperienceSet diagnostics

#ifdef _DEBUG
void CWorkExperienceSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CWorkExperienceSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

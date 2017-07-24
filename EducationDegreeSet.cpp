// EducationDegreeSet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "EducationDegreeSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEducationDegreeSet

IMPLEMENT_DYNAMIC(CEducationDegreeSet, CRecordset)

CEducationDegreeSet::CEducationDegreeSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CEducationDegreeSet)
	m_ID = 0;
	m_degree = _T("");
	m_description = _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CEducationDegreeSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CEducationDegreeSet::GetDefaultSQL()
{
	return _T("[educationDegree]");
}

void CEducationDegreeSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CEducationDegreeSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[degree]"), m_degree);
	RFX_Text(pFX, _T("[description]"), m_description);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CEducationDegreeSet diagnostics

#ifdef _DEBUG
void CEducationDegreeSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CEducationDegreeSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

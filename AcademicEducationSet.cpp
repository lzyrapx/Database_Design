// AcademicEducationSet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "AcademicEducationSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAcademicEducationSet

IMPLEMENT_DYNAMIC(CAcademicEducationSet, CRecordset)

CAcademicEducationSet::CAcademicEducationSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CAcademicEducationSet)
	m_number = 0;
	m_code = _T("");
	m_university = _T("");
	m_department = _T("");
	m_major = _T("");
	m_diploma = _T("");
	m_degree = _T("");
	m_nFields = 9;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CAcademicEducationSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CAcademicEducationSet::GetDefaultSQL()
{
	return _T("[academicEducation]");
}

void CAcademicEducationSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CAcademicEducationSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[number]"), m_number);
	RFX_Text(pFX, _T("[code]"), m_code);
	RFX_Date(pFX, _T("[begin]"), m_begin);
	RFX_Date(pFX, _T("[end]"), m_end);
	RFX_Text(pFX, _T("[university]"), m_university);
	RFX_Text(pFX, _T("[department]"), m_department);
	RFX_Text(pFX, _T("[major]"), m_major);
	RFX_Text(pFX, _T("[diploma]"), m_diploma);
	RFX_Text(pFX, _T("[degree]"), m_degree);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CAcademicEducationSet diagnostics

#ifdef _DEBUG
void CAcademicEducationSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CAcademicEducationSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

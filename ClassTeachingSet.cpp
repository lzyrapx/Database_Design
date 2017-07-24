// ClassTeachingSet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "ClassTeachingSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClassTeachingSet

IMPLEMENT_DYNAMIC(CClassTeachingSet, CRecordset)

CClassTeachingSet::CClassTeachingSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CClassTeachingSet)
	m_number = 0;
	m_code = _T("");
	m_annual = _T("");
	m_semester = _T("");
	m_course = _T("");
	m_sort = _T("");
	m_level = _T("");
	m_class = _T("");
	m_object = _T("");
	m_location = _T("");
	m_hour = _T("");
	m_nFields = 11;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CClassTeachingSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CClassTeachingSet::GetDefaultSQL()
{
	return _T("[classTeaching]");
}

void CClassTeachingSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CClassTeachingSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[number]"), m_number);
	RFX_Text(pFX, _T("[code]"), m_code);
	RFX_Text(pFX, _T("[annual]"), m_annual);
	RFX_Text(pFX, _T("[semester]"), m_semester);
	RFX_Text(pFX, _T("[course]"), m_course);
	RFX_Text(pFX, _T("[sort]"), m_sort);
	RFX_Text(pFX, _T("[level]"), m_level);
	RFX_Text(pFX, _T("[class]"), m_class);
	RFX_Text(pFX, _T("[object]"), m_object);
	RFX_Text(pFX, _T("[location]"), m_location);
	RFX_Text(pFX, _T("[hour]"), m_hour);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CClassTeachingSet diagnostics

#ifdef _DEBUG
void CClassTeachingSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CClassTeachingSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

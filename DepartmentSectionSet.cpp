// DepartmentSectionSet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "DepartmentSectionSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDepartmentSectionSet

IMPLEMENT_DYNAMIC(CDepartmentSectionSet, CRecordset)

CDepartmentSectionSet::CDepartmentSectionSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CDepartmentSectionSet)
	m_ID = 0;
	m_division = _T("");
	m_description = _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CDepartmentSectionSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CDepartmentSectionSet::GetDefaultSQL()
{
	return _T("[departmentSection]");
}

void CDepartmentSectionSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CDepartmentSectionSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[division]"), m_division);
	RFX_Text(pFX, _T("[description]"), m_description);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CDepartmentSectionSet diagnostics

#ifdef _DEBUG
void CDepartmentSectionSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDepartmentSectionSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

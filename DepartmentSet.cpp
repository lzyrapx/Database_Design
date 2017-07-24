// DepartmentSet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "DepartmentSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDepartmentSet

IMPLEMENT_DYNAMIC(CDepartmentSet, CRecordset)

CDepartmentSet::CDepartmentSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CDepartmentSet)
	m_code = _T("");
	m_name = _T("");
	m_leader = _T("");
	m_location = _T("");
	m_organization = _T("");
	m_teach = _T("");
	m_research = _T("");
	m_student = _T("");
	m_nFields = 8;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CDepartmentSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CDepartmentSet::GetDefaultSQL()
{
	return _T("[department]");
}

void CDepartmentSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CDepartmentSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[code]"), m_code);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[leader]"), m_leader);
	RFX_Text(pFX, _T("[location]"), m_location);
	RFX_Text(pFX, _T("[organization]"), m_organization);
	RFX_Text(pFX, _T("[teach]"), m_teach);
	RFX_Text(pFX, _T("[research]"), m_research);
	RFX_Text(pFX, _T("[student]"), m_student);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CDepartmentSet diagnostics

#ifdef _DEBUG
void CDepartmentSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDepartmentSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

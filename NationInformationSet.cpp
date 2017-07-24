// NationInformationSet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "NationInformationSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNationInformationSet

IMPLEMENT_DYNAMIC(CNationInformationSet, CRecordset)

CNationInformationSet::CNationInformationSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CNationInformationSet)
	m_ID = 0;
	m_folk = _T("");
	m_description = _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CNationInformationSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CNationInformationSet::GetDefaultSQL()
{
	return _T("[nationInformation]");
}

void CNationInformationSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CNationInformationSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[folk]"), m_folk);
	RFX_Text(pFX, _T("[description]"), m_description);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CNationInformationSet diagnostics

#ifdef _DEBUG
void CNationInformationSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CNationInformationSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

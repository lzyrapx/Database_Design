// PositionInformationSet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "PositionInformationSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPositionInformationSet

IMPLEMENT_DYNAMIC(CPositionInformationSet, CRecordset)

CPositionInformationSet::CPositionInformationSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CPositionInformationSet)
	m_ID = 0;
	m_post = _T("");
	m_description = _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CPositionInformationSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CPositionInformationSet::GetDefaultSQL()
{
	return _T("[positionInformation]");
}

void CPositionInformationSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CPositionInformationSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[post]"), m_post);
	RFX_Text(pFX, _T("[description]"), m_description);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CPositionInformationSet diagnostics

#ifdef _DEBUG
void CPositionInformationSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CPositionInformationSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

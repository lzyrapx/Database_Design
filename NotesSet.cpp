// NotesSet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "NotesSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNotesSet

IMPLEMENT_DYNAMIC(CNotesSet, CRecordset)

CNotesSet::CNotesSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CNotesSet)
	m_number = 0;
	m_writer = _T("");
	m_wUnit = _T("");
	m_type = _T("");
	m_title = _T("");
	m_content = _T("");
	m_nFields = 7;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CNotesSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CNotesSet::GetDefaultSQL()
{
	return _T("[notes]");
}

void CNotesSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CNotesSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[number]"), m_number);
	RFX_Date(pFX, _T("[rDate]"), m_rDate);
	RFX_Text(pFX, _T("[writer]"), m_writer);
	RFX_Text(pFX, _T("[wUnit]"), m_wUnit);
	RFX_Text(pFX, _T("[type]"), m_type);
	RFX_Text(pFX, _T("[title]"), m_title);
	RFX_Text(pFX, _T("[content]"), m_content);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CNotesSet diagnostics

#ifdef _DEBUG
void CNotesSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CNotesSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

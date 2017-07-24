// PaperSet1.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "PaperSet1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaperSet1

IMPLEMENT_DYNAMIC(CPaperSet1, CRecordset)

CPaperSet1::CPaperSet1(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CPaperSet1)
	m_number = 0;
	m_code = _T("");
	m_title = _T("");
	m_rank = _T("");
	m_publication = _T("");
	m_pub_year = _T("");
	m_volume = _T("");
	m_issue = _T("");
	m_page = _T("");
	m_level = _T("");
	m_type = _T("");
	m_index = _T("");
	m_nFields = 13;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CPaperSet1::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CPaperSet1::GetDefaultSQL()
{
	return _T("[paper]");
}

void CPaperSet1::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CPaperSet1)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[number]"), m_number);
	RFX_Text(pFX, _T("[code]"), m_code);
	RFX_Text(pFX, _T("[title]"), m_title);
	RFX_Text(pFX, _T("[rank]"), m_rank);
	RFX_Text(pFX, _T("[publication]"), m_publication);
	RFX_Date(pFX, _T("[pub time]"), m_pub_time);
	RFX_Text(pFX, _T("[pub year]"), m_pub_year);
	RFX_Text(pFX, _T("[volume]"), m_volume);
	RFX_Text(pFX, _T("[issue]"), m_issue);
	RFX_Text(pFX, _T("[page]"), m_page);
	RFX_Text(pFX, _T("[level]"), m_level);
	RFX_Text(pFX, _T("[type]"), m_type);
	RFX_Text(pFX, _T("[index]"), m_index);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CPaperSet1 diagnostics

#ifdef _DEBUG
void CPaperSet1::AssertValid() const
{
	CRecordset::AssertValid();
}

void CPaperSet1::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

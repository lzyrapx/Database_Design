// ContactsSet.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "ContactsSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CContactsSet

IMPLEMENT_DYNAMIC(CContactsSet, CRecordset)

CContactsSet::CContactsSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CContactsSet)
	m_number = 0;
	m_name = _T("");
	m_sex = _T("");
	m_fPhone = _T("");
	m_oPhone = _T("");
	m_mPhone = _T("");
	m_short = _T("");
	m_QQ = _T("");
	m_weChat = _T("");
	m_email = _T("");
	m_unit = _T("");
	m_remark = _T("");
	m_nFields = 12;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CContactsSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CContactsSet::GetDefaultSQL()
{
	return _T("[contacts]");
}

void CContactsSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CContactsSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[number]"), m_number);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[sex]"), m_sex);
	RFX_Text(pFX, _T("[fPhone]"), m_fPhone);
	RFX_Text(pFX, _T("[oPhone]"), m_oPhone);
	RFX_Text(pFX, _T("[mPhone]"), m_mPhone);
	RFX_Text(pFX, _T("[short]"), m_short);
	RFX_Text(pFX, _T("[QQ]"), m_QQ);
	RFX_Text(pFX, _T("[weChat]"), m_weChat);
	RFX_Text(pFX, _T("[email]"), m_email);
	RFX_Text(pFX, _T("[unit]"), m_unit);
	RFX_Text(pFX, _T("[remark]"), m_remark);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CContactsSet diagnostics

#ifdef _DEBUG
void CContactsSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CContactsSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

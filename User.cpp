// User.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "User.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUser

IMPLEMENT_DYNAMIC(CUser, CRecordset)

CUser::CUser(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CUser)
	m_customer = _T("");
	m_password = _T("");
	m_privilege = FALSE;
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CUser::GetDefaultConnect()
{
	return _T("ODBC;DSN=PostDB");
}

CString CUser::GetDefaultSQL()
{
	return _T("[user]");
}

void CUser::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CUser)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[customer]"), m_customer);
	RFX_Text(pFX, _T("[password]"), m_password);
	RFX_Bool(pFX, _T("[privilege]"), m_privilege);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CUser diagnostics

#ifdef _DEBUG
void CUser::AssertValid() const
{
	CRecordset::AssertValid();
}

void CUser::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

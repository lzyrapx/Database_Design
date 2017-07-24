// DatabaseDoc.cpp : implementation of the CDatabaseDoc class
//

#include "stdafx.h"
#include "Database.h"

#include "DatabaseDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDatabaseDoc

IMPLEMENT_DYNCREATE(CDatabaseDoc, CDocument)

BEGIN_MESSAGE_MAP(CDatabaseDoc, CDocument)
	//{{AFX_MSG_MAP(CDatabaseDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDatabaseDoc construction/destruction

CDatabaseDoc::CDatabaseDoc()
{
	// TODO: add one-time construction code here

}

CDatabaseDoc::~CDatabaseDoc()
{
}

BOOL CDatabaseDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDatabaseDoc serialization

void CDatabaseDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDatabaseDoc diagnostics

#ifdef _DEBUG
void CDatabaseDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDatabaseDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDatabaseDoc commands

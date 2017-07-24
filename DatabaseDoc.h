// DatabaseDoc.h : interface of the CDatabaseDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATABASEDOC_H__B27131F9_4BD8_4175_A519_468F3693478B__INCLUDED_)
#define AFX_DATABASEDOC_H__B27131F9_4BD8_4175_A519_468F3693478B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDatabaseDoc : public CDocument
{
protected: // create from serialization only
	CDatabaseDoc();
	DECLARE_DYNCREATE(CDatabaseDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDatabaseDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDatabaseDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDatabaseDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATABASEDOC_H__B27131F9_4BD8_4175_A519_468F3693478B__INCLUDED_)

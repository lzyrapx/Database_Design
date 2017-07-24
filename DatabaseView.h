// DatabaseView.h : interface of the CDatabaseView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATABASEVIEW_H__055C9A07_05D9_4653_BE33_4C337B7C0090__INCLUDED_)
#define AFX_DATABASEVIEW_H__055C9A07_05D9_4653_BE33_4C337B7C0090__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDatabaseView : public CView
{
protected: // create from serialization only
	CDatabaseView();
	DECLARE_DYNCREATE(CDatabaseView)

// Attributes
public:
	CDatabaseDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDatabaseView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDatabaseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDatabaseView)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DatabaseView.cpp
inline CDatabaseDoc* CDatabaseView::GetDocument()
   { return (CDatabaseDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATABASEVIEW_H__055C9A07_05D9_4653_BE33_4C337B7C0090__INCLUDED_)

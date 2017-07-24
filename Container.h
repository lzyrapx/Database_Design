#if !defined(AFX_CONTAINER_H__EC1736F0_ABD6_4070_881E_57AE902BD8CB__INCLUDED_)
#define AFX_CONTAINER_H__EC1736F0_ABD6_4070_881E_57AE902BD8CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Container.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CContainer window

//添加代码
#define MAXMODEL 32     //CTabCtrl控件最大属性页的宏定义
//添加代码结束
class CContainer : public CTabCtrl
{
// Construction
public:
	CContainer();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CContainer)
	//}}AFX_VIRTUAL

// Implementation
public:
	void Display();
	void SetRect();
	int SetCurSel(int iOption);
	int GetCurSel();
	BOOL AddModel(LPCTSTR title,CDialog * pDialog,UINT ID);
	virtual ~CContainer();

	// Generated message map functions
protected:
	LPCTSTR m_strTitle[MAXMODEL];
	CDialog * m_pMODELS[MAXMODEL];
	int m_iTotalModels;
	int m_iCurrentModel;
	UINT m_MID[MAXMODEL];
	//{{AFX_MSG(CContainer)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTAINER_H__EC1736F0_ABD6_4070_881E_57AE902BD8CB__INCLUDED_)

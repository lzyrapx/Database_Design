// Database.h : main header file for the DATABASE application
//

#if !defined(AFX_DATABASE_H__D0B37492_E191_4440_91BF_BD93CC84A519__INCLUDED_)
#define AFX_DATABASE_H__D0B37492_E191_4440_91BF_BD93CC84A519__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDatabaseApp:
// See Database.cpp for the implementation of this class
//

class CDatabaseApp : public CWinApp
{
public:
	CDatabaseApp();
	//添加代码
	BOOL m_bHasSuperAuthority;  //判断系统用户是否拥有最高访问权限
	//添加代码结束
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDatabaseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDatabaseApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATABASE_H__D0B37492_E191_4440_91BF_BD93CC84A519__INCLUDED_)

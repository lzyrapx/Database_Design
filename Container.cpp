// Container.cpp : implementation file
//

#include "stdafx.h"
#include "Database.h"
#include "Container.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CContainer

CContainer::CContainer()
{
	//添加代码
	//总模块数与当前模块的初始化
	m_iTotalModels = 0;
	m_iCurrentModel = 0;
	//添加代码结束
}

CContainer::~CContainer()
{
}


BEGIN_MESSAGE_MAP(CContainer, CTabCtrl)
	//{{AFX_MSG_MAP(CContainer)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CContainer message handlers

BOOL CContainer::AddModel(LPCTSTR title, CDialog *pDialog, UINT ID)
{
    //添加代码
    if(MAXMODEL == m_iTotalModels)
	    return FALSE;
    m_iTotalModels++;
    //形参赋值
    m_pMODELS[m_iTotalModels - 1] = pDialog;
    m_MID[m_iTotalModels - 1] = ID;
	m_strTitle[m_iTotalModels - 1] = title;
	return TRUE;
	//添加代码结束
}

int CContainer::GetCurSel()
{
	//添加代码
	return CTabCtrl::GetCurSel();
	//添加代码结束
}

int CContainer::SetCurSel(int iOption)
{
    //添加代码
	//当前选择异常的处理
	if(iOption < 0 || iOption >= m_iTotalModels)
		return -1;
	int ret = m_iCurrentModel;
	//将用户当前的正确选择模块予以显示处理
	if(m_iCurrentModel != iOption)
	{
		m_pMODELS[m_iCurrentModel] ->ShowWindow(SW_HIDE);
		m_iCurrentModel = iOption;
		m_pMODELS[m_iCurrentModel] ->ShowWindow(SW_SHOW);
		CTabCtrl::SetCurSel(iOption);
	}
	return ret;
	//添加代码结束
}

void CContainer::SetRect()
{
    //添加代码
	//定义两个矩形类对象
	CRect tabCtrlRect,optionRect;
	//定义4个整型变量处理上面两个矩形的边界
	int Xt,Yt,Xd,Yd;
	GetClientRect(&tabCtrlRect);
	GetItemRect(0,&optionRect);
	Xt = optionRect.left;
	Yt = optionRect.bottom + 1;
	Xd = tabCtrlRect.right - optionRect.left - 2;
	Yd = tabCtrlRect.bottom - Yt -2;
	m_pMODELS[0] ->SetWindowPos(&wndTop,Xt,Yt,Xd,Yd,SWP_SHOWWINDOW);
	for(int i = 1;i < m_iTotalModels;i++)
	m_pMODELS[i] ->SetWindowPos(&wndTop,Xt,Yt,Xd,Yd,SWP_HIDEWINDOW);
	//添加代码结束
}

void CContainer::Display()
{
    //添加代码
	for(int i = 0;i < m_iTotalModels;i++)
	{
		m_pMODELS[i] ->Create(m_MID[i],this);
		InsertItem(i,m_strTitle[i]);
	}
	m_pMODELS[0] ->ShowWindow(SW_SHOW);
	for(i = 1;i < m_iTotalModels;i++)
		m_pMODELS[i] ->ShowWindow(SW_HIDE);
	SetRect();
	//添加代码结束
}

void CContainer::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CTabCtrl::OnLButtonDown(nFlags, point);
	//添加代码
	//模块所在属性页面之间的切换
	if(m_iCurrentModel != GetCurFocus())
	{
		m_pMODELS[m_iCurrentModel] ->ShowWindow(SW_HIDE);
		m_iCurrentModel = GetCurFocus();
		m_pMODELS[m_iCurrentModel] ->ShowWindow(SW_SHOW);
	}
	//添加代码结束
}

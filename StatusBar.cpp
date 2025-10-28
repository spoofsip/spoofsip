/*
 * Copyright (C) 2023-2024 SpoofSIP (http://www.spoofsip.org)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "StdAfx.h"   
#include "StatusBar.h"   
#include "global.h"

 // StatusBar   
IMPLEMENT_DYNAMIC(StatusBar, CStatusBar)
StatusBar::StatusBar()
{
	CStatusBar::CStatusBar();
}

StatusBar::~StatusBar()
{
}

BEGIN_MESSAGE_MAP(StatusBar, CStatusBar)
	//{{AFX_MSG_MAP(StatusBar)   
	ON_MESSAGE(WM_IDLEUPDATECMDUI, OnIdleUpdateCmdUI)
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP   
END_MESSAGE_MAP()

LRESULT StatusBar::OnIdleUpdateCmdUI(WPARAM wParam, LPARAM lParam)
{
	if (IsWindowVisible())
	{
		CFrameWnd* pParent = (CFrameWnd*)GetParent();
		if (pParent)
			OnUpdateCmdUI(pParent, (BOOL)wParam);
	}
	return 0L;
}

void StatusBar::OnLButtonUp(UINT nFlags, CPoint point)
{
}

void StatusBar::OnMouseMove(UINT nFlags, CPoint point)
{
}

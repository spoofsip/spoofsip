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
#include "ButtonBottom.h"   

 // CButtonBottom   
IMPLEMENT_DYNAMIC(CButtonBottom, CMFCButton)
CButtonBottom::CButtonBottom()
{
	m_nFlatStyle = CMFCButton::BUTTONSTYLE_NOBORDERS;
	m_bTransparent = false;
	m_bDrawFocus = FALSE;
	m_bHighlightChecked = FALSE;

	m_clrButton = RGB(255, 255, 255);
	m_clrButtonHover = RGB(224, 238, 249);
	m_clrButtonPushed = RGB(92, 145, 219);
	m_clrButtonText = RGB(0, 0, 0);
	m_clrButtonTextPushed = RGB(255, 255, 255);
}

CButtonBottom::~CButtonBottom()
{
}

BEGIN_MESSAGE_MAP(CButtonBottom, CMFCButton)
	//{{AFX_MSG_MAP(CButtonBottom)
	ON_WM_KILLFOCUS()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CButtonBottom::OnKillFocus(CWnd* pNewWnd)
{
	CButton::OnKillFocus(pNewWnd);

	if (m_bCaptured)
	{
		ReleaseCapture();
		m_bCaptured = FALSE;
	}

	//m_bPushed = FALSE;
	//m_bClickiedInside = FALSE;
	//m_bHighlighted = FALSE;
	m_bHover = FALSE;

	Invalidate();
	UpdateWindow();
}


void CButtonBottom::DrawItem(LPDRAWITEMSTRUCT lpDIS)
{
	if (m_bCheckButton && m_bChecked) {
		m_clrFace = m_clrButtonPushed;
		m_clrRegular = m_clrButtonTextPushed;
	}
	else {
		if (m_bPushed) {
			m_clrFace = m_clrButtonPushed;
			m_clrRegular = m_clrButtonTextPushed;
		}
		else if (m_bHover) {
			m_clrFace = m_clrButtonHover;
			m_clrRegular = m_clrButtonText;
		}
		else {
			m_clrFace = m_clrButton;
			m_clrRegular = m_clrButtonText;
		}
	}
	CMFCButton::DrawItem(lpDIS);
}

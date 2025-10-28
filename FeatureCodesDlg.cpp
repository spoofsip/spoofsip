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

#include "stdafx.h"
#include "spoofsip.h"
#include "FeatureCodesDlg.h"
#include "mainDlg.h"
#include "langpack.h"
#include "settings.h"
#include "Resource.h"

FeatureCodesDlg::FeatureCodesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(FeatureCodesDlg::IDD, pParent)
{
	Create (IDD, pParent);
}

FeatureCodesDlg::~FeatureCodesDlg()
{
}

int FeatureCodesDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (langPack.rtl) {
		ModifyStyleEx(0,WS_EX_LAYOUTRTL);
	}
	POINT p;
	if (GetCursorPos(&p)) {
		SetWindowPos(NULL, p.x-250, p.y+10, 0, 0, SWP_NOZORDER| SWP_NOSIZE | SWP_NOACTIVATE | SWP_NOOWNERZORDER | SWP_NOZORDER);
	}
	return 0;
}

BOOL FeatureCodesDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	TranslateDialog(this->m_hWnd);

	GetDlgItem(IDC_FEATURE_CODES_CP)->SetWindowText(accountSettings.featureCodeCP);
	((CButton*)GetDlgItem(IDC_FEATURE_CODES_ENABLE_CP))->SetCheck(accountSettings.enableFeatureCodeCP);
	GetDlgItem(IDC_FEATURE_CODES_BT)->SetWindowText(accountSettings.featureCodeBT);
	((CButton*)GetDlgItem(IDC_FEATURE_CODES_ENABLE_BT))->SetCheck(accountSettings.enableFeatureCodeBT);
	GetDlgItem(IDC_FEATURE_CODES_AT)->SetWindowText(accountSettings.featureCodeAT);
	((CButton*)GetDlgItem(IDC_FEATURE_CODES_ENABLE_AT))->SetCheck(accountSettings.enableFeatureCodeAT);
	return TRUE;
}

void FeatureCodesDlg::OnDestroy()
{
	mainDlg->settingsDlg->featureCodesDlg = NULL;
	CDialog::OnDestroy();
}

void FeatureCodesDlg::PostNcDestroy()
{
	CDialog::PostNcDestroy();
	delete this;
}

BEGIN_MESSAGE_MAP(FeatureCodesDlg, CDialog)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDOK, &FeatureCodesDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &FeatureCodesDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


void FeatureCodesDlg::OnClose() 
{
	DestroyWindow();
}

void FeatureCodesDlg::OnBnClickedOk()
{
	GetDlgItem(IDC_FEATURE_CODES_CP)->GetWindowText(accountSettings.featureCodeCP);
	accountSettings.enableFeatureCodeCP = ((CButton*)GetDlgItem(IDC_FEATURE_CODES_ENABLE_CP))->GetCheck();
	GetDlgItem(IDC_FEATURE_CODES_BT)->GetWindowText(accountSettings.featureCodeBT);
	accountSettings.enableFeatureCodeBT = ((CButton*)GetDlgItem(IDC_FEATURE_CODES_ENABLE_BT))->GetCheck();
	GetDlgItem(IDC_FEATURE_CODES_AT)->GetWindowText(accountSettings.featureCodeAT);
	accountSettings.enableFeatureCodeAT = ((CButton*)GetDlgItem(IDC_FEATURE_CODES_ENABLE_AT))->GetCheck();
	accountSettings.SettingsSave();
	OnClose();
}

void FeatureCodesDlg::OnBnClickedCancel()
{
	OnClose();
}


// ProgressWizard.cpp : implementation file
//

#include "stdafx.h"
#include "ProgressWizard.h"
#include "VersionInfo.h"

#include "WelcomePage.h"
#include "ProgressPage.h"
#include "CompletePage.h"

// CProgressWizard

IMPLEMENT_DYNAMIC(CProgressWizard, CPropertySheet)

CProgressWizard::CProgressWizard(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage, HBITMAP hbmWatermark, HPALETTE hpalWatermark, HBITMAP hbmHeader)
	: CPropertySheet(nIDCaption, pParentWnd, iSelectPage, hbmWatermark, hpalWatermark, hbmHeader)
{
	AddPage(new CWelcomePage);
	AddPage(new CProgressPage);
	AddPage(new CCompletePage);

	SetWizardMode();

	if (SupportsWizard97())
		m_psh.dwFlags |= PSH_WIZARD97;
}

CProgressWizard::~CProgressWizard()
{
	for (int i = 0; i < GetPageCount(); ++i)
	{
		CPropertyPage *pPage = GetPage(i);

		delete pPage;
	}
}

BEGIN_MESSAGE_MAP(CProgressWizard, CPropertySheet)
END_MESSAGE_MAP()

// CProgressWizard message handlers

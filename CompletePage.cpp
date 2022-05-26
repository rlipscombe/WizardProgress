// CompletePage.cpp : implementation file
//

#include "stdafx.h"
#include "CompletePage.h"

// CCompletePage dialog
IMPLEMENT_DYNAMIC(CCompletePage, CPropertyPage)

CCompletePage::CCompletePage()
	: CPropertyPage(CCompletePage::IDD)
{
    m_psp.dwFlags |= PSP_HIDEHEADER;
}

CCompletePage::~CCompletePage()
{
}

void CCompletePage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCompletePage, CPropertyPage)
END_MESSAGE_MAP()


// CCompletePage message handlers

BOOL CCompletePage::OnSetActive()
{
	if (!CPropertyPage::OnSetActive())
		return FALSE;

	static_cast<CPropertySheet *>(GetParent())->SetWizardButtons(PSWIZB_FINISH);

	return TRUE;
}

/* WelcomePage.cpp
 *
 * Copyright (C) 2003 Roger Lipscombe
 *     http://www.differentpla.net/~roger/
 */

#include "stdafx.h"
#include "WelcomePage.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CWelcomePage, CPropertyPage)


/////////////////////////////////////////////////////////////////////////////
// CWelcomePage property page

CWelcomePage::CWelcomePage()
    : CPropertyPage(CWelcomePage::IDD)
{
    //{{AFX_DATA_INIT(CWelcomePage)
    //}}AFX_DATA_INIT

    m_psp.dwFlags |= PSP_HIDEHEADER;
}

CWelcomePage::~CWelcomePage()
{
}

void CWelcomePage::DoDataExchange(CDataExchange* pDX)
{
    CPropertyPage::DoDataExchange(pDX);

    //{{AFX_DATA_MAP(CWelcomePage)
    //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWelcomePage, CPropertyPage)
    //{{AFX_MSG_MAP(CWelcomePage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CWelcomePage::OnInitDialog() 
{
    CPropertyPage::OnInitDialog();

    CreateBoldFont(&m_boldFont);
	InflictBoldFont(IDC_TITLE);

    return TRUE;
}

BOOL CWelcomePage::OnSetActive() 
{
    if (!CPropertyPage::OnSetActive())
		return FALSE;

    static_cast<CPropertySheet *>(GetParent())->SetWizardButtons(PSWIZB_NEXT);

    return TRUE;
}

static void GetMessageBoxFont(LOGFONT *lf)
{
	NONCLIENTMETRICS ncm;
	ncm.cbSize = sizeof(NONCLIENTMETRICS);
	VERIFY(SystemParametersInfo(SPI_GETNONCLIENTMETRICS, sizeof(ncm), &ncm, 0));
	*lf = ncm.lfMessageFont;
}

bool CWelcomePage::CreateBoldFont(CFont *pFont)
{
	LOGFONT lf;
	GetMessageBoxFont(&lf);

	CDC *pDC = GetDC();
	lf.lfHeight = -MulDiv(12, GetDeviceCaps(pDC->m_hDC, LOGPIXELSY), 72);
	ReleaseDC(pDC);

	lf.lfWeight = FW_BOLD;

	if (pFont->CreateFontIndirect(&lf))
		return true;
	return false;
}

void CWelcomePage::InflictBoldFont(UINT nIDC)
{
	CWnd *pWnd = GetDlgItem(nIDC);
	if (pWnd)
		pWnd->SetFont(&m_boldFont);
}

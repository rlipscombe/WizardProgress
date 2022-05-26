#pragma once



// CProgressWizard

class CProgressWizard : public CPropertySheet
{
	DECLARE_DYNAMIC(CProgressWizard)

public:
	CProgressWizard(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage, HBITMAP hbmWatermark, HPALETTE hpalWatermark, HBITMAP hbmHeader);
	virtual ~CProgressWizard();

protected:
	DECLARE_MESSAGE_MAP()
};


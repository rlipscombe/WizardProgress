#pragma once
#include "resource.h"

// CCompletePage dialog

class CCompletePage : public CPropertyPage
{
	DECLARE_DYNAMIC(CCompletePage)

public:
	CCompletePage();
	virtual ~CCompletePage();

	virtual BOOL OnSetActive();

// Dialog Data
	enum { IDD = IDD_COMPLETE_PAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};

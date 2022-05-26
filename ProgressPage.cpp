// ProgressPage.cpp : implementation file
//

#include "stdafx.h"
#include "ProgressPage.h"

// CProgressPage dialog
IMPLEMENT_DYNAMIC(CProgressPage, CPropertyPage)

CProgressPage::CProgressPage()
	: CPropertyPage(CProgressPage::IDD)
{
}

CProgressPage::~CProgressPage()
{
}

void CProgressPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_progressCtrl);
}

#define MY_WM_START_TASK (WM_USER + 42)

BEGIN_MESSAGE_MAP(CProgressPage, CPropertyPage)
	ON_MESSAGE(MY_WM_START_TASK, OnStartTask)
END_MESSAGE_MAP()

void CProgressPage::PumpMessages()
{
	// Must call Create() before using the dialog
	ASSERT(m_hWnd != NULL);

	MSG msg;
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		if (!IsDialogMessage(&msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);  
		}
	}
}

// CProgressPage message handlers
BOOL CProgressPage::OnSetActive()
{
	if (!CPropertyPage::OnSetActive())
		return FALSE;

	// Because the property page isn't fully created and displayed at this point,
	// we need to use PostMessage to defer the long-lasting task for a short while.
	
	// First, we'll disable the buttons, to prevent the user from pressing anything before we get going.
	static_cast<CPropertySheet *>(GetParent())->SetWizardButtons(0);
	CWnd *pCancel = GetParent()->GetDlgItem(IDCANCEL);
	if (pCancel)
		pCancel->EnableWindow(FALSE);

	PostMessage(MY_WM_START_TASK);

	return TRUE;
}

LRESULT CProgressPage::OnStartTask(WPARAM /*wParam*/, LPARAM /*lParam*/)
{
	CWaitCursor wait;

	Task task(this);
	task.Run();

	return 0;
}

void CProgressPage::OnProgress(int current, int maximum)
{
	PumpMessages();

	m_progressCtrl.SetRange32(0, maximum);
	m_progressCtrl.SetPos(current);
}

void CProgressPage::OnComplete()
{
	PumpMessages();

	static_cast<CPropertySheet *>(GetParent())->PressButton(PSBTN_NEXT);
}

// WizardProgress.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "WizardProgress.h"
#include "ProgressWizard.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWizardProgressApp

BEGIN_MESSAGE_MAP(CWizardProgressApp, CWinApp)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


// CWizardProgressApp construction

CWizardProgressApp::CWizardProgressApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CWizardProgressApp object

CWizardProgressApp theApp;


// CWizardProgressApp initialization

BOOL CWizardProgressApp::InitInstance()
{
	// InitCommonControls() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	InitCommonControls();

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	HBITMAP hbmWatermark = ::LoadBitmap(AfxGetResourceHandle(), MAKEINTRESOURCE(IDB_WATERMARK));
	ASSERT(hbmWatermark);
    HPALETTE hpalWatermark = NULL;
    HBITMAP hbmHeader = ::LoadBitmap(AfxGetResourceHandle(), MAKEINTRESOURCE(IDB_HEADER));
	ASSERT(hbmHeader);

	CProgressWizard dlg(IDS_PROGRESS_WIZARD_CAPTION, NULL, 0, hbmWatermark, hpalWatermark, hbmHeader);
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

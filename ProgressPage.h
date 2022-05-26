#pragma once

#include "resource.h"
#include "Task.h"
#include "afxcmn.h"

// CProgressPage dialog
class CProgressPage : public CPropertyPage, private TaskObserver
{
	DECLARE_DYNAMIC(CProgressPage)

public:
	CProgressPage();
	virtual ~CProgressPage();

	virtual BOOL OnSetActive();

// Dialog Data
	enum { IDD = IDD_PROGRESS_PAGE };
	CProgressCtrl m_progressCtrl;

// TaskObserver
private:
	virtual void OnProgress(int current, int maximum);
	virtual void OnComplete();

protected:
	void PumpMessages();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

	afx_msg LRESULT OnStartTask(WPARAM wParam, LPARAM lParam);
};

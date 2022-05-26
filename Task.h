class TaskObserver;

class Task
{
	TaskObserver *m_pObserver;

public:
	Task(TaskObserver *pObserver)
		: m_pObserver(pObserver)
	{
	}

	void Run()
	{
		// Pretend to do some work.
		const int MAX_ITERATIONS = 10;
		for (int i = 0; i < MAX_ITERATIONS; ++i)
		{
			DWORD startTicks = GetTickCount();
			ReportProgress(i, MAX_ITERATIONS);
			Sleep(1000);
		}

		ReportProgress(MAX_ITERATIONS, MAX_ITERATIONS);
		ReportComplete();
	}

private:
	void ReportProgress(int current, int maximum);
	void ReportComplete();
};

class TaskObserver
{
public:
	virtual void OnProgress(int current, int maximum) = 0;
	virtual void OnComplete() = 0;
};

inline void Task::ReportProgress(int current, int maximum)
{
	if (m_pObserver)
		m_pObserver->OnProgress(current, maximum);
}

inline void Task::ReportComplete()
{
	if (m_pObserver)
		m_pObserver->OnComplete();
}

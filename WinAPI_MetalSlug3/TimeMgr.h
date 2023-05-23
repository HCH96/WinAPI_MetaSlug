#pragma once

class TimeMgr
{
	SINGLE(TimeMgr);

private:
	LARGE_INTEGER		m_llCurCount;
	LARGE_INTEGER		m_llPrevCount;
	LARGE_INTEGER		m_llFrequency;

	double				m_dDT;
	double				m_dAcc;
	UINT				m_iFPS;
	UINT				m_iCallCount;

public:
	void init();
	void update();
	void render(HWND _hWnd);

public:
	double GetDT() { return m_dDT; }
	float GetfDT() { return (float)m_dDT; }
};


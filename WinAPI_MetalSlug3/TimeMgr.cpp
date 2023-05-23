#include "global.h"
#include "TimeMgr.h"

#include "Core.h"

TimeMgr::TimeMgr()
	: m_llCurCount{}
	, m_llPrevCount{}
	, m_llFrequency{}
	, m_dDT(0.)
	, m_dAcc(0.)
	, m_iFPS(0)
	, m_iCallCount(0)
{
}

TimeMgr::~TimeMgr()
{
}

void TimeMgr::init()
{
	// 현재 카운트
	QueryPerformanceCounter(&m_llPrevCount);

	// 초당 카운트
	QueryPerformanceFrequency(&m_llFrequency);
}

void TimeMgr::update()
{
	// 현재 카운트
	QueryPerformanceCounter(&m_llCurCount);

	// Delta Time 계산
	m_dDT = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / (double)m_llFrequency.QuadPart;

	// 다음 프레임 DT 계산을 위해 현재 카운트를 Prev에 저장
	m_llPrevCount = m_llCurCount;
}

void TimeMgr::render(HWND _hWnd)
{
	++m_iCallCount;
	m_dAcc += m_dDT;

	if (m_dAcc >= 1.)
	{
		m_iFPS = m_iCallCount;


		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS : %d, DT : %f", m_iFPS, m_dDT);
		SetWindowText(_hWnd, szBuffer);

		m_dAcc = 0.;
		m_iCallCount = 0;
	}
}
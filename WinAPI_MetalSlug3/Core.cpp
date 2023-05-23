#include "global.h"
#include "Core.h"

Core::Core()
	: m_hWnd(0)
	, m_hDC(0)
	, m_ptResolution{}
{	 
}

Core::~Core()
{
}

int Core::init(HWND _hWnd, POINT _ptResolution)
{
	// 멤버 초기화
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;
	m_hDC = GetDC(m_hWnd);

	return S_OK;
}

void Core::progress()
{
}

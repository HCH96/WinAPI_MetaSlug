#include "global.h"
#include "Core.h"

#include "TimeMgr.h"

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
	// ��� �ʱ�ȭ
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;
	m_hDC = GetDC(m_hWnd);


	// Manager �ʱ�ȭ
	TimeMgr::GetInst()->init();

	return S_OK;
}

void Core::progress()
{

	// Manager update
	TimeMgr::GetInst()->update();


	// render
	TimeMgr::GetInst()->render(m_hWnd);

	for (int i = 0; i < 100; i++)
	{
		Rectangle(m_hDC, 100, 100, 200, 200);
	}

}

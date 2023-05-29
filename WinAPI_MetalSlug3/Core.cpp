#include "global.h"
#include "Core.h"

#include "TimeMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"

Core::Core()
	: m_hWnd(0)
	, m_hDC(0)
	, m_ptResolution{}
	, m_memDC(0)
	, m_hBit(0)
{	 
}

Core::~Core()
{
	ReleaseDC(m_hWnd, m_hDC);
	
	DeleteDC(m_memDC);
	DeleteObject(m_hBit);
}

int Core::init(HWND _hWnd, POINT _ptResolution)
{
	// 멤버 초기화
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;
	m_hDC = GetDC(m_hWnd);

	// 해상도에 맞게 윈도우 크기 조정
	RECT rt = { 0,0,(long)_ptResolution.x, (long)_ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	// BackBuffer 초기화
	m_hBit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
	m_memDC = CreateCompatibleDC(m_hDC);

	HBITMAP OldBit = (HBITMAP)SelectObject(m_memDC, m_hBit);
	DeleteObject(OldBit);


	// Manager 초기화
	TimeMgr::GetInst()->init();
	KeyMgr::GetInst()->init();
	SceneMgr::GetInst()->init();


	return S_OK;
}

void Core::progress()
{
	// ==============
	// Manager Update
	// ==============
	TimeMgr::GetInst()->update();
	KeyMgr::GetInst()->update();


	// ============
	// Scene update
	// ============
	SceneMgr::GetInst()->update();


	// =========
	// Rendering
	// =========
	TimeMgr::GetInst()->render(m_hWnd);

	clear();
	SceneMgr::GetInst()->render(m_memDC);
	
	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y, m_memDC, 0, 0, SRCCOPY);
	
}

void Core::clear()
{
	Rectangle(m_memDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);
}
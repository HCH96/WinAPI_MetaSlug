#pragma once


class Core
{
	SINGLE(Core);

private:
	HWND		m_hWnd;			// 메인 윈도우 핸들
	HDC			m_hDC;			// 메인 윈도우 DC
	POINT		m_ptResolution; // 해상도

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();

public:
	HDC	GetMainDC() { return m_hDC; }
	HWND GetMainHwnd() { return m_hWnd; }
	POINT GetResolution() { return m_ptResolution; }
};


#pragma once


class Core
{
	SINGLE(Core);

private:
	HWND		m_hWnd;			// ���� ������ �ڵ�
	HDC			m_hDC;			// ���� ������ DC
	POINT		m_ptResolution; // �ػ�

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();

public:
	HDC	GetMainDC() { return m_hDC; }
	HWND GetMainHwnd() { return m_hWnd; }
	POINT GetResolution() { return m_ptResolution; }
};


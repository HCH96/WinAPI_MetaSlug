#pragma once

class Object
{
private:
	wstring		m_strName;

	Vec2		m_vPos;
	Vec2		m_vScale;


public:
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }
	void SetName(const wstring& _strName) { m_strName = _strName; }

	Vec2 GetPos() { return m_vPos; }
	Vec2 GetScale() { return m_vScale; }
	wstring GetName() { return m_strName; }

public:
	virtual void start();
	virtual void update();
	virtual void render(HDC _dc);


public:
	Object();
	virtual ~Object();
};


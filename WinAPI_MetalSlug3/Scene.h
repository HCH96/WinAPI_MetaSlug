#pragma once

class Object;

class Scene
{
private:
	vector<Object*>		m_arrObj[(UINT)GROUP_TYPE::END];	// 오브젝트 벡터
	wstring				m_strName;							// Scene 이름

	Object*				m_pPlayer;							// Player 포인터

public:
	const wstring& GetName() { return m_strName; }
	Object* GetPlayer() { return m_pPlayer; }
	void SetName(const wstring& _strName) { m_strName = _strName; }

public:
	void AddObject(Object* _pObj, GROUP_TYPE _eType) { m_arrObj[(UINT)_eType].push_back(_pObj); }
	void RegisterPlayer(Object* _pPlayer) { m_pPlayer = _pPlayer; }

	vector<Object*> GetGroupObject(GROUP_TYPE _eType) { return m_arrObj[(UINT)_eType]; }
	void DeleteGroup(GROUP_TYPE _eTarget);
	void DeleteAll();

public:
	virtual void start();
	virtual void update();
	virtual void render(HDC _dc);

	virtual void Enter() = 0;
	virtual void Exit() = 0;


public:
	Scene();
	virtual ~Scene();
};


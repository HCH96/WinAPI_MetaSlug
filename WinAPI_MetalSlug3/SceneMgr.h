#pragma once

class Scene;

class SceneMgr
{
	SINGLE(SceneMgr);

private:
	Scene* m_arrScene[(UINT)SCENE_TYPE::END];
	Scene* m_pCurScene;


public:
	void init();
	void update();
	void render(HDC _dc);


public:
	Scene* GetCurScene() { return m_pCurScene; }
	void ChangeScene(SCENE_TYPE _eNext);
};


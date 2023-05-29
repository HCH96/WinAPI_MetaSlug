#include "global.h"

#include "SceneMgr.h"


// Scene
#include "Scene_Title.h"
#include "Scene_Play.h"


SceneMgr::SceneMgr()
	: m_arrScene{}
	, m_pCurScene(nullptr)
{
}

SceneMgr::~SceneMgr()
{
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; ++i)
	{
		if (m_arrScene[i] != nullptr)
			delete m_arrScene[i];
	}
}

void SceneMgr::init()
{
	m_arrScene[(UINT)SCENE_TYPE::TITLE] = new Scene_Title;
	m_arrScene[(UINT)SCENE_TYPE::PLAY] = new Scene_Play;

	m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::TITLE];
	m_pCurScene->Enter();
}

void SceneMgr::update()
{
	m_pCurScene->update();
}

void SceneMgr::render(HDC _dc)
{
	m_pCurScene->render(_dc);
}

void SceneMgr::ChangeScene(SCENE_TYPE _eNext)
{
	m_pCurScene->Exit();

	m_pCurScene = m_arrScene[(UINT)_eNext];

	m_pCurScene->Enter();
}

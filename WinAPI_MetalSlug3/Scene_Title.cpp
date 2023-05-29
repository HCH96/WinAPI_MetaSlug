#include "global.h"

#include "Scene_Title.h"

#include "KeyMgr.h"
#include "SceneMgr.h"

Scene_Title::Scene_Title()
{
	SetName(L"Title Scene");
}

Scene_Title::~Scene_Title()
{
}

void Scene_Title::start()
{
}

void Scene_Title::update()
{
	Scene::update();

	if (KEY_TAP(KEY::ENTER))
	{
		SceneMgr::GetInst()->ChangeScene(SCENE_TYPE::PLAY);
	}
}

void Scene_Title::render(HDC _dc)
{
	Scene::render(_dc);
}

void Scene_Title::Enter()
{
}

void Scene_Title::Exit()
{
}


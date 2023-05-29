#include "global.h"

#include "Scene_Play.h"

#include "Object.h"

#include "Player.h"


Scene_Play::Scene_Play()
{
	SetName(L"Play Scene");
}

Scene_Play::~Scene_Play()
{
}


void Scene_Play::start()
{
}

void Scene_Play::update()
{
	Scene::update();
}

void Scene_Play::render(HDC _dc)
{
	Scene::render(_dc);
}

void Scene_Play::Enter()
{
	// Object Ãß°¡
	Object* pPlayer = new Player;

	pPlayer->SetPos(Vec2(640.f, 384.f));
	pPlayer->SetScale(Vec2(100.f, 100.f));

	AddObject(pPlayer, GROUP_TYPE::PLAYER);
	RegisterPlayer(pPlayer);
}

void Scene_Play::Exit()
{
	DeleteAll();
}


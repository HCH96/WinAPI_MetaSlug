#include "global.h"

#include "Player.h"

#include "KeyMgr.h"
#include "TimeMgr.h"


Player::Player()
{
	SetName(L"Player");
}

Player::~Player()
{
}

void Player::start()
{
	SetPos(Vec2(300.f, 300.f));
	SetScale(Vec2(100.f, 100.f));
}

void Player::update()
{
	Vec2 vPos = GetPos();

	if (KEY_HOLD(KEY::UP))
	{
		vPos += Vec2(0.f, -100.f * fDT);
	}

	if (KEY_HOLD(KEY::DOWN))
	{
		vPos += Vec2(0.f, 100.f * fDT);
	}

	if (KEY_HOLD(KEY::LEFT))
	{
		vPos += Vec2(-100.f * fDT, 0.f);
	}

	if (KEY_HOLD(KEY::RIGHT))
	{
		vPos += Vec2(100.f * fDT, 0.f);
	}
	
	SetPos(vPos);
}

void Player::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	Rectangle(_dc
		, (int)(vPos.x - vScale.x / 2)
		, (int)(vPos.y - vScale.y / 2)
		, (int)(vPos.x + vScale.x / 2)
		, (int)(vPos.y + vScale.y / 2)
	);
}


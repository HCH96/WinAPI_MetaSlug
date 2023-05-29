#pragma once

#define SINGLE(type) public:\
							static type* GetInst()\
								{\
									static type mgr;\
									return &mgr;\
								}\
					private:\
							type();\
							~type();

// Time Manager
#define fDT TimeMgr::GetInst()->GetfDT()
#define DT TimeMgr::GetInst()->GetDT()


// Key Manager
#define KEY_CHECK(key, state) KeyMgr::GetInst()->GetKeyState(key) == state
#define KEY_HOLD(key) KEY_CHECK(key, KEY_STATE::HOLD)
#define KEY_TAP(key) KEY_CHECK(key, KEY_STATE::TAP)
#define KEY_AWAY(key) KEY_CHECK(key, KEY_STATE::AWAY)
#define KEY_NONE(key) KEY_CHECK(key, KEY_STATE::NONE)
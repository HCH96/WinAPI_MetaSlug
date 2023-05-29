#pragma once
#include "Scene.h"
class Scene_Play :
    public Scene
{


public:
    virtual void start();
    virtual void update();
    virtual void render(HDC _dc);

    virtual void Enter();
    virtual void Exit();


public:
    Scene_Play();
    ~Scene_Play();

};


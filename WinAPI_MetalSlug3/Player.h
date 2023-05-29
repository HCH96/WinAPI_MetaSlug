#pragma once
#include "Object.h"
class Player :
    public Object
{
private:


public:
    virtual void start();
    virtual void update();
    virtual void render(HDC _dc);

public:
    Player();
    ~Player();

};


#pragma once
#include "GameObject.h"
class Bullet :
    public GameObject
{
private:
    float BulletSpeed;
    float FRICTION;
    float ACCELERATION;
    float BulletLifeTime = 5;

public:
    Bullet();
    IShape2D& GetShape();
    void Update(float FrameTime);
    void initialise(float directions,Vector2D pos);
};


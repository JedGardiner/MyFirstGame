#pragma once
#include "GameObject.h"
#include "ObjectManager.h"
class Rock :
    public GameObject
{
private:
    float speed;
    float FRICTION;
    float ACCELERATION;
    ObjectManager* OM;

public:
    Rock();
    void Update(float FrameTime);
    void initialise(Vector2D pos, ObjectManager* OM);
    IShape2D& GetShape();
    void Death();
};


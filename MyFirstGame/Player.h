#pragma once
#include "errortype.h"
#include "windows.h"
#include "gametimer.h"
#include "GameObject.h"
#include "ObjectManager.h"


class Player : public GameObject
{
private: //because inherits from GameObject everything within game object does not need to be put in here.
	float speed;
	float FRICTION;
	float ACCELERATION;
	float cooldown;
	float pickup;
	int bombs;
	bool SoundPlaying;
	SoundIndex thrustSound;
	SoundIndex shootSound;

	ObjectManager* OM;

public:
	Player();
	void Update(float FrameTime);
	void initialise(Vector2D pos, ObjectManager* OM);
	IShape2D& GetShape();
	void Death();
};
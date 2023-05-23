#pragma once
#include "Rock.h"
#include "mysoundengine.h"
#include "ObjectManager.h"

Rock::Rock()
{
	active = false;
}

void Rock::initialise(Vector2D pos, ObjectManager* OM)
{
	active = true;
	position = (pos);
	velocity.setBearing(0, 0);
	direction = rand() % 628 / 100.0;
	speed = rand()%5;
	ACCELERATION = rand() % 10;
	FRICTION = 0.7;//slightly slower than the spaceship.
	LoadPicture(L"./assets/rock2.bmp");
	this->OM = OM;


	Message msg;
	msg.type = messageType::ENEMYSPAWN;
	msg.location = position;
	msg.psource = this;
	OM->SendMessage(msg);
}

IShape2D& Rock::GetShape()
{
	Circle2D answer;
	answer.PlaceAt(position,20);
	return answer;
}


void Rock::Update(float FrameTime)
{
	speed = speed + ACCELERATION;
	velocity.setBearing(direction, speed);
	speed = speed - FRICTION * speed * FrameTime;
	position = position + velocity * FrameTime;

}

void Rock::Death()
{
	Message msg;
}
#pragma once
#include "Bullet.h"
#include "mysoundengine.h"

Bullet::Bullet()
{
	active = false;
}

IShape2D& Bullet::GetShape()
{
	Rectangle2D answer;
	answer.PlaceAt(10,10,10,10);
	return answer;
}

void Bullet::initialise(float direction,Vector2D pos) 
{
	active = true;
	this->position = pos;
	BulletSpeed = 1000;
	this->direction = direction;
	velocity.setBearing(direction, BulletSpeed);//angle, magnitute (velocity)
	LoadPicture(L"./assets/touhouBullet.bmp");


}

void Bullet::Update(float FrameTime)
{
	position = position + velocity * FrameTime;

	//set active to false after set amount of time.
	BulletLifeTime -= FrameTime;
	if (BulletLifeTime <= 0)
	{
		active = false;
	}
}
#pragma once
#include "errortype.h"
#include "windows.h"
#include "mydrawengine.h"
#include "gametimer.h"
#include "Player.h"
#include "myinputs.h"
#include "mysoundengine.h"
#include "Bullet.h"
#include "ObjectManager.h"

Player::Player()
{
	active = false;
};
//not sure the way i have built this is correct
void Player::initialise(Vector2D pos, ObjectManager* OM )//change this to fix Objectfactory 
{
	active = true;//sets if in use
	position = pos; //sets position of ship
	velocity.setBearing(0, 0);
	direction = 0;
	ACCELERATION = 5000;
	speed = 0;
	this->OM = OM;
	FRICTION = 5;
	cooldown = 0;
	pickup = 0.5; //player cannot go below 0.1 because you can half the cooldown when holding shift 
	bombs = 3;
	SoundPlaying = false;
	LoadPicture(L"./assets/ship.bmp");
	MySoundEngine* pSE = MySoundEngine::GetInstance();
	//shootSound = pSE->LoadWav(L"shoot.wav");
	thrustSound = pSE->LoadWav(L"./assets/thrustloop2.wav");
	shootSound = pSE->LoadWav(L"./assets/shoot.wav");

	Message msg;
	msg.type = messageType::PLAYERSPAWNED;
	msg.location = position;
	msg.psource = this;
	OM->SendMessage(msg);//tells everyone taht spaceship exists and is created
};

IShape2D& Player::GetShape()
{
	Circle2D answer;
	answer.PlaceAt(position, 30);
	return answer;
}


void Player::Update(float FrameTime)
{
	MySoundEngine* pSE = MySoundEngine::GetInstance();
	MyInputs* pInputs = MyInputs::GetInstance();

	pInputs->SampleKeyboard();

	Vector2D acceleration;

	
	//movement controls
	if (pInputs->KeyPressed(DIK_LSHIFT) && pInputs->KeyPressed(DIK_W)) //Shift slows down the player
	{
		acceleration.YValue = ACCELERATION /2;
	}

	if (pInputs->KeyPressed(DIK_W) && !pInputs->KeyPressed(DIK_LSHIFT))// does detect the input im not sure how?
	{
		acceleration.YValue = ACCELERATION;
	}



	if (pInputs->KeyPressed(DIK_A) && !pInputs->KeyPressed(DIK_LSHIFT))
	{
		acceleration.XValue = -ACCELERATION;
	}

	if (pInputs->KeyPressed(DIK_A) && pInputs->KeyPressed(DIK_LSHIFT))
	{
		acceleration.XValue = -ACCELERATION/2;
	}



	if (pInputs->KeyPressed(DIK_S) && !pInputs->KeyPressed(DIK_LSHIFT))
	{
		acceleration.YValue -= ACCELERATION;
	}

	if (pInputs->KeyPressed(DIK_S) && pInputs->KeyPressed(DIK_LSHIFT))
	{
		acceleration.YValue -= ACCELERATION /2;
	}




	if (pInputs->KeyPressed(DIK_D) && !pInputs->KeyPressed(DIK_LSHIFT))
	{
		acceleration.XValue += ACCELERATION;
	}

	if (pInputs->KeyPressed(DIK_D) && pInputs->KeyPressed(DIK_LSHIFT))
	{
		acceleration.XValue += ACCELERATION /2;
	}

	if (pInputs->NewKeyPressed(DIK_1))
	{
		if (pickup <= 0.1)
		{
			pickup = 0.1;
		}
		pickup = pickup - 0.01;
	}


	if (pInputs->KeyPressed(DIK_SPACE) && !pInputs->KeyPressed(DIK_LSHIFT))
	{
		if (cooldown <= 0)
		{
			GameObject* pBullet1 = OM->AddFactoryObj(L"Bullet_1");//creates a pointer to pBullet1 (option 1 of bullet type) and 
			

			pBullet1->initialise(direction, position);//initialise doesnt work currently.
			pSE->Play(shootSound, false);
			
			
			cooldown = pickup;


		}

		
	}

	if (pInputs->KeyPressed(DIK_SPACE) && pInputs->KeyPressed(DIK_LSHIFT))
	{
		if (cooldown <= 0)
		{
			GameObject* pBullet1 = OM->AddFactoryObj(L"Bullet_1");

			pBullet1->initialise(direction, position);//initialise doesnt work currently.
			pSE->Play(shootSound, false);


				cooldown = pickup/2;
		}

	}

	if (pInputs->KeyPressed(DIKEYBOARD_1))//clears all enemies on screen.
	{
		if (bombs != 0)
		{
			bombs--;

		}
	}





	cooldown -= FrameTime;
	if (speed <= 0)
	{
		if (SoundPlaying)
		{
			SoundPlaying = false;
			pSE->Stop(thrustSound);
		}


	}
	//to stop sound's playing

	velocity = velocity + acceleration * FrameTime;

	velocity = velocity - FRICTION * velocity * FrameTime;
	
	if (acceleration.magnitude() < 10.0f) //adds Friction twice if the magnitude is less than 10.0f
	{
		velocity = velocity - FRICTION * velocity * FrameTime;
	}
	position = position + velocity * FrameTime;

};

void Player::Death()//this kills spaceship.
{
	Message msg;
	msg.type = messageType::OBJECTKILLED;
	msg.location = position;
	msg.psource = this;
	OM->SendMessage(msg);//tells everyone taht spaceship exists and is created

}
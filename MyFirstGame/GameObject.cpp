#pragma once
#include "GameObject.h"
GameObject::GameObject()
{

}

void GameObject::LoadPicture(const wchar_t filename[])
{
	image = MyDrawEngine::GetInstance()->LoadPicture(filename);//loads picture and remembers where is inside image
}


void GameObject::Render()
{
	if(active != false)
	{
		MyDrawEngine* pDE = MyDrawEngine::GetInstance(); //draw engine used to draw an image 
		pDE->DrawAt(position, image, 2.0f, direction); // position, image,scale ,angle ,transparecy 
	}
}

GameObject::~GameObject() 
{

}

bool GameObject::IsActive()
{
	return active;
}


void GameObject::Deactivate()
{
	active = false;
}

void GameObject::initialise(float direction, Vector2D pos)
{
}


void GameObject::HandleMessage(Message M)
{

}

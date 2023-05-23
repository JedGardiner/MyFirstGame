#pragma once
#include "vector2D.h"
#include "mydrawengine.h"
#include "mysoundengine.h"
class GameObject;

enum class messageType{ PLAYERSPAWNED,OBJECTKILLED, ENEMYSPAWN};
struct Message { //classes with no functions
	messageType type;
	Vector2D location;
	GameObject* psource;
	int other;
};


class GameObject
{
	//- is private
	//# protected means accessable by children classes 
protected:
	Vector2D position; //position of the child
	Vector2D velocity;
	float direction; //angle facing
	bool active; //set child object active or not
	void LoadPicture(const wchar_t[]);//if goes purple rename

private:
	PictureIndex image; //allows for different images to be loaded within the superclass
public:
	GameObject();
	virtual	void Update(float FrameTime) = 0;//each obj moves in different ways so its to make it abstrac
	 virtual void Render(); //presume objects render the same way. optional if you dont add a =0 at the end
	 bool IsActive();
	 void Deactivate();
	 virtual void initialise(float directions, Vector2D pos);
	 virtual void HandleMessage(Message M);
	 virtual ~GameObject();
	 virtual IShape2D& GetShape() = 0;

};
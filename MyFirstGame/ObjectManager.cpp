#pragma once
#include "ObjectManager.h"
#include "Bullet.h"
#include"Player.h"
#include "Rock.h"
#include "LevelManager.h"
void ObjectManager::AddObj(GameObject* pGameObject)
{
	ObjectList.push_back(pGameObject);//adds obj to list
}

void ObjectManager::UpdateAll(float FT)
{
	for (GameObject* ObjectNext : ObjectList)
	{
		if (ObjectNext) //works because if its null it wouldnt = Objectnext
		{
			ObjectNext->Update(FT);
		}
	}
}

void ObjectManager::RenderAll()
{
	for (GameObject* ObjectNext : ObjectList)
	{
		if (ObjectNext)//works because if its null it equals 0 
		{
			ObjectNext->Render();
			MyDrawEngine::GetInstance()->WriteInt(50, 50, ObjectList.size(), MyDrawEngine::GREEN);
		}
	}
}

void ObjectManager::DeleteAll()
{
	for (GameObject* ObjectNext : ObjectList)
	{
		delete ObjectNext;

	}
	ObjectList.clear();//removes entire list after deleting ObjectList
}


GameObject* ObjectManager::AddFactoryObj(std::wstring objName) //making this currently.
{
	GameObject* pNewObject = nullptr;
	if (objName == L"Bullet_1")
	{
		pNewObject = new Bullet();
	}
	else if (objName == L"Player")
	{
		pNewObject = new Player();
	}
	else if (objName == L"Rock")
	{
		pNewObject = new Rock();
	}
	else
	{
		ErrorLogger::Write(L"Couldn't create item: ");
		ErrorLogger::Writeln(objName.c_str());
	}

	if (pNewObject)
	{
		AddObj(pNewObject);
	}
	return pNewObject;
}

void ObjectManager::setLevelManager(LevelManager* pLevelManager)
{
	pLvl = pLevelManager;
}

void ObjectManager::SendMessage(Message msg)
{
	for (GameObject*& ObjectNext : ObjectList)
	{
		ObjectNext->HandleMessage(msg);

	}
	pLvl->HandleMessage(msg);//level manager told about it here.
	//somewhere in game this needs to be used to set the level manager and object manager
}


void ObjectManager::DeleteInactiveObj()
{
	for (GameObject*& ObjectNext : ObjectList)//reference and value
	{
		if (ObjectNext && ObjectNext->IsActive() == false)
		{
			delete ObjectNext;
			ObjectNext = nullptr;
		}
	}
	ObjectList.remove(nullptr);//goes through list and if any nullptr it removes them.
}

void ObjectManager::CheckAllCollisions()
{
	std::list<GameObject*>::iterator it1;
	std::list<GameObject*>::iterator it2;


		for (it1 = ObjectList.begin(); it1 != ObjectList.end(); it1++)
		{
			for (it2 = std::next(it1); it2 != ObjectList.end(); it2++)
			{
				if (*it1 && *it2 && (*it1)->IsActive() && (*it2)->IsActive())
				{
					//if ((*it1)->GetShape().Intersects((*it2)->GetShape()))
				}

			}
		}




}




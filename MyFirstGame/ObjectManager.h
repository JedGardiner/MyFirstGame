#pragma once
#include "GameObject.h"
#include <list>
class LevelManager;


class ObjectManager
{
private:
	std::list<GameObject* > ObjectList;
	LevelManager* pLvl;
public:
	void AddObj(GameObject* pGameObject);
	void UpdateAll(float FT);
	void RenderAll();
	void DeleteAll();
	

	void DeleteInactiveObj();
	void CheckAllCollisions();
	GameObject* AddFactoryObj(std::wstring objName);

	void setLevelManager(LevelManager* pLevelManager);
	void SendMessage(Message msg);

};



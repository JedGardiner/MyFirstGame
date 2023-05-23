#pragma once
#include "ObjectManager.h"
class SpaceShip;
class LevelManager 
{
	
private:
	ObjectManager* OM;

	int currentLevel;
	int lives;
	SpaceShip* pPlayer;
	float respawnTimer;
	float levelTimer; //to spawn boss
	float endLevelTimer; //timer for end of level before next starts
	int killCount;//number of kills
	int score;//serperate points for kills

public:
	LevelManager();
	void SetOM(ObjectManager* pObjectManager);
	void LevelStart(int level);
	void GameStart();
	void Update(float FrameTime);
	void ShowUI();
	void HandleMessage(Message M);
	void AddScore(int score);
	
};


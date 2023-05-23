#include "LevelManager.h"
#
LevelManager::LevelManager()
{
}

void LevelManager::SetOM(ObjectManager* pObjectManager)
{
	OM = pObjectManager;
}

void LevelManager::LevelStart(int level)
{
	if (level == 1)
	{

	}
	if (level == 2)
	{
		
	}
	if (level == 3)
	{

	}
}

void LevelManager::GameStart()
{
	currentLevel++;
	lives = 3;
	LevelStart(1);


}

void LevelManager::Update(float FrameTime)
{
	if (currentLevel > 1)
	{
		LevelStart(currentLevel);
	}


}

void LevelManager::ShowUI()//
{

	MyDrawEngine* pDraw = MyDrawEngine::GetInstance();

}

void LevelManager::HandleMessage(Message M)
{
	if (M.type == messageType::OBJECTKILLED && M.psource == (GameObject*)pPlayer)
	{
		lives--;
		respawnTimer = 4.0f;
		pPlayer = nullptr;
	}

	else if (M.type == messageType::OBJECTKILLED)
	{
		//if (typeid(*(M.psource)) == typeid(Rock))//* between first two brackets dereference
		//{
		//	AddScore(20);
		//}

	}
	//updaet function countdown timer if lives 
}

void LevelManager::AddScore(int score)
{
	score = score + score;
}

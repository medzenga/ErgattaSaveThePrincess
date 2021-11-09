#include "LevelLoader.h"

LevelLoader::LevelLoader(PlayerMng& playerMngIn, EnemyMng& enemyMngIn, NpcMng& npcMngIn)
{
	playerMng = &playerMngIn;
	enemyMng = &enemyMngIn;
	npcMng = &npcMngIn;
}

LevelLoader::~LevelLoader()
{

}

bool LevelLoader::LoadLevel(int levelNum)
{
	if (playerMng == NULL || enemyMng == NULL || npcMng == NULL)
		return false;

	if (levelNum == 1)
	{
		playerMng->ClearAll();
		enemyMng->ClearAll();
		npcMng->ClearAll();

		pos3 posTemp;
		posTemp.x = 1.0f;
		posTemp.y = -2.0f;
		posTemp.z = 1.0f;
		playerMng->AddPlayer(1, posTemp);

		posTemp.x = 5.0f;
		posTemp.y = -1.0f;
		posTemp.z = 0.5f;
		enemyMng->AddEnemy(TURTLE, 1, posTemp);

		posTemp.x = 6.0f;
		posTemp.y = 4.0f;
		posTemp.z = -1.5f;
		enemyMng->AddEnemy(PUFFER, 1, posTemp);

		posTemp.x = 7.0f;
		posTemp.y = 2.0f;
		posTemp.z = 3.5f;
		enemyMng->AddEnemy(SQUAB, 1, posTemp);

		posTemp.x = 15.0f;
		posTemp.y = 6.0f;
		posTemp.z = 1.0f;
		enemyMng->AddEnemy(EVIL_BOSS, 1, posTemp);

		posTemp.x = 20.0f;
		posTemp.y = 6.0f;
		posTemp.z = 2.0f;
		npcMng->AddNpc(PRINCESS, posTemp);

		return true;
	}
	else if (levelNum == 2)
	{
		playerMng->ClearAll();
		enemyMng->ClearAll();
		npcMng->ClearAll();

		pos3 posTemp;
		posTemp.x = 1.0f;
		posTemp.y = 0.0f;
		posTemp.z = 1.0f;
		playerMng->AddPlayer(1, posTemp);

		return true;
	}

	return false;
}

#ifndef LEVEL_LOADER
#define LEVEL_LOADER

#include "PlayerMng.h"
#include "EnemyMng.h"
#include "NpcMng.h"

class LevelLoader
{
public:
	LevelLoader(PlayerMng* playerMngIn, EnemyMng* enemyMngIn, NpcMng* npcMngIn);
	~LevelLoader();

	bool LoadLevel(int levelNum);

private:
	PlayerMng* playerMng;
	EnemyMng* enemyMng;
	NpcMng* npcMng;
};

#endif
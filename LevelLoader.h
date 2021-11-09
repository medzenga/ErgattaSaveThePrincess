#ifndef LEVEL_LOADER
#define LEVEL_LOADER

#include "WorldMng.h"
#include "PlayerMng.h"
#include "EnemyMng.h"
#include "NpcMng.h"

class LevelLoader
{
public:
	LevelLoader(WorldMng& worldMngIn, PlayerMng& playerMngIn, EnemyMng& enemyMngIn, NpcMng& npcMngIn);
	~LevelLoader();

	bool LoadLevel(int levelNum);

private:
	WorldMng* worldMng;
	PlayerMng* playerMng;
	EnemyMng* enemyMng;
	NpcMng* npcMng;
};

#endif
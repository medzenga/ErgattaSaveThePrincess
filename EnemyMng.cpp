#include "EnemyMng.h"

EnemyMng::EnemyMng(WorldMng& worldMngIn, WeaponMng& weaponMngIn)
{
	worldMng = &worldMngIn;
	weaponMng = &weaponMngIn;
	subtypeArray = NULL;
}

EnemyMng::~EnemyMng()
{

}

void EnemyMng::LoadEnemyTypeDefs()	// Load variations of each enemy type that only differ by stats
{

}

void EnemyMng::AddEnemy(int enemyTypeEnum, int subType, const pos3& startingPos)
{
	ActorStats* newEnemyStats = NULL;		// passing NULL stats uses defaults
	if (subType > 1)
	{
		newEnemyStats = new ActorStats();
		// setup subtype data here if subType>1
	}

	GameObj* newEnemy = NULL;
	switch (enemyTypeEnum)
	{
	case PUFFER: newEnemy = new PufferObj(newEnemyStats, *worldMng, *weaponMng); break;
	case SQUAB: newEnemy = new SquabObj(newEnemyStats, *worldMng, *weaponMng); break;
	case TURTLE: newEnemy = new TurtleObj(newEnemyStats, *worldMng, *weaponMng); break;
	case EVIL_BOSS: newEnemy = new EvilBossObj(newEnemyStats, *worldMng, *weaponMng); break;
	}

	if (newEnemy == NULL)
	{
		if (newEnemyStats != NULL)
			delete newEnemyStats;

		return;
	}

	newEnemy->SetPos(startingPos);

	ObjMng::AddObject(*newEnemy);
}

void EnemyMng::ClearAll()
{
	ObjMng::ClearAll();
}

void EnemyMng::UpdateAll(float timeScale)
{
	ObjMng::UpdateAll(timeScale);
}

const void EnemyMng::RenderAll()
{
	ObjMng::RenderAll();
}

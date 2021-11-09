#include "EnemyMng.h"

EnemyMng::EnemyMng(WeaponMng& weaponMngIn)
{
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
	case PUFFER: newEnemy = new PufferObj(newEnemyStats, *weaponMng); break;
	case SQUAB: newEnemy = new SquabObj(newEnemyStats, *weaponMng); break;
	case TURTLE: newEnemy = new TurtleObj(newEnemyStats, *weaponMng); break;
	case EVIL_BOSS: newEnemy = new EvilBossObj(newEnemyStats, *weaponMng); break;
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

#ifndef ENEMY_MANAGER
#define ENEMY_MANAGER

#include "ObjMng.h"
#include "WorldMng.h"

#include "EvilBossObj.h"
#include "SquabObj.h"
#include "TurtleObj.h"
#include "PufferObj.h"

class EnemyMng : public ObjMng
{
public:
	EnemyMng(WorldMng& worldMngIn, WeaponMng& weaponMngIn);
	~EnemyMng();

	void LoadEnemyTypeDefs();	// Load variations of each enemy type that only differ by stats

	void AddEnemy(int enemyTypeEnum, int subType, const pos3& startingPos);
	void ClearAll();

	void UpdateAll(float timeScale);
	const void RenderAll();

private:
	WorldMng* worldMng;
	WeaponMng* weaponMng;
	ActorStats* subtypeArray;
};

#endif
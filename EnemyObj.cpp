#include "EnemyObj.h"

EnemyObj::EnemyObj(ActorStats* statsIn, WorldMng& worldMngIn, WeaponMng& weaponMngIn)
	: ActorObj(statsIn, worldMngIn, weaponMngIn)
{

}

EnemyObj::~EnemyObj()
{

}

void EnemyObj::Update(float timeScale)
{

}

const void EnemyObj::Render()
{

}

int EnemyObj::GetPoints()
{
	return awardedPoints.GetValue();
}
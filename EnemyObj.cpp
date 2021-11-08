#include "EnemyObj.h"

EnemyObj::EnemyObj(ActorStats* statsIn, WeaponMng* weaponMngIn)
	: ActorObj(statsIn, weaponMngIn)
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
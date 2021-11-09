#include "ActorObj.h"

ActorObj::ActorObj(ActorStats* statsIn, WeaponMng* weaponMngIn)
{
	if (statsIn != NULL)
		stats = *statsIn;

	weaponMng = weaponMngIn;
}

ActorObj::~ActorObj()
{

}

ActorStats ActorObj::GetActorStats()
{
	return stats;
}

void ActorObj::Update(float timeScale)
{

}

const void ActorObj::Render()
{

}

bool ActorObj::checkHasMoveType(int moveType)
{
	return false;
}
#include "ActorObj.h"

ActorObj::ActorObj(ActorStats* statsIn, WorldMng& worldMngIn, WeaponMng& weaponMngIn)
{
	if (statsIn != NULL)
		stats = *statsIn;

	worldMng = &worldMngIn;
	weaponMng = &weaponMngIn;
}

ActorObj::~ActorObj()
{

}

ActorStats ActorObj::GetActorStats()
{
	return stats;
}

StatEnum* ActorObj::GetStatusEffects()
{
	return &statusEffects;
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
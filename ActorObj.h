#ifndef ACTOR_OBJ
#define ACTOR_OBJ

#include "GameObj.h"
#include "ActorStats.h"
#include "WeaponMng.h"
#include "WorldMng.h"

class ActorObj : public GameObj
{
public:
	ActorObj(ActorStats* statsIn, WorldMng& worldMngIn, WeaponMng& weaponMngIn);
	~ActorObj();

	ActorStats GetActorStats();
	StatEnum* GetStatusEffects();

protected:
	void Update(float timeScale);
	const void Render();

	bool checkHasMoveType(int moveType);

	ActorStats stats;
	StatEnum statusEffects;
	WorldMng* worldMng;
	WeaponMng* weaponMng;
};

#endif
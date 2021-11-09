#ifndef ACTOR_OBJ
#define ACTOR_OBJ

#include "GameObj.h"
#include "ActorStats.h"
#include "WeaponMng.h"

class ActorObj : public GameObj
{
public:
	ActorObj(ActorStats* statsIn, WeaponMng& weaponMngIn);
	~ActorObj();

	ActorStats GetActorStats();
	StatEnum* GetStatusEffects();

protected:
	void Update(float timeScale);
	const void Render();

	bool checkHasMoveType(int moveType);

	ActorStats stats;
	StatEnum statusEffects;
	WeaponMng* weaponMng;
};

#endif
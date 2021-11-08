#ifndef PLAYER_OBJ
#define PLAYER_OBJ

#include "ActorObj.h"
#include "StatInt.h"

class PlayerObj : public ActorObj
{
public:
	PlayerObj(ActorStats* statsIn, WeaponMng* weaponMngIn);
	~PlayerObj();

	void Update(float timeScale);
	const void Render();

	StatInt& GetScore();

private:
	StatInt score;
	WeaponMng* weaponMng;
};

#endif
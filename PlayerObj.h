#ifndef PLAYER_OBJ
#define PLAYER_OBJ

#include "ActorObj.h"
#include "StatInt.h"
#include "InputHandler.h"

class PlayerObj : public ActorObj
{
public:
	PlayerObj(int playerNumIn, ActorStats* statsIn, WeaponMng& weaponMngIn);
	~PlayerObj();

	void Update(float timeScale, const Inputs& inputs);
	const void Render();

	StatInt& GetScore();

private:
	StatInt score;
	int playerNum;
};

#endif
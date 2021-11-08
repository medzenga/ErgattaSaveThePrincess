#ifndef PRINCESS
#define PRINCESS 0x30000001

#include "ActorObj.h"

class PrincessObj : public ActorObj
{
public:
	PrincessObj(ActorStats* statsIn, WeaponMng* weaponMngIn);
	~PrincessObj();

	void Update(float timeScale);
	const void Render();

private:
};

#endif
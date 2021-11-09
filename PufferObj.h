#ifndef PUFFER
#define PUFFER 0x10000003

#include "EnemyObj.h"

class PufferObj : public EnemyObj
{
public:
	PufferObj(ActorStats* statsIn, WorldMng& worldMngIn, WeaponMng& weaponMngIn);
	~PufferObj();

	void Update(float timeScale);
	const void Render();

private:

};

#endif
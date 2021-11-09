#ifndef EVIL_BOSS
#define EVIL_BOSS 0x20000001

#include "EnemyObj.h"

class EvilBossObj : public EnemyObj
{
public:
	EvilBossObj(ActorStats* statsIn, WeaponMng& weaponMngIn);
	~EvilBossObj();

	void Update(float timeScale);
	const void Render();

private:

};

#endif
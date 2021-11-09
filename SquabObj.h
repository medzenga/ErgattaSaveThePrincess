#ifndef SQUAB
#define SQUAB 0x10000001

#include "EnemyObj.h"

class SquabObj : public EnemyObj
{
public:
	SquabObj(ActorStats* statsIn, WorldMng& worldMngIn, WeaponMng& weaponMngIn);
	~SquabObj();

	void Update(float timeScale);
	const void Render();

private:

};

#endif
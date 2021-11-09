#ifndef TURTLE
#define TURTLE 0x10000002

#include "EnemyObj.h"

class TurtleObj : public EnemyObj
{
public:
	TurtleObj(ActorStats* statsIn, WeaponMng& weaponMngIn);
	~TurtleObj();

	void Update(float timeScale);
	const void Render();

private:

};

#endif
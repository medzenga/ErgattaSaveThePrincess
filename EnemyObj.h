#ifndef ENEMY_OBJ
#define ENEMY_OBJ

#include "ActorObj.h"
#include "StatInt.h"

class EnemyObj : public ActorObj
{
public:
	EnemyObj(ActorStats* statsIn, WeaponMng* weaponMngIn);
	~EnemyObj();

	void Update(float timeScale);
	const void Render();

	int GetPoints();

protected:
	StatInt awardedPoints;
};

#endif
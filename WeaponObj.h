#ifndef WEAPON_OBJ
#define WEAPON_OBJ

#include "GameObj.h"
#include "StatFloat.h"
#include "WeaponStats.h"

class WeaponObj : public GameObj
{
public:
	WeaponObj(WeaponStats& statsIn);
	~WeaponObj();

	WeaponStats& GetStats();

private:
	WeaponStats stats;
};

#endif
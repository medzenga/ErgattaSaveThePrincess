#ifndef WEAPON_OBJ
#define WEAPON_OBJ

#include "GameObj.h"
#include "StatFloat.h"
#include "WeaponStats.h"

class WeaponObj : public GameObj
{
public:
	WeaponObj(const WeaponStats& statsIn);
	~WeaponObj();

	WeaponStats& GetStats();

	const void operator=(const WeaponObj& rhs);		// deep copy overload for '='

private:
	WeaponStats stats;
};

#endif
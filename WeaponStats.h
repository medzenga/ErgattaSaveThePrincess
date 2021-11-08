#ifndef WEAPON_STATS
#define WEAPON_STATS

#include "StatFloat.h"

#define WEAPON_MELEE 1
#define WEAPON_HITSCAN 2
#define WEAPON_PROJECTILE 3
#define WEAPON_AOE 4

class WeaponStats
{
public:
	WeaponStats();
	~WeaponStats();

	StatFloat& GetDamageStat();
	StatFloat& GetRangeStat();
	StatFloat& GetCooldownStat();
	StatFloat& GetAttackDurationStat();
	void SetType(int typeEnum);
	int GetType();

	const void operator=(const WeaponStats& rhs);		// deep copy overload for '='

private:
	StatFloat damage;
	StatFloat range;
	StatFloat cooldown;
	StatFloat attackDuration;
	int type;
};

#endif
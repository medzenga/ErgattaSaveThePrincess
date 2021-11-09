#ifndef WEAPON_STATS
#define WEAPON_STATS

#include "StatFloat.h"

#define WEAPON_NONE 0x00100000
#define WEAPON_MELEE 0x00100001
#define WEAPON_HITSCAN 0x00100002
#define WEAPON_PROJECTILE 0x00100003
#define WEAPON_AOE 0x00100004

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
	void SetCategory(int categoryEnum);
	int GetCategory();

	const void operator=(const WeaponStats& rhs);		// deep copy overload for '='

private:
	StatFloat damage;
	StatFloat range;
	StatFloat cooldown;
	StatFloat attackDuration;
	int type;
	int category;
};

#endif
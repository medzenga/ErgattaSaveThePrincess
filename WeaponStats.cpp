#include "WeaponStats.h"

WeaponStats::WeaponStats()
{
	type = 0;
}

WeaponStats::~WeaponStats()
{

}

StatFloat& WeaponStats::GetDamageStat()
{
	return damage;
}

StatFloat& WeaponStats::GetRangeStat()
{
	return range;
}

StatFloat& WeaponStats::GetCooldownStat()
{
	return cooldown;
}

StatFloat& WeaponStats::GetAttackDurationStat()
{
	return attackDuration;
}

void WeaponStats::SetType(int typeEnum)
{
	type = typeEnum;
}

int WeaponStats::GetType()
{
	return type;
}

const void WeaponStats::operator=(const WeaponStats& rhs)		// deep copy overload for '='
{
	damage = rhs.damage;
	range = rhs.range;
	cooldown = rhs.cooldown;
	type = rhs.type;
}

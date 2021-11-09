#include "WeaponStats.h"

WeaponStats::WeaponStats()
{
	type = TYPE_NONE;
	category = WEAPON_NONE;
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

void WeaponStats::SetCategory(int categoryEnum)
{
	category = categoryEnum;
}

int WeaponStats::GetCategory()
{
	return category;
}

StatEnum* WeaponStats::getAdditionalEffects()
{
	return &additionalEffects;
}

const void WeaponStats::operator=(const WeaponStats& rhs)		// deep copy overload for '='
{
	damage = rhs.damage;
	range = rhs.range;
	cooldown = rhs.cooldown;
	type = rhs.type;
	category = rhs.category;
}

#include "ActorStats.h"

ActorStats::ActorStats()
{
	equippedWeaponList = NULL;
	movementTypes = 0;
}

ActorStats::~ActorStats()
{

}

StatFloat& ActorStats::GetHealthStat()
{
	return health;
}

StatFloat& ActorStats::GetArmorStat()
{
	return armor;
}

void ActorStats::ClearWeapons()
{

}

void ActorStats::EquipWeapon(WeaponObj& weaponToEquip)
{

}

const WeaponObj* ActorStats::GetWeaponData()
{
	return NULL;
}

void ActorStats::AddMovementType(int moveAdd)
{

}

void ActorStats::RemoveMovementType(int moveRemove)
{

}

bool ActorStats::GetHasMovementType(int moveType)
{
	return false;
}

const void ActorStats::operator=(const ActorStats& rhs)		// deep copy overload for '='
{

}
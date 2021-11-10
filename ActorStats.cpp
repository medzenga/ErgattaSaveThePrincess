#include "ActorStats.h"

ActorStats::ActorStats()
{
	equippedWeaponList = NULL;
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
	while (equippedWeaponList != NULL)
	{
		WeaponObj* tempObj = equippedWeaponList;
		equippedWeaponList = static_cast<WeaponObj*>(equippedWeaponList->next);
		delete tempObj;
	}
}

void ActorStats::EquipWeapon(WeaponObj& weaponToEquip)
{
	WeaponObj* newWeaponInstance = new WeaponObj(weaponToEquip);
	newWeaponInstance->next = equippedWeaponList;
	equippedWeaponList = newWeaponInstance;
}

const WeaponObj* ActorStats::GetWeaponData()
{
	return NULL;
}

void ActorStats::AddMovementType(int moveAdd)
{
	movementTypes.AddEnum(moveAdd);
}

void ActorStats::RemoveMovementType(int moveRemove)
{
	movementTypes.RemoveEnum(moveRemove);
}

bool ActorStats::GetHasMovementType(int moveType)
{
	return false;
}

const void ActorStats::operator=(const ActorStats& rhs)		// deep copy overload for '='
{
	health = rhs.health;
	armor = rhs.armor;
	movementTypes = rhs.movementTypes;

	WeaponObj* iterator = rhs.equippedWeaponList;
	while (iterator != NULL)
	{
		EquipWeapon(*iterator);
		iterator = static_cast<WeaponObj*>(iterator->next);
	}
}
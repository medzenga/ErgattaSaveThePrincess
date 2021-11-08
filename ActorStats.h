#ifndef ACTOR_STATS
#define ACTOR_STATS

#include "WeaponObj.h"
#include "StatFloat.h"

#define MOVE_GROUND 0x00000001
#define MOVE_AIR 0x00000002
#define MOVE_WATER 0x00000004

class ActorStats
{
public:
	ActorStats();
	~ActorStats();

	StatFloat& GetHealthStat();
	StatFloat& GetArmorStat();

	void ClearWeapons();
	void EquipWeapon(WeaponObj& weaponToEquip);
	const WeaponObj* GetWeaponData();

	void AddMovementType(int moveAdd);
	void RemoveMovementType(int moveRemove);
	bool GetHasMovementType(int moveType);

	const void operator=(const ActorStats& rhs);		// deep copy overload for '='

private:
	StatFloat health;
	StatFloat armor;
	WeaponObj* equippedWeaponList;
	int movementTypes;
};

#endif
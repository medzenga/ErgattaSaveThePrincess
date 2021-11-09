#include "WeaponMng.h"

WeaponMng::WeaponMng()
{
	WeaponStats* weaponStatsTemp = new WeaponStats();
	weaponDefList = new WeaponObj(*weaponStatsTemp);
	delete weaponStatsTemp;
}

WeaponMng::~WeaponMng()
{

}

void WeaponMng::AddWeapon(int weaponEnum)
{

}

void WeaponMng::ClearAll()
{
	ObjMng::ClearAll();
}

WeaponObj WeaponMng::GetWeaponData(int weaponEnum)
{
	for (GameObj* iterator = weaponDefList; iterator != NULL; iterator = iterator->next)
	{
		if (static_cast<WeaponObj*>(iterator)->GetStats().GetType() == weaponEnum)
			return *static_cast<WeaponObj*>(iterator);
	}

	return *weaponDefList;
}

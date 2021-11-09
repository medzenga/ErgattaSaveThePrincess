#include "WeaponMng.h"

WeaponMng::WeaponMng()
{
	// setup default weapon stats here; otherwise use imported data

	WeaponStats* weaponStatsTemp = new WeaponStats();
	weaponStatsTemp->SetType(TYPE_NONE);
	weaponStatsTemp->SetCategory(WEAPON_NONE);
	AddWeapon(*weaponStatsTemp, NULL);
	
	weaponStatsTemp->GetDamageStat().SetStartingValue(10);
	weaponStatsTemp->GetAttackDurationStat().SetStartingValue(2);
	weaponStatsTemp->GetCooldownStat().SetStartingValue(1);
	weaponStatsTemp->GetRangeStat().SetStartingValue(20);
	weaponStatsTemp->SetType(SHOTGUN);
	weaponStatsTemp->SetCategory(WEAPON_HITSCAN);
	AddWeapon(*weaponStatsTemp, NULL);


	delete weaponStatsTemp;
}

WeaponMng::~WeaponMng()
{

}

void WeaponMng::AddWeapon(const WeaponStats& statsIn, unsigned int modelIn)
{
	GameObj* newWeapon = new WeaponObj(statsIn, modelIn);
	ObjMng::AddObject(newWeapon);
}

void WeaponMng::ClearAll()
{
	ObjMng::ClearAll();
}

WeaponObj WeaponMng::GetWeaponData(int weaponEnum)
{
	for (GameObj* iterator =objList; iterator != NULL; iterator = iterator->next)
	{
		if (static_cast<WeaponObj*>(iterator)->GetStats().GetType() == weaponEnum)
			return *static_cast<WeaponObj*>(iterator);
	}

	// handle empty list here

	return *static_cast<WeaponObj*>(objList);
}

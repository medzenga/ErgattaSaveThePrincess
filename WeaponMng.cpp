#include "WeaponMng.h"

WeaponMng::WeaponMng()
{
	// setup default weapon stats here; otherwise use imported data

	WeaponStats* weaponStatsTemp = new WeaponStats();
	AddWeapon(*weaponStatsTemp, NULL);

	defaultWeapon = new WeaponObj(*weaponStatsTemp, NULL);
	
	weaponStatsTemp->GetDamageStat().SetStartingValue(10);
	weaponStatsTemp->GetAttackDurationStat().SetStartingValue(2);
	weaponStatsTemp->GetCooldownStat().SetStartingValue(1);
	weaponStatsTemp->GetRangeStat().SetStartingValue(20);
	weaponStatsTemp->SetType(SHOTGUN);
	weaponStatsTemp->SetCategory(WEAPON_HITSCAN);
	AddWeapon(*weaponStatsTemp, NULL);

	weaponStatsTemp->GetDamageStat().SetStartingValue(15);
	weaponStatsTemp->GetAttackDurationStat().SetStartingValue(2);
	weaponStatsTemp->GetCooldownStat().SetStartingValue(8);
	weaponStatsTemp->GetRangeStat().SetStartingValue(50);
	weaponStatsTemp->SetType(FIREBALL);
	weaponStatsTemp->SetCategory(WEAPON_PROJECTILE);
	AddWeapon(*weaponStatsTemp, NULL);

	weaponStatsTemp->GetDamageStat().SetStartingValue(30);
	weaponStatsTemp->GetAttackDurationStat().SetStartingValue(2);
	weaponStatsTemp->GetCooldownStat().SetStartingValue(25);
	weaponStatsTemp->GetRangeStat().SetStartingValue(5);
	weaponStatsTemp->SetType(BATTLE_AXE);
	weaponStatsTemp->SetCategory(WEAPON_MELEE);
	AddWeapon(*weaponStatsTemp, NULL);

	weaponStatsTemp->GetDamageStat().SetStartingValue(15);
	weaponStatsTemp->GetAttackDurationStat().SetStartingValue(2);
	weaponStatsTemp->GetCooldownStat().SetStartingValue(15);
	weaponStatsTemp->GetRangeStat().SetStartingValue(10);
	weaponStatsTemp->SetType(BOMB);
	weaponStatsTemp->SetCategory(WEAPON_AOE);
	AddWeapon(*weaponStatsTemp, NULL);

	weaponStatsTemp->GetDamageStat().SetStartingValue(10);
	weaponStatsTemp->GetAttackDurationStat().SetStartingValue(2);
	weaponStatsTemp->GetCooldownStat().SetStartingValue(20);
	weaponStatsTemp->GetRangeStat().SetStartingValue(10);
	weaponStatsTemp->SetType(SHELL_SHOCK);
	weaponStatsTemp->SetCategory(WEAPON_AOE);
	AddWeapon(*weaponStatsTemp, NULL);

	weaponStatsTemp->GetDamageStat().SetStartingValue(1);
	weaponStatsTemp->GetAttackDurationStat().SetStartingValue(1);
	weaponStatsTemp->GetCooldownStat().SetStartingValue(1);
	weaponStatsTemp->GetRangeStat().SetStartingValue(2);
	weaponStatsTemp->SetType(POISON_TOUCH);
	weaponStatsTemp->SetCategory(WEAPON_MELEE);
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
	if (weaponEnum == NULL)
		weaponEnum = TYPE_NONE;

	for (GameObj* iterator =objList; iterator != NULL; iterator = iterator->next)
	{
		if (static_cast<WeaponObj*>(iterator)->GetStats().GetType() == weaponEnum)
			return *static_cast<WeaponObj*>(iterator);
	}

	return *defaultWeapon;		// return default empty weapon if not found
}

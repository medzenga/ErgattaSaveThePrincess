#ifndef WEAPON_MANAGER
#define WEAPON_MANAGER

#include "ObjMng.h"
#include "WeaponObj.h"

class WeaponMng : public ObjMng
{
public:
	WeaponMng();
	~WeaponMng();

	void AddWeapon(const WeaponStats& statsIn, unsigned int modelIn);
	void ClearAll();

	WeaponObj GetWeaponData(int weaponEnum);

private:
	WeaponObj* defaultWeapon;
};

#endif
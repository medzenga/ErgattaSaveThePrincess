#ifndef WEAPON_MANAGER
#define WEAPON_MANAGER

#include "ObjMng.h"
#include "WeaponObj.h"

#define NONE 0x01000000
#define SHOTGUN 0x01000001
#define FIREBALL 0x01000002
#define BATTLE_AXE 0x01000003
#define BOMB 0x01000004
#define SHELL_SHOCK 0x01000005
#define POISON_TOUCH 0x01000006

class WeaponMng : public ObjMng
{
public:
	WeaponMng();
	~WeaponMng();

	void AddWeapon(int weaponEnum);
	void ClearAll();

	WeaponObj GetWeaponData(int weaponEnum);

private:
	WeaponObj* weaponDefList;
};

#endif
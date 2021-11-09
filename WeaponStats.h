#ifndef WEAPON_STATS
#define WEAPON_STATS

#include "StatFloat.h"
#include "StatEnum.h"

#define WEAPON_NONE 0x00000000
#define WEAPON_MELEE 0x00000001
#define WEAPON_HITSCAN 0x00000002
#define WEAPON_PROJECTILE 0x00000004
#define WEAPON_AOE 0x00000008

#define TYPE_NONE 0x00000000
#define SHOTGUN 0x00000100
#define FIREBALL 0x00000200
#define BATTLE_AXE 0x00000400
#define BOMB 0x00000800
#define SHELL_SHOCK 0x00001000
#define POISON_TOUCH 0x00002000

#define EFFECT_NONE 0x00000000
#define EFFECT_POISON 0x00010000
#define EFFECT_SLEEP 0x00020000
#define EFFECT_SLOW 0x00040000
#define EFFECT_CURSE 0x00080000
#define EFFECT_STONE 0x00100000
#define EFFECT_HASTE 0x00200000
#define EFFECT_PARALYZE 0x00400000
#define EFFECT_DEATH 0x00800000

class WeaponStats
{
public:
	WeaponStats();
	~WeaponStats();

	StatFloat& GetDamageStat();
	StatFloat& GetRangeStat();
	StatFloat& GetCooldownStat();
	StatFloat& GetAttackDurationStat();
	void SetType(int typeEnum);
	int GetType();
	void SetCategory(int categoryEnum);
	int GetCategory();

	StatEnum* getAdditionalEffects();

	const void operator=(const WeaponStats& rhs);		// deep copy overload for '='

private:
	StatFloat damage;
	StatFloat range;
	StatFloat cooldown;
	StatFloat attackDuration;
	StatEnum additionalEffects;
	int type;
	int category;
};

#endif
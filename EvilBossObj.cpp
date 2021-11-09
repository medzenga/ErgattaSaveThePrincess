#include "EvilBossObj.h"
#include "WeaponMng.h"

const float defaultHealth = 500;
const float defaultArmor = 100;
const int defaultWeapon1 = FIREBALL;
const int defaultWeapon2 = BATTLE_AXE;
const int defaultMoveType = MOVE_GROUND;

const int defaultPoints = 5000;

EvilBossObj::EvilBossObj(ActorStats* statsIn, WeaponMng& weaponMngIn)
	: EnemyObj(statsIn, weaponMngIn)
{
	if (statsIn == NULL)
	{
		stats.GetHealthStat().SetStartingValue(defaultHealth);
		stats.GetArmorStat().SetStartingValue(defaultArmor);
		stats.AddMovementType(defaultMoveType);

		WeaponObj weaponData1 = weaponMng->GetWeaponData(defaultWeapon1);
		WeaponObj weaponData2 = weaponMng->GetWeaponData(defaultWeapon2);

		stats.EquipWeapon(weaponData1);
		stats.EquipWeapon(weaponData2);
	}

	awardedPoints.SetStartingValue(defaultPoints);
}

EvilBossObj::~EvilBossObj()
{

}

void EvilBossObj::Update(float timeScale)
{

}

const void EvilBossObj::Render()
{

}

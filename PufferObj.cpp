#include "PufferObj.h"

const float defaultHealth = 60;
const float defaultArmor = 20;
const int defaultWeapon = POISON_TOUCH;
const int defaultMoveType = MOVE_WATER;

const int defaultPoints = 50;

PufferObj::PufferObj(ActorStats* statsIn, WeaponMng* weaponMngIn)
	: EnemyObj(statsIn, weaponMngIn)
{
	if (statsIn == NULL)
	{
		stats.GetHealthStat().SetStartingValue(defaultHealth);
		stats.GetArmorStat().SetStartingValue(defaultArmor);
		stats.AddMovementType(defaultMoveType);

		WeaponObj weaponData = weaponMng->GetWeaponData(defaultWeapon);
		stats.EquipWeapon(weaponData);
	}

	awardedPoints.SetStartingValue(defaultPoints);
}

PufferObj::~PufferObj()
{

}

void PufferObj::Update(float timeScale)
{

}

const void PufferObj::Render()
{

}
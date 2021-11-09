#include "SquabObj.h"

const float defaultHealth = 50;
const float defaultArmor = 0;
const int defaultWeapon = BOMB;
const int defaultMoveType = MOVE_AIR;

const int defaultPoints = 75;

SquabObj::SquabObj(ActorStats* statsIn, WeaponMng& weaponMngIn)
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

SquabObj::~SquabObj()
{

}

void SquabObj::Update(float timeScale)
{

}

const void SquabObj::Render()
{

}
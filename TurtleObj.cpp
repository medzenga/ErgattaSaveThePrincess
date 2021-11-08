#include "TurtleObj.h"

const float defaultHealth = 60;
const float defaultArmor = 50;
const int defaultWeapon = SHELL_SHOCK;
const int defaultMoveType = MOVE_GROUND;

const int defaultPoints = 25;

TurtleObj::TurtleObj(ActorStats* statsIn, WeaponMng* weaponMngIn)
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

TurtleObj::~TurtleObj()
{

}

void TurtleObj::Update(float timeScale)
{

}

const void TurtleObj::Render()
{

}
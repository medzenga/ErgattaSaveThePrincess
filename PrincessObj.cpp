#include "PrincessObj.h"

const float defaultHealth = 80;
const float defaultArmor = 0;
const int defaultWeapon = NULL;
const int defaultMoveType = MOVE_GROUND;

PrincessObj::PrincessObj(ActorStats* statsIn, WeaponMng* weaponMngIn)
	: ActorObj(statsIn, weaponMngIn)
{
	if (statsIn == NULL)
	{
		stats.GetHealthStat().SetStartingValue(defaultHealth);
		stats.GetArmorStat().SetStartingValue(defaultArmor);

		stats.AddMovementType(defaultMoveType);

		WeaponObj weaponData = weaponMng->GetWeaponData(defaultWeapon);

		stats.EquipWeapon(weaponData);
	}
}

PrincessObj::~PrincessObj()
{

}

void PrincessObj::Update(float timeScale)
{

}

const void PrincessObj::Render()
{

}
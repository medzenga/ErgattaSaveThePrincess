#include "PlayerObj.h"
#include "WeaponMng.h"

const float defaultHealth = 100;
const float defaultArmor = 100;
const int defaultWeapon = SHOTGUN;
const int defaultMoveType = MOVE_GROUND;

PlayerObj::PlayerObj(int playerNumIn, ActorStats* statsIn, WorldMng& worldMngIn, WeaponMng& weaponMngIn)
	: ActorObj(statsIn, worldMngIn, weaponMngIn)
{
	if (statsIn == NULL)
	{
		stats.GetHealthStat().SetMaxValue(defaultHealth);
		stats.GetHealthStat().SetMinValue(0);
		stats.GetHealthStat().SetValue(defaultHealth);

		stats.GetArmorStat().SetMaxValue(defaultArmor);
		stats.GetArmorStat().SetMinValue(0);
		stats.GetArmorStat().SetValue(defaultArmor);

		stats.AddMovementType(defaultMoveType);

		WeaponObj weaponData = weaponMng->GetWeaponData(defaultWeapon);

		stats.EquipWeapon(weaponData);
	}

	score.SetMaxValue(1000000);
	score.SetValue(0);

	playerNum = playerNumIn;
}

PlayerObj::~PlayerObj()
{

}

void PlayerObj::Update(float timeScale, const Inputs& inputs)
{

}

const void PlayerObj::Render()
{

}

StatInt& PlayerObj::GetScore()
{
	return score;
}
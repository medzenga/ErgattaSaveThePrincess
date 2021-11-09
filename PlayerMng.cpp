#include "PlayerMng.h"

PlayerMng::PlayerMng(WeaponMng& weaponMngIn)
{
	weaponMng = &weaponMngIn;
}

PlayerMng::~PlayerMng()
{

}

void PlayerMng::AddPlayer(int playerNum, const pos3& startingPos)
{
	GameObj* newPlayer = new PlayerObj(playerNum, NULL, *weaponMng);
	newPlayer->SetPos(startingPos);
	ObjMng::AddObject(*newPlayer);
}

void PlayerMng::ClearAll()
{
	ObjMng::ClearAll();
}

void PlayerMng::UpdateAll(float timeScale, const Inputs& inputs)
{
	for (GameObj* objIterator = objList; objIterator != NULL; objIterator = objIterator->next)
		static_cast<PlayerObj*>(objIterator)->Update(timeScale, inputs);
}

const void PlayerMng::RenderAll()
{
	ObjMng::RenderAll();
}

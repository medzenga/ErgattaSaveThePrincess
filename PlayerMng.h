#ifndef PLAYER_MANAGER
#define PLAYER_MANAGER

#include "ObjMng.h"
#include "WorldMng.h"
#include "PlayerObj.h"
#include "InputHandler.h"

class PlayerMng : public ObjMng
{
public:
	PlayerMng(WorldMng& worldMngIn, WeaponMng& weaponMngIn);
	~PlayerMng();

	void AddPlayer(int playerNum, const pos3& startingPos);
	void ClearAll();

	void UpdateAll(float timeScale, const Inputs& inputs);
	const void RenderAll();

private:
	WorldMng* worldMng;
	WeaponMng* weaponMng;
};

#endif
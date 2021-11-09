#ifndef NPC_MANAGER
#define NPC_MANAGER

#include "ObjMng.h"
#include "PrincessObj.h"
#include "WeaponMng.h"

class NpcMng : public ObjMng
{
public:
	NpcMng(WorldMng& worldMngIn, WeaponMng& weaponMngIn);
	~NpcMng();

	void LoadNpcDefs();

	void AddNpc(int npcTypeEnum, const pos3& startingPos);
	void ClearAll();

	void UpdateAll(float timeScale);
	const void RenderAll();

private:
	WorldMng* worldMng;
	WeaponMng* weaponMng;
};

#endif
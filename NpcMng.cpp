#include "NpcMng.h"

NpcMng::NpcMng(WorldMng& worldMngIn, WeaponMng& weaponMngIn)
{
	worldMng = &worldMngIn;
	weaponMng = &weaponMngIn;
}

NpcMng::~NpcMng()
{

}

void NpcMng::LoadNpcDefs()
{

}

void NpcMng::AddNpc(int npcTypeEnum, const pos3& startingPos)
{
	if (npcTypeEnum == PRINCESS)
	{
		GameObj* newNpc = new PrincessObj(NULL, *worldMng, *weaponMng);
		ObjMng::AddObject(*newNpc);
	}
}

void NpcMng::ClearAll()
{
	ObjMng::ClearAll();
}

void NpcMng::UpdateAll(float timeScale)
{
	ObjMng::UpdateAll(timeScale);
}

const void NpcMng::RenderAll()
{
	ObjMng::RenderAll();
}
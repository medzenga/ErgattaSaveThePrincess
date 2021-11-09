#include "NpcMng.h"

NpcMng::NpcMng(WeaponMng* weaponMngIn)
{
	weaponMng = weaponMngIn;
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
		GameObj* newNpc = new PrincessObj(NULL, weaponMng);
		ObjMng::AddObject(newNpc);
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
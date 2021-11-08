#ifndef NPC_MANAGER
#define NPC_MANAGER

#include "ObjMng.h"
#include "PrincessObj.h"

class NpcMng : public ObjMng
{
public:
	NpcMng();
	~NpcMng();

	void LoadNpcDefs();

	void AddNpc(int npcTypeEnum, pos3 startingPos);
	void ClearAll();

	void UpdateAll(float timeScale);
	const void RenderAll();

private:

};

#endif
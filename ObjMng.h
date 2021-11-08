#ifndef OBJECT_MANAGER
#define OBJECT_MANAGER

#include "GameObj.h"

class ObjMng
{
public:
	ObjMng();
	~ObjMng();

	void ClearAll();

	void UpdateAll(float timeScale);
	const void RenderAll();

protected:
	void AddObject(GameObj* newObj);
	GameObj* objList;

private:
};

#endif
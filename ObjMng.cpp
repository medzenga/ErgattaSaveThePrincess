#include "ObjMng.h"

ObjMng::ObjMng()
{
	objList = NULL;
}

ObjMng::~ObjMng()
{
	ClearAll();
}

void ObjMng::AddObject(GameObj& newObj)
{
	newObj.next = objList;
	objList = &newObj;
}

void ObjMng::ClearAll()
{
	while (objList != NULL)
	{
		GameObj* currentObj = objList;
		objList = objList->next;
		delete currentObj;
	}
}

void ObjMng::UpdateAll(float timeScale)
{
	for (GameObj* objIterator = objList; objIterator != NULL; objIterator = objIterator->next)
		objIterator->Update(timeScale);
}

const void ObjMng::RenderAll()
{
	for (GameObj* objIterator = objList; objIterator != NULL; objIterator = objIterator->next)
		objIterator->Render();
}

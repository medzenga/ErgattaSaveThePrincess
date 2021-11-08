#ifndef GAME_OBJ
#define GAME_OBJ

#include "Windows.h"

struct pos3
{
	float x;
	float y;
	float z;
};

class GameObj
{
public:
	GameObj();
	virtual ~GameObj();
	GameObj* UpdateAll(float timeScale, GameObj** ListPtr);
	const void RenderAll();
	void DeleteAll(GameObj** ListPtr);

	pos3 GetPos();
	bool isActive();

	GameObj* next;

protected:
	virtual void Update(float timeScale);
	virtual const void Render();

	bool active;
	pos3 pos;

private:
};

#endif

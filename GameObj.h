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

	virtual void Update(float timeScale);
	virtual const void Render();

	pos3 GetPos();
	void SetPos(const pos3& targetPos);
	bool isActive();

	GameObj* next;

protected:
	bool active;
	pos3 pos;

private:
};

#endif

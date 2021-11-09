#include "GameObj.h"

GameObj::GameObj()
{
	active = true;
	next = NULL;
}

GameObj::~GameObj()
{

}

pos3 GameObj::GetPos()
{
	return pos;
}

void GameObj::SetPos(const pos3& targetPos)
{
	pos = targetPos;
}

bool GameObj::isActive()
{
	return active;
}

void GameObj::Update(float timeScale)
{

}

const void GameObj::Render()
{

}

#include "GameObj.h"

GameObj::GameObj()
{
	active = true;
}

GameObj::~GameObj()
{

}

pos3 GameObj::GetPos()
{
	return pos;
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

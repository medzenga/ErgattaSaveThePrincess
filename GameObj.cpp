#include "GameObj.h"

GameObj::GameObj()
{

}

GameObj::~GameObj()
{

}

GameObj* GameObj::UpdateAll(float timeScale, GameObj** ListPtr)
{
	return NULL;
}

const void GameObj::RenderAll()
{

}

void GameObj::DeleteAll(GameObj** ListPtr)
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

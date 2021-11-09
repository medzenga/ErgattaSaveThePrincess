#include "STGameLoop.h"

#include "FrameTimer.h"
#include "WeaponMng.h"
#include "WorldMng.h"
#include "PlayerMng.h"
#include "EnemyMng.h"
#include "NpcMng.h"
#include "InputHandler.h"
#include "LevelLoader.h"

STGameLoop::STGameLoop()
{
	weaponManager = new WeaponMng();
	worldManager = new WorldMng();
	playerManager = new PlayerMng(*worldManager, *weaponManager);
	npcManager = new NpcMng(*worldManager, *weaponManager);
	enemyManager = new EnemyMng(*worldManager, *weaponManager);
	inputHandler = new InputHandler();
	levelLoader = new LevelLoader(*worldManager, *playerManager, *enemyManager, *npcManager);
}

STGameLoop::~STGameLoop()
{
	delete weaponManager;
	delete worldManager;
	delete playerManager;
	delete npcManager;
	delete enemyManager;
	delete inputHandler;
	delete levelLoader;
}

bool STGameLoop::UpdateGame(float timeScale, const Inputs& inputs, int& gameStateRef)
{
	bool continueGame = true;

	if (gameStateRef == 0)
	{
		gameStateRef = 1;
		levelLoader->LoadLevel(1);
	}

	if (gameStateRef == 1)
	{
		worldManager->Update(timeScale);
		playerManager->UpdateAll(timeScale, inputs);
		npcManager->UpdateAll(timeScale);
		enemyManager->UpdateAll(timeScale);
	}

	return continueGame;
}

void STGameLoop::RenderFrame(int gameState)
{
	if (gameState == 1)
	{
		worldManager->Render();
		playerManager->RenderAll();
		npcManager->RenderAll();
		enemyManager->RenderAll();
	}
}

void STGameLoop::FlipFrame()
{

}

void STGameLoop::RunSTLoop()
{
	FrameTimer* frameTimer = new FrameTimer();

	bool continueGame = true;
	float timeScale = 1.0f;
	int gameState = 0;
	while (continueGame)		// main game loop
	{
		Inputs newInputs = inputHandler->PollInputs();
		continueGame = UpdateGame(timeScale, newInputs, gameState);
		RenderFrame(gameState);
		FlipFrame();
		timeScale = frameTimer->GetNewTimeScale();
	}

	delete frameTimer;
}
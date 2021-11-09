#include "MTGameLoop.h"

#include "FrameTimer.h"
#include "InputHandler.h"
#include "PlayerMng.h"
#include "EnemyMng.h"
#include "NpcMng.h"
#include "LevelLoader.h"

WeaponMng* MTGameLoop::weaponManager = NULL;
PlayerMng* MTGameLoop::playerManager = NULL;
NpcMng* MTGameLoop::npcManager = NULL;
EnemyMng* MTGameLoop::enemyManager = NULL;
InputHandler* MTGameLoop::inputHandler = NULL;
LevelLoader* MTGameLoop::levelLoader = NULL;

float MTGameLoop::threadUpdateTimeScale = 0;
int MTGameLoop::gameState = 0;
bool MTGameLoop::continueGameUpdateThread = false;

HANDLE MTGameLoop::gameUpdateThreadHandle = NULL;
HANDLE MTGameLoop::threadUpdateTimeScaleMutex = NULL;
HANDLE MTGameLoop::gameUpdateLoopEvent = NULL;

MTGameLoop::MTGameLoop()
{
	weaponManager = new WeaponMng();
	playerManager = new PlayerMng(*weaponManager);
	npcManager = new NpcMng(*weaponManager);
	enemyManager = new EnemyMng(*weaponManager);
	inputHandler = new InputHandler();
	levelLoader = new LevelLoader(*playerManager, *enemyManager, *npcManager);

	threadUpdateTimeScale = 1.0f;
	continueGame = true;
	gameState = 1;
	continueGameUpdateThread = true;
}

MTGameLoop::~MTGameLoop()
{
	delete weaponManager;
	delete playerManager;
	delete npcManager;
	delete enemyManager;
	delete inputHandler;
	delete levelLoader;
}


unsigned int __stdcall MTGameLoop::GameUpdateThread(void* param)
{
	gameUpdateLoopEvent = CreateEvent(NULL, true, false, NULL);
	threadUpdateTimeScaleMutex = CreateMutex(NULL, false, NULL);

	while (continueGameUpdateThread)
	{
		const float maxUpdateRate = 3.0f;
		float localTimeScale = 0;

		WaitForSingleObject(threadUpdateTimeScaleMutex, INFINITE);
		if (threadUpdateTimeScale > maxUpdateRate)
		{
			localTimeScale = maxUpdateRate;
			threadUpdateTimeScale -= maxUpdateRate;
			if (threadUpdateTimeScale > maxUpdateRate)
				threadUpdateTimeScale = maxUpdateRate;
		}
		else
		{
			localTimeScale = threadUpdateTimeScale;
			threadUpdateTimeScale = 0;
		}
		ReleaseMutex(threadUpdateTimeScaleMutex);

		UpdateGame(localTimeScale, gameState);

		WaitForSingleObject(gameUpdateLoopEvent, INFINITE);
		ResetEvent(gameUpdateLoopEvent);
	}

	return 0;
}

bool MTGameLoop::UpdateGame(float timeScale, int& gameStateRef)
{
	bool continueGame = true;

	if (gameStateRef == 0)
	{
		gameStateRef = 1;
		levelLoader->LoadLevel(1);
	}

	if (gameStateRef == 1)
	{
		Inputs newInputs = inputHandler->PollInputs();
		playerManager->UpdateAll(timeScale, newInputs);
		npcManager->UpdateAll(timeScale);
		enemyManager->UpdateAll(timeScale);
	}

	return continueGame;
}

void MTGameLoop::RenderFrame(int gameState)
{
	if (gameState == 1)
	{
		playerManager->RenderAll();
		npcManager->RenderAll();
		enemyManager->RenderAll();
	}
}

void MTGameLoop::UnblockGameUpdateThread(float timeScaleIn)
{
	WaitForSingleObject(threadUpdateTimeScaleMutex, INFINITE);
	threadUpdateTimeScale += timeScaleIn;
	ReleaseMutex(threadUpdateTimeScaleMutex);

	SetEvent(gameUpdateLoopEvent);
}

void MTGameLoop::StopGameUpdateThread()
{
	continueGameUpdateThread = false;
	SetEvent(gameUpdateLoopEvent);
	DWORD ThreadResult = WaitForSingleObject(gameUpdateThreadHandle, 2000);

	if (ThreadResult == WAIT_TIMEOUT)
		TerminateThread(gameUpdateThreadHandle, 0);

	CloseHandle(gameUpdateThreadHandle);
}

void MTGameLoop::FlipFrame()
{

}

void MTGameLoop::RunMTLoop()
{
	FrameTimer* frameTimer = new FrameTimer();

	gameUpdateThreadHandle = (HANDLE)_beginthreadex(NULL, 0, GameUpdateThread, NULL, 0, NULL);

	float timeScale = 1.0f;
	while (continueGame)		// main game loop
	{
		RenderFrame(gameState);
		UnblockGameUpdateThread(timeScale);
		FlipFrame();
		timeScale = frameTimer->GetNewTimeScale();
	}

	StopGameUpdateThread();

	delete frameTimer;
}
#ifndef MULTITHREADED_GAME_LOOP
#define MULTITHREADED_GAME_LOOP

#include <Windows.h>
#include <process.h>

class WeaponMng;
class PlayerMng;
class NpcMng;
class EnemyMng;
class InputHandler;
class LevelLoader;

class MTGameLoop
{
public:
	MTGameLoop();
	~MTGameLoop();

	void RunMTLoop();

private:
	static unsigned int __stdcall GameUpdateThread(void* param);
	static bool UpdateGame(float timeScale, int& gameStateRef);
	void RenderFrame(int gameState);
	void UnblockGameUpdateThread(float timeScaleIn);
	void StopGameUpdateThread();
	void FlipFrame();

	static WeaponMng* weaponManager;
	static PlayerMng* playerManager;
	static NpcMng* npcManager;
	static EnemyMng* enemyManager;
	static InputHandler* inputHandler;
	static LevelLoader* levelLoader;

	static HANDLE gameUpdateThreadHandle;
	static HANDLE threadUpdateTimeScaleMutex;
	static HANDLE gameUpdateLoopEvent;

	static float threadUpdateTimeScale;
	bool continueGame;
	static int gameState;
	static bool continueGameUpdateThread;
};

#endif
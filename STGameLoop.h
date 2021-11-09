#ifndef SINGLE_THREAD_GAME_LOOP
#define SINGLE_THREAD_GAME_LOOP

class WeaponMng;
class WorldMng;
class InputHandler;
class NpcMng;
class EnemyMng;
class PlayerMng;
class LevelLoader;
struct Inputs;

class STGameLoop
{
public:
	STGameLoop();
	~STGameLoop();

	void RunSTLoop();

private:
	bool UpdateGame(float timeScale, const Inputs& inputs, int& gameStateRef);
	void RenderFrame(int gameState);
	void FlipFrame();

	WeaponMng* weaponManager;
	WorldMng* worldManager;
	PlayerMng* playerManager;
	NpcMng* npcManager;
	EnemyMng* enemyManager;
	InputHandler* inputHandler;
	LevelLoader* levelLoader;
};

#endif
// "Save the Princess" Exersize Project
// written by Matt Edzenga

#include <iostream>

#include "ConfigFile.h"
#include "AssetLoader.h"

#include "STGameLoop.h"
#include "MTGameLoop.h"

int main()
{
	const bool useMultithreading = false;

	std::cout << "Starting Save the Princess game...\n";

	ConfigFile* configFile = new ConfigFile();
	ConfigSettings gameSettings = configFile->LoadConfig();

	AssetLoader* assetLoaderInst = new AssetLoader();
	AssetStorage gameAssets = assetLoaderInst->LoadAssets();

	std::cout << "Done initializing, starting main game loop...\n";

	if (useMultithreading)
	{
		std::cout << "Using multithreaded game loop\n";

		MTGameLoop* mtGameLoop = new MTGameLoop();
		mtGameLoop->RunMTLoop();
		delete mtGameLoop;
	}
	else
	{
		std::cout << "Using single threaded game loop\n";

		STGameLoop* stGameLoop = new STGameLoop();
		stGameLoop->RunSTLoop();
		delete stGameLoop;
	}

	std::cout << "Main game loop is done executing, shutting down game...\n";

	configFile->SaveConfig(gameSettings);
	delete configFile;
	delete assetLoaderInst;

	std::cout << "Shutdown process complete, closing application...\n";
}

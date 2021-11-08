#include "AssetLoader.h"

AssetLoader::AssetLoader()
{

}

AssetLoader::~AssetLoader()
{

}

AssetStorage AssetLoader::LoadAssets()
{
	return internalStorage;
}

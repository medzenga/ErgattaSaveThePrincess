#ifndef ASSET_LOADER
#define ASSET_LOADER

struct AssetStorage
{
	unsigned int asset1;
	unsigned int asset2;
	unsigned int asset3;
	unsigned int asset4;
};

class AssetLoader
{
public:
	AssetLoader();
	~AssetLoader();

	AssetStorage LoadAssets();

private:
	AssetStorage internalStorage;
};

#endif
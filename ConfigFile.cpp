#include "ConfigFile.h"

ConfigFile::ConfigFile()
{

}

ConfigFile::~ConfigFile()
{

}

ConfigSettings ConfigFile::LoadConfig()
{
	return currentSettings;
}

void ConfigFile::SaveConfig(const ConfigSettings& settingsToSave)
{

}

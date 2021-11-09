#ifndef CONFIG_FILE
#define CONFIG_FILE

struct ConfigSettings
{
	int setting1;
	int setting2;
	float setting3;
	bool setting4;
};

class ConfigFile
{
public:
	ConfigFile();
	~ConfigFile();

	ConfigSettings LoadConfig();
	void SaveConfig(const ConfigSettings& settingsToSave);

private:
	ConfigSettings currentSettings;
};

#endif
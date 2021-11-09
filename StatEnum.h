#ifndef STAT_ENUM
#define STAT_ENUM

class StatEnum
{
public:
	StatEnum();
	~StatEnum();

	void SetEnum(int enumIn);
	void AddEnum(int enumIn);
	void RemoveEnum(int enumIn);
	bool GetHasEnum(int enumIn);
	int GetRawEnum();

private:
	int enumVal;
};

#endif
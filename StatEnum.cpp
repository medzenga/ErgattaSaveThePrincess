#include "StatEnum.h"

StatEnum::StatEnum()
{
	enumVal = 0;
}

StatEnum::~StatEnum()
{

}

void StatEnum::SetEnum(int enumIn)
{
	enumVal = enumIn;
}

void StatEnum::AddEnum(int enumIn)
{
	enumVal = enumVal | enumIn;
}

void StatEnum::RemoveEnum(int enumIn)
{
	enumVal = enumVal ^ enumIn;
}

bool StatEnum::GetHasEnum(int enumIn)
{
	return (enumVal & enumIn) == enumIn;
}

int StatEnum::GetRawEnum()
{
	return enumVal;
}
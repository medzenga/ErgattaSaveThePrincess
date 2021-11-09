#include "WeaponObj.h"

WeaponObj::WeaponObj(const WeaponStats& statsIn, unsigned int modelIn)
{
	stats = statsIn;
	model = modelIn;
}

WeaponObj::~WeaponObj()
{

}

WeaponStats& WeaponObj::GetStats()
{
	return stats;
}

const void WeaponObj::operator=(const WeaponObj& rhs)		// deep copy overload for '='
{
	stats = rhs.stats;
}
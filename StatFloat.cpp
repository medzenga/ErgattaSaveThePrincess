#include "StatFloat.h"

StatFloat::StatFloat()
{
	maxValue = 0;
	minValue = 0;
	value = 0;
}

StatFloat::~StatFloat()
{

}

void StatFloat::SetStartingValue(float startVal)		// sets the max and current values
{

}

void StatFloat::SetMaxValue(float newVal)
{

}

float StatFloat::GetMaxValue()
{
	return maxValue;
}

void StatFloat::SetMinValue(float newVal)
{

}

float StatFloat::GetMinValue()
{
	return minValue;
}

void StatFloat::SetValue(float newVal)			// ensures the final value stays within the max/min
{

}

void StatFloat::OffsetValue(float deltaVal)		// ensures the final value stays within the max/min
{

}

float StatFloat::GetValue()
{
	return value;
}

void StatFloat::SetValueToMax()
{

}

void StatFloat::SetValueToMin()
{

}
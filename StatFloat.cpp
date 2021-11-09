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
	if (startVal > maxValue)
		maxValue = startVal;
	if (startVal < minValue)
		minValue = startVal;

	value = startVal;
}

void StatFloat::SetMaxValue(float newVal)
{
	maxValue = newVal;
	if (value > maxValue)
		value = maxValue;
}

float StatFloat::GetMaxValue()
{
	return maxValue;
}

void StatFloat::SetMinValue(float newVal)
{
	minValue = newVal;
	if (minValue > value)
		value = minValue;
}

float StatFloat::GetMinValue()
{
	return minValue;
}

void StatFloat::SetValue(float newVal)			// ensures the final value stays within the max/min
{
	if (newVal > maxValue)
		value = maxValue;
	else if (newVal < minValue)
		value = minValue;
	else
		value = newVal;
}

void StatFloat::OffsetValue(float deltaVal)		// ensures the final value stays within the max/min
{
	float newValue = value + deltaVal;
	SetValue(newValue);
}

float StatFloat::GetValue()
{
	return value;
}

void StatFloat::SetValueToMax()
{
	value = maxValue;
}

void StatFloat::SetValueToMin()
{
	value = minValue;
}
#include "StatInt.h"

StatInt::StatInt()
{
	maxValue = 0;
	minValue = 0;
	value = 0;
}

StatInt::~StatInt()
{

}

void StatInt::SetStartingValue(int startVal)		// sets the max and current values
{
	if (startVal > maxValue)
		maxValue = startVal;
	if (startVal < minValue)
		minValue = startVal;

	value = startVal;
}

void StatInt::SetMaxValue(int newVal)
{
	maxValue = newVal;
	if (value > maxValue)
		value = maxValue;
}

int StatInt::GetMaxValue()
{
	return maxValue;
}

void StatInt::SetMinValue(int newVal)
{
	minValue = newVal;
	if (minValue > value)
		value = minValue;
}

int StatInt::GetMinValue()
{
	return minValue;
}

void StatInt::SetValue(int newVal)			// ensures the final value stays within the max/min
{
	if (newVal > maxValue)
		value = maxValue;
	else if (newVal < minValue)
		value = minValue;
	else
		value = newVal;
}

void StatInt::OffsetValue(int deltaVal)		// ensures the final value stays within the max/min
{
	int newValue = value + deltaVal;
	SetValue(newValue);
}

int StatInt::GetValue()
{
	return value;
}

void StatInt::SetValueToMax()
{
	value = maxValue;
}

void StatInt::SetValueToMin()
{
	value = minValue;
}
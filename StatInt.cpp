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

}

void StatInt::SetMaxValue(int newVal)
{

}

int StatInt::GetMaxValue()
{
	return maxValue;
}

void StatInt::SetMinValue(int newVal)
{
	minValue = newVal;
}

int StatInt::GetMinValue()
{
	return minValue;
}

void StatInt::SetValue(int newVal)			// ensures the final value stays within the max/min
{

}

void StatInt::OffsetValue(int deltaVal)		// ensures the final value stays within the max/min
{

}

int StatInt::GetValue()
{
	return value;
}

void StatInt::SetValueToMax()
{

}

void StatInt::SetValueToMin()
{

}
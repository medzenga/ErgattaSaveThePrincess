#ifndef STAT_FLOAT
#define STAT_FLOAT

class StatFloat
{
public:
	StatFloat();
	~StatFloat();

	void SetStartingValue(float startVal);		// sets the max and current values

	void SetMaxValue(float newVal);
	float GetMaxValue();

	void SetMinValue(float newVal);
	float GetMinValue();

	void SetValue(float newVal);			// ensures the final value stays within the max/min
	void OffsetValue(float deltaVal);		// ensures the final value stays within the max/min
	float GetValue();
	void SetValueToMax();
	void SetValueToMin();

private:
	float maxValue;
	float minValue;
	float value;
};

#endif
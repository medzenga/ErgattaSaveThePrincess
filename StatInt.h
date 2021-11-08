#ifndef STAT_INT
#define STAT_INT

class StatInt
{
public:
	StatInt();
	~StatInt();

	void SetStartingValue(int startVal);

	void SetMaxValue(int newVal);
	int GetMaxValue();

	void SetMinValue(int newVal);
	int GetMinValue();

	void SetValue(int newVal);
	void OffsetValue(int deltaVal);
	int GetValue();
	void SetValueToMax();
	void SetValueToMin();

private:
	int maxValue;
	int minValue;
	int value;
};

#endif
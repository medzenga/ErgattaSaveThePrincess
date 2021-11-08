#ifndef FRAME_TIMER
#define FRAME_TIMER

class FrameTimer
{
public:
	FrameTimer();
	~FrameTimer();

	float GetNewTimeScale();

private:
	long long prevTime;
};

#endif
#ifndef INPUT_HANDLER
#define INPUT_HANDLER

struct Inputs
{
	bool up;
	bool down;
	bool left;
	bool right;
	bool jump;
	bool attack;
};

class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	Inputs PollInputs();

private:
	Inputs currentInputs;
};

#endif
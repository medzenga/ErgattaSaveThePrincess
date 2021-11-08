#include "InputHandler.h"

InputHandler::InputHandler()
{

}

InputHandler::~InputHandler()
{

}

Inputs InputHandler::PollInputs()
{
	return currentInputs;
}

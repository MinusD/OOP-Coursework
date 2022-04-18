#include <string>
#include "Interpreter.h"
#include "ConcreteStates.h"

Interpreter::Interpreter()
{
    current = &H::getInstance();
}

void Interpreter::setState(State& newState)
{
    current = &newState;
}

void Interpreter::next(std::string::const_iterator& it)
{
    current->proceed(it, this);
}

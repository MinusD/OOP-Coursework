#ifndef __INTERPRETER__
#define __INTERPRETER__
#include <string>
#include "State.h"

class State;

class Interpreter
{
public:
    Interpreter();
    inline State& getState() { return *current; }
    void setState(State& newState);
    void next(std::string::const_iterator&);
private:
    State* current;
};
#endif // __INTERPRETER__

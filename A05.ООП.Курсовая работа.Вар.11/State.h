#ifndef __STATE__
#define __STATE__
#include <string>
#include "Interpreter.h"

class Interpreter;

class State
{
public:
    virtual void proceed(std::string::const_iterator&, Interpreter*) = 0;
    virtual bool isFinal() { return false; }
};
#endif // __STATE__

#ifndef __D__
#define __D__
#include "State.h"

class D : public State
{
public:
    virtual void proceed(char, Interpreter*);

};
#endif // __D__


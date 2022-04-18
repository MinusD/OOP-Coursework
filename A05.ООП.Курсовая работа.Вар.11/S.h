#ifndef __S__
#define __S__
#include "State.h"
class S : public State {
public:
    virtual State* proceed(char);
    virtual bool isFinal() { return true; }
};
#endif // __S__



#ifndef __CONCRETE_STATES__
#define __CONCRETE_STATES__
#include <string>
#include "State.h"
#include "Interpreter.h"

class H : public State
{
public:
    void proceed(std::string::const_iterator&, Interpreter*);
    static State& getInstance();
private:
    H() {}
    H(const H&);
    H& operator=(const H&);
};

class D : public State
{
public:
    void proceed(std::string::const_iterator&, Interpreter*);
    static State& getInstance();
private:
    D() {}
    D(const D&);
    D& operator=(const D&);
};

class S : public State
{
public:
    void proceed(std::string::const_iterator&, Interpreter*);
    bool isFinal() { return true; }
    static State& getInstance();
private:
    S() {}
    S(const S&);
    S& operator=(const S&);
};
#endif // __CONCRETE_STATES__



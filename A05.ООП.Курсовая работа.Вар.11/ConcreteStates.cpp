#include <iostream>
#include <string>
#include "ConcreteStates.h"
#include <exception>
#include <stdexcept>
#include "StateException.h"

void H::proceed(std::string::const_iterator& it, Interpreter* interp)
{
    std::string pattern = "http://";
    for (int i = 0; i < 7; i++) {
        if (*it == pattern[i]) {
            //std::cout << *it;
            if (i != 6) it++;
            continue;
        }
        else {
            throw StateException(std::string("Invalid symbol: ") + *it);
        }
    }
    interp->setState(D::getInstance());
    /*while (true) {
        if (*it == pattern[pos]) {
            pos++
            it++;
            std::cout << *it;
            continue;
        }
    }
    if (*it != 'h') {
        throw StateException(std::string("Invalid symbol: ") + *it);
    }
    */
    
}

void D::proceed(std::string::const_iterator& it, Interpreter* interp)
{
    bool flag = false;
    while (true) {
        if (*it >= 'a' && *it <= 'z') {
            it++;
            flag = true;
            continue;
        } else if (*it != '/') {
            throw StateException(std::string("Invalid symbol: ") + *it);
        }
        else if (flag) {
            return interp->setState(S::getInstance());
        } else {
            throw StateException(std::string("Invalid format"));
        }
    }
}

void S::proceed(std::string::const_iterator& it, Interpreter* interp)
{
    if (*it != '/') {
        throw StateException(std::string("Invalid symbol: ") + *it);
    }
}

State& H::getInstance()
{
    static H self;
    return self;
}

State& D::getInstance()
{
    static D self;
    return self;
}

State& S::getInstance()
{
    static S self;
    return self;
}

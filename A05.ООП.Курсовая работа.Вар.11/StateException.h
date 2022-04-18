#ifndef __STATE_EXCEPTION__
#define __STATE_EXCEPTION__
#include <string>
#include <exception>

class StateException : public std::exception
{
    const std::string msg;
public:
    StateException(const std::string& _msg) : msg(_msg) {}
    virtual ~StateException() {}
    virtual const char* what() const throw() { return msg.c_str(); }
};
#endif // __STATE_EXCEPTION__


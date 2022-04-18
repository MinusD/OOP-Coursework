#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include "Interpreter.h"
#include "State.h"

using namespace std;

enum state { _H, _D, _S };
state recognize(const char*);

int main() {
    const char* input = "http://asv/";
    try {
        state cur = recognize(input);
        if (cur != _S) {
            throw "No match";
        }
        cout << "OK" << endl;
    }
    catch (char c) {
        cout << "ERROR: " << c << endl;
        return 1;
    }
    catch (const char* s) {
        cout << s << endl;
    }
    return 0;
}

/*
int main()
{
    string input = "https://";
    Interpreter interpreter;
    try {
        input += "/";
        for (string::const_iterator it = input.begin(); it != input.end(); it++) {
            interpreter.next(it);
        }
        if (interpreter.getState().isFinal()) {
            cout << "OK" << endl;
        }
        else {
            throw runtime_error("Interpreter not in final state");
        }
    } catch (exception& e) {
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
*/
state recognize(const char* s)
{
    state cur = _H;
    char c;
    int i = 0;
    bool flag = false;
    std::string pattern = "http://";
    while (s[i]) {
        c = s[i];
        switch (cur) {
        case _H:
            //std::cout << c << " " << pattern[i] << std::endl;
            if (i == 6) {
                cur = _D;
            }
            else if (c != pattern[i]) {
                throw c;
            }
            else {
                cur = _H;
            }
            break;
        case _D:
            //std::cout << c << " " << strlen(s)-1 << " " << c << " " << s[i] << " " << i << std::endl;
            if (i == strlen(s) - 1 && flag && (c == '/' or c >= 'a' && c <= 'z')) {
                cur = _S;
            }
            else if (c >= 'a' && c <= 'z') {
                flag = true;
                cur = _D;
            }
            else if (c == '/') {
                cur = _S;
            }
            else {
                throw c;
            }
            break;
        case _S:
            throw c;
        }
        i++;
    }
    return cur;
}

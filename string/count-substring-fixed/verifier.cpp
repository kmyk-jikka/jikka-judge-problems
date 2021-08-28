#include <iostream>
#include "testlib.h"
#include "params.h"

int main() {
    registerValidation();

    std::string s = inf.readToken();
    ensure(LEN_S_MIN <= s.length() and s.length() <= LEN_S_MAX);
    for (char c : s) {
        ensure(islower(c));
    }
    inf.readChar('\n');
    inf.readEof();
    return 0;
}

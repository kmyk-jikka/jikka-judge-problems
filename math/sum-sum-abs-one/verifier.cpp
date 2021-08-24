#include <iostream>
#include "testlib.h"

int main() {
    registerValidation();

    int n = inf.readInt(0, 1e5);
    inf.readChar('\n');
    for (int i = 0; i < n; ++i) {
        inf.readInt(-1e8, 1e8);
        inf.readChar(i + 1 < n ? ' ' : '\n');
    }
    if (n == 0) {
        inf.readChar('\n');
    }
    inf.readEof();
    return 0;
}

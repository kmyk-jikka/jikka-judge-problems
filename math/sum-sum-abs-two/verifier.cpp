#include <iostream>
#include "testlib.h"

int main() {
    registerValidation();

    int n = inf.readInt(0, 1e5);
    inf.readSpace();
    int m = inf.readInt(0, 1e5);
    inf.readChar('\n');
    for (int i = 0; i < n; ++i) {
        inf.readInt(-1e8, 1e8);
        inf.readChar(i + 1 < n ? ' ' : '\n');
    }
    if (n == 0) {
        inf.readChar('\n');
    }
    for (int j = 0; j < m; ++j) {
        inf.readInt(-1e8, 1e8);
        inf.readChar(j + 1 < m ? ' ' : '\n');
    }
    if (m == 0) {
        inf.readChar('\n');
    }
    inf.readEof();
    return 0;
}

#include <iostream>
#include "testlib.h"
#include "params.h"

int main() {
    registerValidation();

    int n = inf.readLong(N_MIN, N_MAX);
    inf.readChar('\n');
    for (int i = 0; i < n; ++i) {
        inf.readLong(X_MIN, X_MAX);
        inf.readChar(i + 1 < n ? ' ' : '\n');
    }
    if (n == 0) {
        inf.readChar('\n');
    }
    inf.readEof();
    return 0;
}

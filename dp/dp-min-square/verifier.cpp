#include <iostream>
#include "testlib.h"
#include "params.h"

int main() {
    registerValidation();

    int n = inf.readLong(N_MIN, N_MAX);
    inf.readChar('\n');
    for (int i = 0; i < n; ++i) {
        inf.readLong(A_MIN, A_MAX);
        inf.readChar(i + 1 < n ? ' ' : '\n');
    }
    inf.readEof();
    return 0;
}

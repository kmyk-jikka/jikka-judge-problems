#include <iostream>
#include "testlib.h"
#include "params.h"

int main() {
    registerValidation();

    int n = inf.readInt(N_MIN, N_MAX);
    inf.readChar('\n');
    for (int i = 0; i < n; ++i) {
        inf.readInt(A_MIN, A_MAX);
        inf.readChar(i + 1 < n ? ' ' : '\n');
    }
    if (n == 0) {
        inf.readChar('\n');
    }
    for (int j = 0; j < n; ++j) {
        inf.readInt(A_MIN, A_MAX);
        inf.readChar(j + 1 < n ? ' ' : '\n');
    }
    if (n == 0) {
        inf.readChar('\n');
    }
    inf.readEof();
    return 0;
}

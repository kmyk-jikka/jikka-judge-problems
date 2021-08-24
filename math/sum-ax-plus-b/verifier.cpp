#include <iostream>
#include "testlib.h"
#include "params.h"

int main() {
    registerValidation();

    inf.readLong(A_MIN, A_MAX);
    inf.readSpace();
    inf.readLong(A_MIN, A_MAX);
    inf.readSpace();
    inf.readLong(N_MIN, N_MAX);
    inf.readChar('\n');
    inf.readEof();
    return 0;
}

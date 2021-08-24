#include <iostream>
#include "testlib.h"
#include "params.h"

int main() {
    registerValidation();

    inf.readLong(N_MIN, N_MAX);
    inf.readChar('\n');
    inf.readEof();
    return 0;
}

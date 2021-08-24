#include <iostream>
#include "testlib.h"

int main() {
    registerValidation();

    inf.readLong(0, 1000000000000000000ll);
    inf.readChar('\n');
    inf.readEof();
    return 0;
}

#include <iostream>
#include "testlib.h"

int main() {
    registerValidation();

    inf.readInt(0, 10000000);
    inf.readChar('\n');
    inf.readEof();
    return 0;
}

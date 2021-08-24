#include <iostream>
#include "testlib.h"

int main() {
    registerValidation();

    constexpr long long K = 1000000000;
    inf.readInt(-K, K);
    inf.readSpace();
    inf.readInt(-K, K);
    inf.readSpace();
    inf.readLong(0, 1000000000000000000ll);
    inf.readChar('\n');
    inf.readEof();
    return 0;
}

#include <cstdio>
#include "random.h"

using namespace std;

int main(int, char* argv[]) {
    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    long long n = gen.uniform(0ll, 1000000000000000000ll);
    printf("%lld\n", n);
    return 0;
}

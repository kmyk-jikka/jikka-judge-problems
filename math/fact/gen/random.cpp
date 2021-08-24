#include <cstdio>
#include "random.h"
#include "../params.h"

using namespace std;

int main(int, char* argv[]) {
    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    long long n = gen.uniform(N_MIN, N_MAX);
    printf("%lld\n", n);
    return 0;
}

#include <cstdio>
#include "random.h"
#include "../params.h"

using namespace std;

int main(int, char* argv[]) {
    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    long long a = gen.uniform(A_MIN, A_MAX);
    long long b = gen.uniform(A_MIN, A_MAX);
    long long n = gen.uniform(N_MIN, N_MAX);
    printf("%lld %lld %lld\n", a, b, n);
    return 0;
}

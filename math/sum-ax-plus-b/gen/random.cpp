#include <cstdio>
#include "random.h"

using namespace std;

int main(int, char* argv[]) {
    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    constexpr long long K = 1000000000;
    long long a = gen.uniform(-K, K);
    long long b = gen.uniform(-K, K);
    long long n = gen.uniform(0ll, 1000000000000000000ll);
    printf("%lld %lld %lld\n", a, b, n);
    return 0;
}

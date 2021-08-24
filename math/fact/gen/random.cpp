#include <cstdio>
#include "random.h"

using namespace std;

int main(int, char* argv[]) {
    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    int n = gen.uniform(0, 10000000);
    printf("%d\n", n);
    return 0;
}

#include <iostream>
#include "random.h"
#include "../params.h"
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
using namespace std;

int main(int, char* argv[]) {
    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    int n = gen.uniform(N_MIN, N_MAX);
    printf("%d\n", n);
    REP (i, n) {
        int a = gen.uniform(A_MIN, A_MAX);
        printf("%d%c", a, i + 1 < n ? ' ' : '\n');
    }
    return 0;
}

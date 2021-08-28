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

    string s;
    int n = gen.uniform<int>(LEN_S_MIN, LEN_S_MAX);
    int state = 0;
    REP (i, n) {
        if (gen.uniform01() < 0.1) {
            state = gen.uniform(0, 5 - 1);
        }
        if (gen.uniform01() < 0.2) {
            s += gen.uniform('a', 'z');
        } else if (state == 0) {
            s += 'f';
            state += 1;
        } else if (state == 1) {
            s += 'i';
            state += 1;
        } else if (state == 2) {
            s += 'x';
            state += 1;
        } else if (state == 3) {
            s += 'e';
            state += 1;
        } else if (state == 4) {
            s += 'd';
            state = 0;
        }
    }
    printf("%s\n", s.c_str());
    return 0;
}

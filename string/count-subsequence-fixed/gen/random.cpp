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

    string table;
    table += "abcdefg";
    table += "fixed";
    table += "fixed";
    table += "fixed";

    string s;
    int n = gen.uniform<int>(LEN_S_MIN, LEN_S_MAX);
    REP (i, n) {
        s += table[gen.uniform<int>(0, table.size() - 1)];
    }
    printf("%s\n", s.c_str());
    return 0;
}

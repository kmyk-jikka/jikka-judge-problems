#include <algorithm>
#include <array>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
using namespace std;

// /re+g(exp?|ular*e?xp(res*ion)?)/
enum STATE {
    EPSILON,
    R,
    RE,
    REG,
    REGE,
    REGEX,
    REGU,
    REGUL,
    REGULA,
    REGULAE,
    REGULAEX,
    REGULAEXP,
    REGULAEXPR,
    REGULAEXPRE,
    REGULAEXPREI,
    REGULAEXPREIO,
    ACCEPT,
};

// /re+g(exp?|ular*e?xp(res*ion)?)/
int64_t solve(const string &s) {
    array<int64_t, ACCEPT + 1> cur = {};
    cur[EPSILON] += 1;
    for (char c : s) {
        array<int64_t, ACCEPT + 1> prv = {};
        cur.swap(prv);
        cur[EPSILON] += 1;
        if (c == 'r') cur[R] += prv[EPSILON];
        if (c == 'e') cur[RE] += prv[R];
        if (c == 'r') cur[R] += prv[RE];
        if (c == 'g') cur[REG] += prv[RE];
        if (c == 'e') cur[REGE] += prv[REG];
        if (c == 'x') cur[REGEX] += prv[REGE];
        if (c == 'p') cur[ACCEPT] += prv[REGEX];
        if (c == 'u') cur[REGU] += prv[REG];
        if (c == 'l') cur[REGUL] += prv[REGU];
        if (c == 'a') cur[REGULA] += prv[REGUL];
        if (c == 'r') cur[REGULA] += prv[REGULA];
        if (c == 'e') cur[REGULAE] += prv[REGULA];
        if (c == 'x') cur[REGULAEX] += prv[REGULA];
        if (c == 'x') cur[REGULAEX] += prv[REGULAE];
        if (c == 'p') cur[REGULAEXP] += prv[REGULAEX];
        if (c == 'r') cur[REGULAEXPR] += prv[REGULAEXP];
        if (c == 'e') cur[REGULAEXPRE] += prv[REGULAEXPR];
        if (c == 's') cur[REGULAEXPRE] += prv[REGULAEXPRE];
        if (c == 'i') cur[REGULAEXPREI] += prv[REGULAEXPRE];
        if (c == 'o') cur[REGULAEXPREIO] += prv[REGULAEXPREI];
        if (c == 'n') cur[ACCEPT] += prv[REGULAEXPREIO];
        cur[ACCEPT] += cur[REGEX];
        cur[ACCEPT] += cur[REGULAEXP];
        cur[ACCEPT] += prv[ACCEPT];
    }
    return cur[ACCEPT];
}

int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}

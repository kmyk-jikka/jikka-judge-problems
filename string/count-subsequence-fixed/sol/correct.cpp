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

template <int32_t MOD>
struct mint {
    int32_t value;
    mint() = default;
    mint(int32_t value_) : value(value_) {}
    inline mint<MOD> operator + (mint<MOD> other) const { int32_t c = this->value + other.value; return mint<MOD>(c >= MOD ? c - MOD : c); }
    inline mint<MOD> operator * (mint<MOD> other) const { int32_t c = (int64_t)this->value * other.value % MOD; return mint<MOD>(c < 0 ? c + MOD : c); }
    inline mint<MOD> & operator += (mint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
    inline mint<MOD> & operator *= (mint<MOD> other) { this->value = (int64_t)this->value * other.value % MOD; if (this->value < 0) this->value += MOD; return *this; }
};
template <int32_t MOD> std::istream & operator >> (std::istream & in, mint<MOD> & n) { int64_t value; in >> value; n = value; return in; }
template <int32_t MOD> std::ostream & operator << (std::ostream & out, mint<MOD> n) { return out << n.value; }

constexpr int MOD = 998244353;

enum STATE {
    EPSILON,
    F,
    FI,
    FIX,
    FIXE,
    FIXED,
};

mint<MOD> solve(const string &s) {
    array<mint<MOD>, FIXED + 1> cur = {};
    cur[EPSILON] += 1;
    for (char c : s) {
        array<mint<MOD>, FIXED + 1> prv = cur;
        if (c == 'f') cur[F] += prv[EPSILON];
        if (c == 'i') cur[FI] += prv[F];
        if (c == 'x') cur[FIX] += prv[FI];
        if (c == 'e') cur[FIXE] += prv[FIX];
        if (c == 'd') cur[FIXED] += prv[FIXE];
    }
    return cur[FIXED];
}

int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}

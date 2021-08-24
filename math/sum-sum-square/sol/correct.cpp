#include <algorithm>
#include <cstdint>
#include <numeric>
#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
using namespace std;

constexpr int MOD = 998244353;

int64_t solve(int n, vector<int64_t> a) {
    int64_t ans = 0;
    for (int64_t a_i : a) {
        ans += 2 * n * a_i % MOD * a_i % MOD;
    }
    int64_t sum_a = accumulate(ALL(a), 0ll);
    ans -= 2 * sum_a * sum_a % MOD;
    return (ans % MOD + MOD) % MOD;
}

int main() {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    REP (i, n) {
        cin >> a[i];
    }
    cout << solve(n, a) << endl;
    return 0;
}

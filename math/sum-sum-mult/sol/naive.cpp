#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
using namespace std;

constexpr int MOD = 1000000007;

int64_t solve(int n, vector<int64_t> a, vector<int64_t> b) {
    int64_t ans = 0;
    REP (i, n) {
        REP (j, n) {
            ans += abs(a[i] - a[j]) % MOD * (abs(b[i] - b[j]) % MOD) % MOD;
        }
        ans %= MOD;
    }
    return (ans % MOD + MOD) % MOD;
}

int main() {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    REP (i, n) {
        cin >> a[i];
    }
    vector<int64_t> b(n);
    REP (j, n) {
        cin >> b[j];
    }
    cout << solve(n, a, b) << endl;
    return 0;
}

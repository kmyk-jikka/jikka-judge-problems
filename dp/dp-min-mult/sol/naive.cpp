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

constexpr int64_t INF = 1e18;

int64_t solve(int n, const vector<int64_t> &a, const vector<int64_t> &b) {
    vector<int64_t> dp(n, INF);
    dp[0] = 0;
    REP3 (i, 1, n) {
        REP (j, i) {
            dp[i] = min(dp[i], dp[j] + a[j] * b[i]);
        }
    }
    return dp[n - 1];
}

int main() {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    REP (i, n) {
        cin >> a[i];
    }
    vector<int64_t> b(n);
    REP (i, n) {
        cin >> b[i];
    }
    cout << solve(n, a, b) << endl;
    return 0;
}

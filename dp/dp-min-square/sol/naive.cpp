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

int64_t sq(int64_t x) {
    return x * x;
}

int64_t solve(int n, const vector<int64_t> &a) {
    vector<int64_t> dp(n, INF);
    dp[0] = 0;
    REP3 (i, 1, n) {
        REP (j, i) {
            dp[i] = min(dp[i], dp[j] + sq(a[i] - a[j]));
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
    cout << solve(n, a) << endl;
    return 0;
}

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

int64_t solve(int n, vector<int64_t> a) {
    sort(ALL(a));

    vector<int64_t> sum(n + 1);
    partial_sum(ALL(a), sum.begin() + 1);
    int64_t ans = 0;
    REP (i, n) {
        ans += sum[n] - sum[i] - a[i] * (n - i);
    }
    return ans;
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

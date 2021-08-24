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

int64_t solve(vector<int64_t> a, vector<int64_t> b) {
    int n = a.size();
    sort(ALL(a));
    sort(ALL(b));

    vector<int64_t> sum(n + 1);
    partial_sum(ALL(a), sum.begin() + 1);
    int64_t ans = 0;
    for (int64_t b_j : b) {
        int i = lower_bound(ALL(a), b_j) - a.begin();
        ans += sum[n] - sum[i] - b_j * (n - i);
        ans += b_j * i - (sum[i] - sum[0]);
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int64_t> a(n);
    REP (i, n) {
        cin >> a[i];
    }
    vector<int64_t> b(m);
    REP (j, m) {
        cin >> b[j];
    }
    cout << solve(a, b) << endl;
    return 0;
}

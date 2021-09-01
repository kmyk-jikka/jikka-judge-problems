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
    int64_t ans = 0;
    ans += accumulate(ALL(a), 0ll) * b.size();
    ans -= a.size() * accumulate(ALL(b), 0ll);
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

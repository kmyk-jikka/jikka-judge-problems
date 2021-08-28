#include <algorithm>
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

int64_t solve(const string &s) {
    int64_t ans = 0;
    REP (i, s.length()) {
        if (s.substr(i, 5) == "fixed") {
            ans += 1;
        }
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}

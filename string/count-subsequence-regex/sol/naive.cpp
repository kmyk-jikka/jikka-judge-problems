#include <algorithm>
#include <cstdint>
#include <iostream>
#include <regex>
#include <vector>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
using namespace std;

constexpr int MOD = 998244353;

int solve(const string &s) {
    while (s.length() > 30) {
        // TLE
    }

    int ans = 0;
    regex pattern("(re)+g(exp?|ular*e?xp(res*ion)?)");
    REP (x, 1 << s.length()) {
        string t;
        REP (i, s.length()) {
            if (x & (1 << i)) {
                t += s[i];
            }
        }
        if (regex_match(t, pattern)) {
            ans += 1;
        }
    }
    return ans % MOD;
}

int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}

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

int64_t solve(const string &s) {
    int64_t ans = 0;
    regex pattern("(re)+g(exp?|ular*e?xp(res*ion)?)");
    REP (l, s.length()) {
        REP3 (r, l + 1, s.length() + 1) {
            string t = s.substr(l, r - l);
            if (regex_match(t, pattern)) {
                ans += 1;
            }
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

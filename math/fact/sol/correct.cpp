#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
using namespace std;

constexpr int MOD = 1000000007;

int main() {
    // input
    int n;
    cin >> n;

    // solve
    long long ans = 0;
    REP (i, n) {
        ans *= i + 1;
        ans %= MOD;
    }

    // output
    printf("%lld\n", ans);
    return 0;
}

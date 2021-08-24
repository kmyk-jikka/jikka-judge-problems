#include <vector>
#include <iostream>
using namespace std;

constexpr int MOD = 1000000007;

int main() {
    // input
    long long a, b, n;
    scanf("%lld%lld%lld", &a, &b, &n);

    // solve
    a = (a % MOD + MOD) % MOD;
    b = (b % MOD + MOD) % MOD;
    n %= MOD;
    long long ans = 0;
    ans += a * (n * (n - 1) / 2 % MOD) % MOD;
    ans += b * n % MOD;
    ans %= MOD;

    // output
    printf("%lld\n", ans);
    return 0;
}

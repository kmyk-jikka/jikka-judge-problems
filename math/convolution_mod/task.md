## @{keyword.statement}

``` python
from typing import *

MOD = 998244353


def solve(n: int, m: int, a: List[int], b: List[int]) -> List[int]:
    c = [0 for _ in range(n + m - 1)]
    for i in range(n + m - 1):
        for j in range(max(0, i - m + 1), min(n, i + 1)):
            c[i] += a[j] * b[i - j]
    return [c_i % MOD for c_i in c]


def main() -> None:
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    assert len(a) == n
    b = list(map(int, input().split()))
    assert len(b) == m
    ans = solve(n, m, a, b)
    print(*ans)


if __name__ == '__main__':
    main()
```

<!-- location.href doesn't work via React... -->

Please go Library Checker <https://judge.yosupo.jp/problem/convolution_mod>.
You cannot submit to this problem.

<!--

@{example.example_00}

-->


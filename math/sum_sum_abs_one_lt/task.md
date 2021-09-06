## @{keyword.statement}

``` python
from typing import *


def solve(n: int, a: List[int]) -> int:
    ans = 0
    for i in range(n):
        for j in range(i + 1, n):
            ans += abs(a[i] - a[j])
    return ans


def main() -> None:
    n = int(input())
    a = list(map(int, input().split()))
    assert len(a) == n
    ans = solve(n, a)
    print(ans)


if __name__ == "__main__":
    main()
```

This problem is almost the same to [AtCoder Beginner Contest 186: D - Sum of difference](https://atcoder.jp/contests/abc186/tasks/abc186_d).

## @{keyword.constraints}

- $@{param.N_MIN} \leq N \leq @{param.N_MAX}$
- $@{param.X_MIN} \leq a_i \leq @{param.X_MAX}$

## @{keyword.input}

```
$N$
$a_1$ $a_2$ $\ldots$ $a_N$
```

## @{keyword.sample}

@{example.example_00}

@{example.example_01}

@{example.example_02}

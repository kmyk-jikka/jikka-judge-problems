## @{keyword.statement}

``` python
from typing import *


def solve(a: List[int], b: List[int]) -> int:
    ans = 0
    for i in range(n):
        for j in range(n):
            ans += abs(a[i] - a[j]) * abs(b[i] - b[j])
    return ans


def main() -> None:
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    assert len(a) == n
    b = list(map(int, input().split()))
    assert len(b) == m
    ans = solve(a, b)
    print(ans)


if __name__ == "__main__":
    main()
```

関連する問題: [yukicoder No.1649 Manhattan Square](https://yukicoder.me/problems/no/1649)

## @{keyword.constraints}

- $@{param.N_MIN} \leq N \leq @{param.N_MAX}$
- $@{param.A_MIN} \leq a_i \leq @{param.A_MAX}$
- $@{param.A_MIN} \leq b_j \leq @{param.A_MAX}$

## @{keyword.input}

```
$N$ $M$
$a_1$ $a_2$ $\ldots$ $a_N$
$b_1$ $b_2$ $\ldots$ $b_N$
```

## @{keyword.sample}

@{example.example_00}

@{example.example_01}

@{example.example_02}

@{example.example_03}

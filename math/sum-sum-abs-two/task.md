## @{keyword.statement}

``` python
from typing import *


def solve(a: List[int], b: List[int]) -> int:
    ans = 0
    for a_i in a:
        for b_j in b:
            ans += abs(a_i - b_j)
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

## @{keyword.constraints}

- $@{param.N_MIN} \leq N \leq @{param.N_MAX}$
- $@{param.N_MIN} \leq M \leq @{param.N_MAX}$
- $@{param.A_MIN} \leq a_i \leq @{param.A_MAX}$
- $@{param.A_MIN} \leq b_j \leq @{param.A_MAX}$

## @{keyword.input}

```
$N$ $M$
$a_1$ $a_2$ $\ldots$ $a_N$
$b_1$ $b_2$ $\ldots$ $b_M$
```

## @{keyword.sample}

@{example.example_00}

@{example.example_01}

@{example.example_02}

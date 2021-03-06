## @{keyword.statement}

``` python
from typing import *


def solve(a: List[int]) -> int:
    ans = 0
    for a_i in a:
        for a_j in a:
            ans += a_i * a_j
    return ans % 998244353


def main() -> None:
    n = int(input())
    a = list(map(int, input().split()))
    assert len(a) == n
    ans = solve(a)
    print(ans)


if __name__ == "__main__":
    main()
```

## @{keyword.constraints}

- $@{param.N_MIN} \leq N \leq @{param.N_MAX}$
- $@{param.X_MIN} \leq a_i \leq @{param.X_MAX}$
- $\mathrm{MOD} = @{param.MOD}$

## @{keyword.input}

```
$N$
$a_1$ $a_2$ $\ldots$ $a_N$
```

## @{keyword.sample}

@{example.example_00}

@{example.example_01}

@{example.example_02}

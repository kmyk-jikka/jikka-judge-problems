## @{keyword.statement}

``` python
def solve(a: int, b: int, n: int) -> int:
    y = 0
    for x in range(n):
        y += a * x + b
    return y % 1000000007
```

## @{keyword.constraints}

- $-10^9 \leq a, b \leq 10^9$
- $0 \leq n \leq 10^{18}$

## @{keyword.input}

```
$a$ $b$ $n$
```

## @{keyword.sample}

@{example.example_00}

@{example.example_01}

@{example.example_02}

@{example.example_03}

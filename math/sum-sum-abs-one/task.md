## @{keyword.statement}

``` python
def solve(x: List[int]) -> int:
    ans = 0
    for x_i in x:
        for x_j in x:
            ans += abs(x_i - x_j)
    return ans
```

## @{keyword.constraints}

- $0 \leq N \leq 10^5$
- $-10^8 \leq x_i \lt 10^8$

## @{keyword.input}

```
$N$
$a_1$ $a_2$ $\ldots$ $a_N$
```

## @{keyword.sample}

@{example.example_00}

@{example.example_01}

@{example.example_02}

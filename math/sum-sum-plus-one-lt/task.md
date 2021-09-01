## @{keyword.statement}

``` python
def solve(a: List[int]) -> int:
    n = len(a)
    ans = 0
    for i in range(n):
        for j in range(i + 1, n):
            ans += a[i] - a[j]
    return ans
```

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

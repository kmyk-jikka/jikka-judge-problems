## @{keyword.statement}

``` python
def solve(a: List[int], b: List[int]) -> int:
    ans = 0
    for a_i in a:
        for b_j in b:
            ans += abs(a_i - b_j)
    return ans
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

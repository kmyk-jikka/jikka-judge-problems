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

- $0 \leq N \leq 10^5$
- $0 \leq M \leq 10^5$
- $-10^8 \leq a_i \lt 10^8$
- $-10^8 \leq b_j \lt 10^8$

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

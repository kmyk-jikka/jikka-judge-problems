## @{keyword.statement}

``` python
INF = 10 ** 18

def solve(n: int, a: List[int], b: List[int]) -> int:
    n = len(a)
    dp = [INF for _ in range(n)]
    dp[0] = 0
    for i in range(1, n):
        for j in range(i):
            dp[i] = min(dp[i], dp[j] + a[j] * b[i])
    return dp[n - 1]

def main() -> None:
    n = int(input())
    a = list(map(int, input().split()))
    assert len(a) == n
    b = list(map(int, input().split()))
    assert len(b) == n
    ans = solve(n, a, b)
    print(ans)

if __name__ == "__main__":
    main()
```

## @{keyword.constraints}

- $@{param.N_MIN} \leq N \leq @{param.N_MAX}$
- $@{param.A_MIN} \leq a_i \leq @{param.A_MAX}$
- $@{param.B_MIN} \leq b_i \leq @{param.B_MAX}$

## @{keyword.input}

```
$N$
$a_1$ $a_2$ $\ldots$ $a_N$
$b_1$ $b_2$ $\ldots$ $b_N$
```

## @{keyword.sample}

@{example.example_00}

@{example.example_01}

@{example.example_02}

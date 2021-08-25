## @{keyword.statement}

``` python
INF = 10 ** 18

def solve(a: List[int]) -> int:
    n = len(a)
    dp = [INF for _ in range(n)]
    dp[0] = 0
    for i in range(1, n):
        for j in range(i):
            dp[i] = min(dp[i], dp[j] + (a[i] - a[j]) ** 2)
    return dp[n - 1]
```

or

``` python
INF = 10 ** 18

def solve(a: List[int]) -> int:
    n = len(a)
    dp = [INF for _ in range(n)]
    dp[0] = 0
    for j in range(n):
        for i in range(j + 1, n):
            dp[i] = min(dp[i], dp[j] + (a[i] - a[j]) ** 2)
    return dp[n - 1]
```

関連する問題: [Educational DP Contest / DP まとめコンテスト: Z - Frog 3](https://atcoder.jp/contests/dp/tasks/dp_z)

## @{keyword.constraints}

- $@{param.N_MIN} \leq N \leq @{param.N_MAX}$
- $@{param.A_MIN} \leq a_i \leq @{param.A_MAX}$

## @{keyword.input}

```
$N$
$a_1$ $a_2$ $\ldots$ $a_N$
```

## @{keyword.sample}

@{example.example_00}

@{example.example_01}

@{example.example_02}

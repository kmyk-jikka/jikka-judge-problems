## @{keyword.statement}

``` python
def solve(a: int, b: int, n: int) -> int:
    y = 0
    for x in range(n):
        y += a * x + b
    return y % 998244353


def main() -> None:
    a, b, n = map(int, input().split())
    ans = solve(a, b, n)
    print(ans)


if __name__ == "__main__":
    main()
```

## @{keyword.constraints}

- $@{param.A_MIN} \leq a, b \leq {param.A_MAX}$
- $@{param.N_MIN} \leq n \leq @{param.N_MAX}$

## @{keyword.input}

```
$a$ $b$ $n$
```

## @{keyword.sample}

@{example.example_00}

@{example.example_01}

@{example.example_02}

@{example.example_03}

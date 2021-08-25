## @{keyword.statement}

``` python
def solve(n: int) -> int:
    a = 0
    b = 1
    for _ in range(n):
        c = a + b
        a = b
        b = c
    return a % 998244353
```

## @{keyword.constraints}

- $@{param.N_MIN} \leq n \leq @{param.N_MAX}$
- $\mathrm{MOD} = @{param.MOD}$

## @{keyword.input}

```
$n$
```

## @{keyword.sample}

@{example.example_00}

@{example.example_01}

@{example.example_02}

@{example.example_03}

@{example.example_04}

@{example.example_05}

@{example.example_06}

@{example.example_07}

@{example.example_08}

@{example.example_09}

@{example.example_10}

@{example.example_11}

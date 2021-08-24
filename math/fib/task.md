## @{keyword.statement}

``` python
def fib(n: int) -> int:
    if n <= 1:
        return n
    else:
        return (fib(n - 2) + fib(n - 1)) % @{param.MOD}
```

## @{keyword.constraints}

- $@{param.N_MIN} \leq n \leq @{param.N_MAX}$

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

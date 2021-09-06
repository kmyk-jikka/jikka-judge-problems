## @{keyword.statement}

``` python
import itertools


def solve(s: str) -> int:
    ans = 0
    for xs in itertools.product(range(2), len(s)):
        if ''.join([s[x] for x in xs]) == "fixed":
            ans += 1
    return ans % 998244353


def main() -> None:
    s = input()
    ans = solve(s)
    print(ans)


if __name__ == "__main__":
    main()
```

## @{keyword.constraints}

- $@{param.LEN_S_MIN} \le \lvert S \rvert \le @{param.LEN_S_MAX}$
- Each character of $S$ is lowercase English letters.
- $\mathrm{MOD} = @{param.MOD}$

## @{keyword.input}

```
$S$
```

## @{keyword.sample}

@{example.example_00}

@{example.example_01}

@{example.example_02}

@{example.example_03}

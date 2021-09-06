## @{keyword.statement}

``` python
def solve(s: str) -> int:
    ans = 0
    for l in range(len(s)):
        for r in range(l + 1, len(s) + 1):
            if s[l:r] == "fixed":
                ans += 1
    return ans


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

## @{keyword.input}

```
$S$
```

## @{keyword.sample}

@{example.example_00}

@{example.example_01}

@{example.example_02}

@{example.example_03}

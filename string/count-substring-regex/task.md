## @{keyword.statement}

``` python
import re

def solve(s: str, k: int) -> int:
    ans = 0
    for l in range(len(s)):
        for r in range(l + 1, len(s) + 1):
            t = s[l:r]
            if re.search(r'(re)+g(exp?|ular*e?xp(res*ion)?)', t):
                ans += 1
    return ans
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

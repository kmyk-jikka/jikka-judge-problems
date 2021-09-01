## @{keyword.statement}

``` python
import itertools
import re

def solve(s: str, k: int) -> int:
    ans = 0
    for xs in itertools.product(range(2), len(s)):
        t = ''.join([s[x] for x in xs])
        if re.search(r'(re)+g(exp?|ular*e?xp(res*ion)?)', t):
            ans += 1
    return ans % 998244353
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

#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

/**
 * @note y = ax + b
 */
struct line_t {
  int64_t a, b;
};
bool operator<(line_t lhs, line_t rhs) {
  return std::make_pair(-lhs.a, lhs.b) < std::make_pair(-rhs.a, rhs.b);
}

struct rational_t {
  int64_t num, den;
};
bool operator<(rational_t lhs, rational_t rhs) {
  if (lhs.num == INT64_MAX or rhs.num == -INT64_MAX)
    return false;
  if (lhs.num == -INT64_MAX or rhs.num == INT64_MAX)
    return true;
  return (__int128_t)lhs.num * rhs.den < (__int128_t)rhs.num * lhs.den;
}

/*
 * @brief Convex Hull Trick (非単調, online)
 * @docs data_structure/convex_hull_trick.md
 */
class convex_hull_trick {
  static rational_t make_rational(int64_t num, int64_t den = 1) {
    if (den < 0) {
      num *= -1;
      den *= -1;
    }
    return {num, den}; // NOTE: no reduction
  }

public:
  convex_hull_trick() {
    lines.insert({+INT64_MAX, 0}); // sentinels
    lines.insert({-INT64_MAX, 0});
    cross.emplace(make_rational(-INT64_MAX), (line_t){-INT64_MAX, 0});
  }
  /**
   * @note O(log n)
   */
  void add_line(int64_t a, int64_t b) {
    auto it = lines.insert({a, b}).first;
    if (not is_required(*prev(it), {a, b}, *next(it))) {
      lines.erase(it);
      return;
    }
    cross.erase(cross_point(*prev(it), *next(it)));
    { // remove right lines
      auto ju = prev(it);
      while (ju != lines.begin() and not is_required(*prev(ju), *ju, {a, b}))
        --ju;
      cross_erase(ju, prev(it));
      it = lines.erase(++ju, it);
    }
    { // remove left lines
      auto ju = next(it);
      while (next(ju) != lines.end() and
             not is_required({a, b}, *ju, *next(ju)))
        ++ju;
      cross_erase(++it, ju);
      it = prev(lines.erase(it, ju));
    }
    cross.emplace(cross_point(*prev(it), *it), *it);
    cross.emplace(cross_point(*it, *next(it)), *next(it));
    assert(not empty());
  }
  bool empty() const { return lines.size() <= 2; }
  /**
   * @note O(log n)
   */
  int64_t get_min(int64_t x) const {
    assert(not empty());
    line_t f = prev(cross.lower_bound(make_rational(x)))->second;
    return f.a * x + f.b;
  }

private:
  std::set<line_t> lines;
  std::map<rational_t, line_t> cross;
  template <typename Iterator> void cross_erase(Iterator first, Iterator last) {
    for (; first != last; ++first) {
      cross.erase(cross_point(*first, *next(first)));
    }
  }
  rational_t cross_point(line_t f1, line_t f2) const {
    if (f1.a == INT64_MAX)
      return make_rational(-INT64_MAX);
    if (f2.a == -INT64_MAX)
      return make_rational(INT64_MAX);
    return make_rational(f1.b - f2.b, f2.a - f1.a);
  }
  bool is_required(line_t f1, line_t f2, line_t f3) const {
    if (f1.a == f2.a and f1.b <= f2.b)
      return false;
    if (f1.a == INT64_MAX or f3.a == -INT64_MAX)
      return true;
    return (__int128_t)(f2.a - f1.a) * (f3.b - f2.b) <
           (__int128_t)(f2.b - f1.b) * (f3.a - f2.a);
  }
};

using namespace std;

int64_t solve(int n, const vector<int64_t> &a, const vector<int64_t> &b) {
  vector<int64_t> dp(n);
  dp[0] = 0;
  convex_hull_trick cht;
  for (int i = 0; i < n - 1; ++i) {
    cht.add_line(a[i], dp[i]);
    dp[i + 1] = cht.get_min(b[i + 1]);
  }
  return dp[n - 1];
}

int main() {
  int n;
  cin >> n;
  vector<int64_t> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int64_t> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  auto ans = solve(n, a, b);
  cout << ans << '\n';
  return 0;
}

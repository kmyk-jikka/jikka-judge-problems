#include <algorithm>
#include <cassert>
#include <cstdint>
#include <numeric>
#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)
using namespace std;

template <int32_t MOD>
struct mint {
    int32_t value;
    mint() : value() {}
    mint(int64_t value_) : value(value_ < 0 ? value_ % MOD + MOD : value_ >= MOD ? value_ % MOD : value_) {}
    mint(int32_t value_, std::nullptr_t) : value(value_) {}
    explicit operator bool() const { return value; }
    inline mint<MOD> operator + (mint<MOD> other) const { return mint<MOD>(*this) += other; }
    inline mint<MOD> operator - (mint<MOD> other) const { return mint<MOD>(*this) -= other; }
    inline mint<MOD> operator * (mint<MOD> other) const { return mint<MOD>(*this) *= other; }
    inline mint<MOD> & operator += (mint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
    inline mint<MOD> & operator -= (mint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
    inline mint<MOD> & operator *= (mint<MOD> other) { this->value = (uint_fast64_t)this->value * other.value % MOD; return *this; }
    inline mint<MOD> operator - () const { return mint<MOD>(this->value ? MOD - this->value : 0, nullptr); }
    inline bool operator == (mint<MOD> other) const { return value == other.value; }
    inline bool operator != (mint<MOD> other) const { return value != other.value; }
    // inline mint<MOD> pow(uint64_t k) const { return mint<MOD>(modpow(value, k, MOD), nullptr); }
    // inline mint<MOD> inv() const { return mint<MOD>(modinv(value, MOD), nullptr); }
    inline mint<MOD> operator / (mint<MOD> other) const { return *this * other.inv(); }
    inline mint<MOD> & operator /= (mint<MOD> other) { return *this *= other.inv(); }
};
template <int32_t MOD> mint<MOD> operator + (int64_t value, mint<MOD> n) { return mint<MOD>(value) + n; }
template <int32_t MOD> mint<MOD> operator - (int64_t value, mint<MOD> n) { return mint<MOD>(value) - n; }
template <int32_t MOD> mint<MOD> operator * (int64_t value, mint<MOD> n) { return mint<MOD>(value) * n; }
template <int32_t MOD> mint<MOD> operator / (int64_t value, mint<MOD> n) { return mint<MOD>(value) / n; }
template <int32_t MOD> std::istream & operator >> (std::istream & in, mint<MOD> & n) { int64_t value; in >> value; n = value; return in; }
template <int32_t MOD> std::ostream & operator << (std::ostream & out, mint<MOD> n) { return out << n.value; }

/**
 * @brief Segment Tree / セグメント木 (monoids, 完全二分木)
 * @docs data_structure/segment_tree.md
 * @tparam Monoid (commutativity is not required)
 */
template <class Monoid>
struct segment_tree {
    typedef typename Monoid::value_type value_type;
    Monoid mon;
    int n;
    std::vector<value_type> a;
    segment_tree() = default;
    segment_tree(int n_, const Monoid & mon_ = Monoid()) : mon(mon_) {
        n = 1; while (n < n_) n *= 2;
        a.resize(2 * n - 1, mon.unit());
    }
    void point_set(int i, value_type b) {  // 0-based
        assert (0 <= i and i < n);
        a[i + n - 1] = b;
        for (i = (i + n) / 2; i > 0; i /= 2) {  // 1-based
            a[i - 1] = mon.mult(a[2 * i - 1], a[2 * i]);
        }
    }
    value_type range_get(int l, int r) {  // 0-based, [l, r)
        assert (0 <= l and l <= r and r <= n);
        value_type lacc = mon.unit(), racc = mon.unit();
        for (l += n, r += n; l < r; l /= 2, r /= 2) {  // 1-based loop, 2x faster than recursion
            if (l % 2 == 1) lacc = mon.mult(lacc, a[(l ++) - 1]);
            if (r % 2 == 1) racc = mon.mult(a[(-- r) - 1], racc);
        }
        return mon.mult(lacc, racc);
    }

    value_type point_get(int i) {  // 0-based
        assert (0 <= i and i < n);
        return a[i + n - 1];
    }

    /**
     * @note O(min(n, (r - l) log n))
     */
    void range_set(int l, int r, value_type b) {
        assert (0 <= l and l <= r and r <= n);
        range_set(0, 0, n, l, r, b);
    }
    void range_set(int i, int il, int ir, int l, int r, value_type b) {
        if (l <= il and ir <= r and ir - il == 1) {  // 0-based
            a[i] = b;
        } else if (ir <= l or r <= il) {
            // nop
        } else {
            range_set(2 * i + 1, il, (il + ir) / 2, l, r, b);
            range_set(2 * i + 2, (il + ir) / 2, ir, l, r, b);
            a[i] = mon.mult(a[2 * i + 1], a[2 * i + 2]);
        }
    }

    /**
     * @brief a fast & semigroup-friendly version constructor
     * @note $O(n)$
     */
    template <class InputIterator>
    segment_tree(InputIterator first, InputIterator last, const Monoid & mon_ = Monoid()) : mon(mon_) {
        int size = std::distance(first, last);
        n = 1; while (n < size) n *= 2;
        a.resize(2 * n - 1, mon.unit());
        std::copy(first, last, a.begin() + (n - 1));
        unsafe_rebuild();
    }
    /**
     * @brief update a leaf node without updating ancestors
     * @note $O(1)$
     */
    void unsafe_point_set(int i, value_type b) {  // 0-based
        assert (0 <= i and i < n);
        a[i + n - 1] = b;
    }
    /**
     * @brief re-build non-leaf nodes from leaf nodes
     * @note $O(n)$
     */
    void unsafe_rebuild() {
        REP_R (i, n - 1) {
            a[i] = mon.mult(a[2 * i + 1], a[2 * i + 2]);
        }
    }
};

template <class T>
struct plus_monoid {
    typedef T value_type;
    value_type unit() const { return value_type(); }
    value_type mult(value_type a, value_type b) const { return a + b; }
};

constexpr int MOD = 998244353;

mint<MOD> solve(int n, vector<int64_t> x, vector<int64_t> y) {
    vector<int> order_x(n);
    iota(ALL(order_x), 0);
    sort(ALL(order_x), [&](int i, int j) { return x[i] > x[j]; });

    vector<int64_t> compress_y = y;
    sort(ALL(compress_y));
    compress_y.erase(unique(ALL(compress_y)), compress_y.end());
    const int H = compress_y.size();

    mint<MOD> ans = 0;

    // \sum_i \sum_{i < j} |x_i - x_j| |y_i - y_j|
    segment_tree<plus_monoid<mint<MOD>>> segtree_sum(H);
    segment_tree<plus_monoid<mint<MOD>>> segtree_cnt(H);
    for (int j : order_x) {
        // - \sum \sum x_j |y_i - y_j|
        int k = lower_bound(ALL(compress_y), y[j]) - compress_y.begin();
        ans -= x[j] * (segtree_sum.range_get(k + 1, H) - segtree_cnt.range_get(k + 1, H) * y[j]);
        ans -= x[j] * (segtree_cnt.range_get(0, k) * y[j] - segtree_sum.range_get(0, k));
        segtree_sum.point_set(k, segtree_sum.point_get(k) + y[j]);
        segtree_cnt.point_set(k, segtree_cnt.point_get(k) + 1);
    }
    for (int i : order_x) {
        // \sum \sum x_i |y_i - y_j|
        int k = lower_bound(ALL(compress_y), y[i]) - compress_y.begin();
        segtree_sum.point_set(k, segtree_sum.point_get(k) - y[i]);
        segtree_cnt.point_set(k, segtree_cnt.point_get(k) - 1);
        ans += x[i] * (segtree_sum.range_get(k + 1, H) - segtree_cnt.range_get(k + 1, H) * y[i]);
        ans += x[i] * (segtree_cnt.range_get(0, k) * y[i] - segtree_sum.range_get(0, k));
    }

    // \sum_i \sum_j |x_i - x_j| |y_i - y_j|
    ans *= 2;
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    REP (i, n) {
        cin >> a[i];
    }
    vector<int64_t> b(n);
    REP (j, n) {
        cin >> b[j];
    }
    cout << solve(n, a, b) << endl;
    return 0;
}

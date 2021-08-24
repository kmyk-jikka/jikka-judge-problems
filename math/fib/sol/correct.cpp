#include <array>
#include <cstdint>
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

template <typename T, size_t H, size_t W>
using matrix = std::array<std::array<T, W>, H>;

template <typename T, size_t A, size_t B, size_t C>
matrix<T, A, C> operator * (matrix<T, A, B> const & a, matrix<T, B, C> const & b) {
    matrix<T, A, C> c = {};
    REP (y, A) REP (z, B) REP (x, C) c[y][x] += a[y][z] * b[z][x];
    return c;
}

template <typename T, size_t H, size_t W>
std::array<T, H> operator * (matrix<T, H, W> const & a, std::array<T, W> const & b) {
    std::array<T, H> c = {};
    REP (y, H) REP (z, W) c[y] += a[y][z] * b[z];
    return c;
}

template <typename T, size_t N>
matrix<T, N, N> unit_matrix() {
    matrix<T, N, N> a = {};
    REP (i, N) a[i][i] = 1;
    return a;
}

template <typename T, size_t N>
matrix<T, N, N> matpow(matrix<T, N, N> x, int64_t k) {
    matrix<T, N, N> y = unit_matrix<T, N>();
    for (; k; k >>= 1) {
        if (k & 1) y = y * x;
        x = x * x;
    }
    return y;
}

constexpr int MOD = 998244353;

int main() {
    // input
    int64_t n;
    cin >> n;

    // solve
    matrix<mint<MOD>, 2, 2> f = {{
        {{1, 1}},
        {{1, 0}},
    }};
    array<mint<MOD>, 2> x = {{
        1, 0
    }};
    mint<MOD> y = (matpow(f, n) * x)[1];

    // output
    cout << y << endl;
    return 0;
}

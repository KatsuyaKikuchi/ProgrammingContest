#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 998244353;
const ll INF = (ll) 1e15;

template<std::uint_fast64_t Modulus>
class ModInt {
    using u64 = std::uint_fast64_t;
public:
    constexpr ModInt(u64 value = 0) noexcept:
            mValue(value % Modulus) {}

    u64 &value() { return mValue; }

    constexpr ModInt &operator+=(ModInt v) noexcept {
        mValue += v.mValue;
        if (mValue >= Modulus)
            mValue -= Modulus;
        return *this;
    }

    constexpr ModInt &operator-=(ModInt v) noexcept {
        if (mValue < v.mValue)
            mValue += Modulus;
        mValue -= v.mValue;
        return *this;
    }

    constexpr ModInt &operator*=(ModInt v) noexcept {
        mValue = (mValue * v.mValue) % Modulus;
        return *this;
    }

    constexpr ModInt &operator/=(ModInt v) noexcept {
        *this *= v.pow(Modulus - 2);
        return *this;
    }

    constexpr ModInt operator+(ModInt v) noexcept {
        return ModInt(*this) += v;
    }

    constexpr ModInt operator-(ModInt v) noexcept {
        return ModInt(*this) -= v;
    }

    constexpr ModInt operator*(ModInt v) noexcept {
        return ModInt(*this) *= v;
    }

    constexpr ModInt operator/(ModInt v) noexcept {
        return ModInt(*this) /= v;
    }

    ModInt pow(u64 r) {
        u64 p = mValue;
        ModInt ret(1);
        while (r > 0) {
            if (r & 1)
                ret *= p;
            r >>= 1;
            p = (p * p) % Modulus;
        }
        return ret;
    }

private:
    u64 mValue;
};

ll sums(pll a, pll b) {
    ll mh0 = std::min(a.first, b.first);
    ll mh1 = std::max(a.first, b.first);
    ll mw0 = std::min(a.second, b.second);
    ll mw1 = std::max(a.second, b.second);
    ll mw = mw1 - mw0;
    ll mh = mh1 - mh0;
    return mw + mh;
}

int main() {
    using mint = ModInt<MOD>;
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    pll a, b;
    cin >> a.first >> a.second >> b.first >> b.second;
    mint ans = 0;
    REP(i, H - 1) {
        //! i番目の横線が期待値に与える影響を考える
        ll h = i + 1;
        if (a.first <= h && b.first <= h) {
            ll mh = h - std::max(a.first, b.first) + 1 + sums(a, b);
            ans += ((mint) 1) / mh;
        }
        else if (a.first > h && b.first > h) {
            ll mh = std::min(a.first, b.first) - h + sums(a, b);
            ans += ((mint) 1) / mh;
        }
        else {
            ans += ((mint) 1) / sums(a, b);
        }
    }
    REP(i, W - 1) {
        //! i番目の縦線が期待値に与える影響を考える
        ll w = i + 1;
        if (a.second <= w && b.second <= w) {
            ll mw = w - std::max(a.second, b.second) + 1 + sums(a, b);
            ans += ((mint) 1) / mw;
        }
        else if (a.second > w && b.second > w) {
            ll mw = std::min(a.second, b.second) - w + sums(a, b);
            ans += ((mint) 1) / mw;
        }
        else {
            ans += ((mint) 1) / sums(a, b);
        }
    }

    cout << ans.value() << endl;
    return 0;
}
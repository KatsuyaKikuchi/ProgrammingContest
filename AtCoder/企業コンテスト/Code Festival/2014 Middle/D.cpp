#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 2005;
const ll MID = 1001;

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

int main() {
    using mint = ModInt<MOD>;
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<pll> A(N);
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    vector<vector<mint>> dp(N + 5, vector<mint>(MAX + 1, 0));
    for (ll p = -A[0].second; p <= A[0].second; ++p) {
        dp[0][p + MID] = 1;
    }
    REP(i, MAX) {
        dp[0][i + 1] += dp[0][i];
    }
    FOR(i, N, 1) {
        for (ll p = -A[i].second; p <= A[i].second; ++p) {
            ll x = A[i].first + p;
            ll m = std::max(0LL, std::min(MAX, x - A[i - 1].first + MID - 1));
            dp[i][p + MID] += dp[i - 1][m];
        }
        REP(j, MAX) {
            dp[i][j + 1] += dp[i][j];
        }
    }
    cout << dp[N - 1][MAX].value() << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

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

int main() {
    using mint = ModInt<MOD>;
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;
    vector<mint> S(N + 5);
    S[1] = 1;
    FOR(i, S.size(), 2) {
        S[i] += S[i - 1] + S[i - 2];
    }

    vector<vector<mint>> dp(N + 10, vector<mint>(N + 10, 0));
    REP(i, N + 5) {
        // dp[i][i] = 1;
    }
    REP(i, N + 5) {
        REP(j, N + 5) {
            dp[i][j] += S[j];
        }
    }
    mint ans = 0;
    REP(i, N + 1) {
        //! 1/2をi個とる
        ll n = N - (2 * i);
        if (n < 0)
            continue;
        ll s = N - i - K;
        if (s < 0)
            continue;
        if (s == 0) {
            //ans += 1;
            // continue;
        }
        if (s > n)
            continue;
        //if (2 * i + s > N)
        // continue;
        ans += dp[2 * i][s];
    }
    cout << ans.value() << endl;
    return 0;
}
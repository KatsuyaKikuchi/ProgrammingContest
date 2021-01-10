#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
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

using mint = ModInt<MOD>;

vector<ll> P, M;

ll solve(ll N, ll K) {
    bool zero = P.size() + M.size() < N;
    if (P.size() + M.size() < K)
        return 0;
    if (M.size() % 2 == 1 && M.size() + P.size() == K) {
        if (!zero) {
            ll x = 1;
            REP(i, P.size()) {
                x = (x * P[i]) % MOD;
            }
            REP(i, M.size()) {
                x = (x * abs(M[i])) % MOD;
            }
            return MOD - x;
        }
        else {
            return 0;
        }
    }
    if (P.size() == 0 && K % 2 == 1) {
        if (zero)
            return 0;
        reverse(M.begin(), M.end());
        ll x = 1;
        REP(i, K) {
            x = (x * abs(M[i])) % MOD;
        }
        return MOD - x;
    }

    vector<pll> v;
    REP(i, P.size()) {
        v.push_back(pll(P[i], 1));
    }
    REP(i, M.size()) {
        v.push_back(pll(abs(M[i]), -1));
    }
    sort(v.begin(), v.end(), [](pll a, pll b) { return a.first > b.first; });
    mint ret = 1;
    ll m = 0, p = 0;
    ll pi = 0, mi = 0;
    REP(i, K) {
        ret *= v[i].first;
        if (v[i].second < 0) {
            m++;
            mi = i;
        }
        else {
            p++;
            pi = i;
        }
    }

    if (m % 2 == 1) {
        ll a = 0, b = 0, c = 0;
        if (m < M.size() && p > 0) {
            if (p < P.size() && m > 0) {
                // マイナスを減らしてプラスを一つたす
                // プラスを減らしてマイナスを1つたす
                // より大きい方
                ll m0 = 0, p0 = 0;
                FOR(i, v.size(), mi + 1) {
                    if (v[i].second < 0) {
                        m0 = v[i].first;
                        break;
                    }
                }
                FOR(i, v.size(), pi + 1) {
                    if (v[i].second > 0) {
                        p0 = v[i].first;
                        break;
                    }
                }

                if (v[mi].first * m0 < v[pi].first * p0) {
                    ret /= v[mi].first;
                    ret *= p0;
                }
                else {
                    ret /= v[pi].first;
                    ret *= m0;
                }
            }
            else {
                // プラスを減らしてマイナスを1つたす
                ret /= v[pi].first;
                FOR(i, v.size(), mi + 1) {
                    if (v[i].second < 0) {
                        ret *= v[i].first;
                        break;
                    }
                }
            };
        }
        else if (p < P.size() && m > 0) {
            // マイナスを減らしてプラスを一つたす
            ret /= v[mi].first;
            FOR(i, v.size(), pi + 1) {
                if (v[i].second > 0) {
                    ret *= v[i].first;
                    break;
                }
            }
        }
        else {
            ret = 0;
        }
    }

    return ret.value();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        ll a;
        cin >> a;
        if (a < 0)
            M.push_back(a);
        else if (a > 0)
            P.push_back(a);
    }
    sort(M.begin(), M.end());
    sort(P.begin(), P.end(), greater<ll>());

    cout << solve(N, K) << endl;

    return 0;
}
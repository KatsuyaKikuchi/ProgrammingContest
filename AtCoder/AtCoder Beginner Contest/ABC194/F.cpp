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

ll count(ll bit) {
    ll ret = 0;
    REP(i, 16) {
        if ((bit >> i) & 1)
            ret++;
    }
    return ret;
}

ll num(char c) {
    if ('0' <= c && c <= '9')
        return c - '0';
    return 10 + c - 'A';
}

struct Combination {
    Combination(ll n) :
            mSize(n) {
        mNumTbl.resize(n + 1);
        mInverseNumTbl.resize(n + 1);
        mNumTbl[0] = 1;
        mInverseNumTbl[0] = 1;
        FOR(i, n + 1, 1) {
            mNumTbl[i] = (mNumTbl[i - 1] * i) % MOD;
        }
        FOR(i, n + 1, 1) {
            mInverseNumTbl[i] = modpow(mNumTbl[i]);
        }
    }

    ll get(ll n, ll r) {
        assert(mSize >= n);
        if (n < r || n < 0)
            return 0;
        return (((mNumTbl[n] * mInverseNumTbl[r]) % MOD) * mInverseNumTbl[n - r]) % MOD;
    }

private:
    ll modpow(ll n) {
        ll s = 1, p = n;
        for (ll i = 0; (1LL << i) <= MOD - 2; ++i, p = (p * p) % MOD) {
            if (((MOD - 2) & (1 << i)) == 0)
                continue;
            s *= p;
            s %= MOD;
        }
        return s;
    }

    ll mSize;
    vector<ll> mInverseNumTbl;
    vector<ll> mNumTbl;
};

int main() {
    using mint = ModInt<MOD>;
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll K;
    cin >> K;
    ll N = S.length();
    ll bit = 0;

    Combination cmb(200005);

    mint ans = 0;
    REP(i, N) {
        ll nm = num(S[i]);
        REP(n, nm) {
            ll b = (bit | (1LL << n));
            if (b == 1)
                continue;
            ll cnt = count(b);
            if (cnt > K)
                continue;
            ll m = K - cnt;
            ll len = N - (i + 1);
            mint t = ((mint) K).pow(len);
            REP(j, m) {
                mint x = cmb.get(m, j + 1);
                mint y = cnt + (m - j - 1);
                x *= y.pow(len);
                if (j % 2 == 0)
                    t -= x;
                else
                    t += x;
            }
            ans += t * cmb.get(16 - cnt, K - cnt);
        }
        bit |= (1LL << nm);
    }
    //! 一番上が0のやつ足していく
    FOR(i, N, 1) {
        if (i < K)
            continue;
        mint t = ((mint) K).pow(i - 1);
        REP(j, K - 1) {
            mint x = cmb.get(K - 1, j + 1);
            mint y = K - (j + 1);
            x *= y.pow(i - 1);
            if (j % 2 == 0)
                t -= x;
            else
                t += x;
        }
        ans += t * cmb.get(15, K - 1) * 15LL;;
    }

    if (count(bit) == K)
        ans += 1;
    cout << ans.value() << endl;

    return 0;
}
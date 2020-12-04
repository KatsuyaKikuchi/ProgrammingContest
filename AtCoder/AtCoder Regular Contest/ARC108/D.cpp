#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[5];

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
    ll N;
    cin >> N;
    REP(i, 4) {
        char c;
        cin >> c;
        if (c == 'A')
            C[i] = 0;
        else
            C[i] = 1;
    }
    if (N <= 3) {
        cout << 1 << endl;
        return 0;
    }

    if (C[1] == 0) {
        if (C[0] == C[1]) {
            cout << 1 << endl;
            return 0;
        }
    }
    else {
        if (C[1] == C[3]) {
            cout << 1 << endl;
            return 0;
        }
    }

    Combination cmb(10000);

    mint ans = 1;
    if (C[1] == 1) {
        if (C[2] == 0) {
            /*
             * AA = A or B
             * AB = B
             * BA = A
             * BB = A
             */
            mint p = 2;
            ans = p.pow(N - 3);
        }
        else if (C[2] == 1) {
            /*
            * AA = A or B
            * AB = B
            * BA = B
            * BB = A
            */
            //! Aが二つ隣り合わない物
            ans = 0;
            for (ll i = 0; i <= N - 3; ++i) {
                ll a = N - 3 - i;
                if (a > i + 1)
                    continue;
                ans += cmb.get(i + 1, a);
            }
        }
    }
    else if (C[1] == 0) {
        if (C[2] == 1) {
            /*
             * AA = B
             * AB = A
             * BA = B
             * BB = A or B
             */
            mint p = 2;
            ans = p.pow(N - 3);
        }
        else if (C[2] == 0) {
            /*
            * AA = B
            * AB = A
            * BA = A
            * BB = A or B
            */
            //! Bが二つ隣り合わない物
            ans = 0;
            for (ll i = 0; i <= N - 3; ++i) {
                ll a = N - 3 - i;
                if (a > i + 1)
                    continue;
                ans += cmb.get(i + 1, a);
            }
        }
    }

    cout << ans.value() << endl;

    return 0;
}
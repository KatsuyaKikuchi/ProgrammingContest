#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 3;
const ll INF = (ll) 1e15;

char check(char a, char b) {
    if (a == 'R') {
        if (b == 'R')
            return 'R';
        if (b == 'B')
            return 'W';
        return 'B';
    }
    if (a == 'B') {
        if (b == 'B')
            return 'B';
        if (b == 'R')
            return 'W';
        return 'R';
    }
    if (b == 'W')
        return 'W';
    if (b == 'B')
        return 'R';
    return 'B';
}

void test(string &S) {
    ll r = 0, b = 0, w = 0;
    ll N = S.length();
    REP(i, N) {
        if (S[i] == 'R')
            r++;
        if (S[i] == 'B')
            b++;
        if (S[i] == 'W')
            w++;
    }
    cout << S << ",R:" << r << ",B:" << b << ",W:" << w << endl;
    if (N == 1) {
        return;
    }
    string s = "";
    REP(i, N - 1) {
        s.push_back(check(S[i], S[i + 1]));
    }
    test(s);
}

char C[3] = {'W', 'B', 'R'};

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

ll P[400015];

struct Combination {
    Combination(ll n) :
            mSize(n) {
        mNumTbl.resize(n + 1);
        mInverseNumTbl.resize(n + 1);
        mNumTbl[0] = 1;
        mInverseNumTbl[0] = 1;
        FOR(i, n + 1, 1) {
            ll x = i;
            while (x % 3 == 0) {
                x /= 3;
            }
            mNumTbl[i] = (mNumTbl[i - 1] * x) % MOD;
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
    using mint = ModInt<3>;
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string S;
    cin >> S;
    Combination cmb(N + 10);
    // N以下の整数について、3で何回割り切れるか
    P[0] = 0;
    REP(i, N + 5) {
        ll n = i + 1;
        P[n] = P[i];
        ll x = n;
        while (x % 3 == 0) {
            P[n]++;
            x /= 3;
        }
    }
    vector<ll> v(N);
    REP(i, N) {
        REP(j, 3) {
            if (C[j] == S[i]) {
                v[i] = j;
                break;
            }
        }
        // cout << v[i] << " ";
    }
    //cout << endl;

    mint p = 0;
    REP(i, N) {
        ll a = P[N - 1];
        ll b = P[i] + P[N - 1 - i];
        if (a != b)
            continue;
        // cout << cmb.get(N - 1, i) << " ";
        if (N % 2 == 0)
            p -= v[i] * cmb.get(N - 1, i);
        else
            p += v[i] * cmb.get(N - 1, i);
    }
    //   cout << endl;
    // cout << p.value() << endl;
    cout << C[p.value()] << endl;
    return 0;
}
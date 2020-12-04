#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1777777777;
const ll INF = (ll) 1e15;

ll modpow(ll n, ll r) {
    ll ret = 1;
    ll p = n;
    while (r > 0) {
        if (r & 1)
            ret = (ret * p) % MOD;
        r /= 2;
        p = (p * p) % MOD;
    }
    return ret;
}

struct Combination {
    Combination(ll n) {
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
        if (n < r || n < 0)
            return 0;
        return (((mNumTbl[n] * mInverseNumTbl[r]) % MOD) * mInverseNumTbl[n - r]) % MOD;
    }

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

    vector<ll> mInverseNumTbl;
    vector<ll> mNumTbl;
};

ll P[1000005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    ll ans = 1;
    {
        ll p = 1;
        REP(i, K) {
            ans = (ans * ((N - i) % MOD)) % MOD;
            p = (p * (i + 1)) % MOD;
        }
        ans = ans * modpow(p, MOD - 2) % MOD;
    }

    {
        P[0] = 1;
        Combination cmb(K + 5);
        REP(i, K) {
            P[i + 1] = (P[i] * (i + 1)) % MOD;
        }
        ll p = P[K];
        REP(i, K) {
            ll t = cmb.get(K, i + 1) * P[K - (i + 1)] % MOD;
            if (i % 2 == 0)
                p = (MOD + p - t) % MOD;
            else
                p = (p + t) % MOD;
        }
        ans = (ans * p) % MOD;
    }
    cout << ans << endl;
    return 0;
}
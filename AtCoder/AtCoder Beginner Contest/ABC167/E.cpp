#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 998244353;
const ll INF = (ll) 1e15;

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

ll P[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, K;
    cin >> N >> M >> K;
    Combination cmb(N + 5);
    ll p = M;
    P[N - 1] = p;
    REP(i, N - 1) {
        p = (p * (M - 1)) % MOD;
        P[N - 2 - i] = p;
    }

    ll ans = 0;
    REP(i, K + 1) {
        p = (P[i] * cmb.get(N - 1, i)) % MOD;
        ans += p;
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}
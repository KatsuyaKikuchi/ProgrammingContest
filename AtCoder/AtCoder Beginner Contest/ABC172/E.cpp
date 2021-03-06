#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
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

ll P[500005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    Combination cmb(M + 5);
    ll ans = cmb.get(M, N);
    REP(i, N) {
        ans = (ans * (i + 1)) % MOD;
    }
    P[1] = P[0] = 1;
    REP(i, N + 2) {
        P[i + 1] = (P[i] * (i + 1)) % MOD;
    }

    ll b = ans;
    REP(i, N) {
        ll p = cmb.get(N, i + 1);
        p = (p * cmb.get(M - (i + 1), N - (i + 1))) % MOD;
        p = (p * P[N - (i + 1)]) % MOD;

        if (i % 2 == 0)
            b = (b + MOD - p) % MOD;
        else
            b = (b + p) % MOD;
    }

    ans = (ans * b) % MOD;
    cout << ans << endl;

    return 0;
}
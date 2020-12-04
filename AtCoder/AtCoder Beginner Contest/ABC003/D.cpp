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

ll calcCmb(ll S, ll D, ll L, Combination &cmb) {
    return cmb.get(S, D) * cmb.get(S - D, L) % MOD;
}

ll calc(ll X, ll Y, ll D, ll L) {
    Combination cmb(X * Y + 5);
    ll ret = calcCmb(X * Y, D, L, cmb);
    ret -= (2LL * calcCmb((X - 1) * Y, D, L, cmb) + 2LL * calcCmb(X * (Y - 1), D, L, cmb)) % MOD;
    ret = (ret + MOD) % MOD;
    ret += calcCmb((X - 2) * Y, D, L, cmb) + calcCmb(X * (Y - 2), D, L, cmb) +
           4LL * calcCmb((X - 1) * (Y - 1), D, L, cmb) % MOD;
    ret %= MOD;
    ret -= (2LL * calcCmb((X - 1) * (Y - 2), D, L, cmb) + 2LL * calcCmb((X - 2) * (Y - 1), D, L, cmb)) % MOD;
    ret = (ret + MOD) % MOD;

    ret += calcCmb(std::max(0LL, (X - 2)) * std::max(0LL, (Y - 2)), D, L, cmb);
    return ret % MOD;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll R, C, X, Y, D, L;
    cin >> R >> C >> X >> Y >> D >> L;

    ll p = calc(X, Y, D, L);
    ll ans = 0;
    REP(h, R) {
        if (h + X > R)
            break;
        REP(w, C) {
            if (w + Y > C)
                break;
            ans = (ans + p) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
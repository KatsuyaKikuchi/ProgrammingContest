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
        if (n < r || n < 0 || r < 0)
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

ll dp[3005][3005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    Combination cmb(C * D + 5);
    memset(dp, 0, sizeof(dp));
    dp[A][B] = 1;
    FOR(i, C, A) {
        dp[i + 1][B] = dp[i][B] * cmb.get(B, 1LL) % MOD;
    }
    FOR(i, D, B) {
        dp[A][i + 1] = dp[A][i] * cmb.get(A, 1LL) % MOD;
    }
    FOR(i, C, A) {
        FOR(j, D, B) {
            //! (i+1,j+1)に塗らない
            ll x = (MOD + dp[i][j + 1] - (dp[i][j] * i) % MOD) % MOD;
            ll y = (MOD + dp[i + 1][j] - (dp[i][j] * j) % MOD) % MOD;
            ll p = (x * j + y * i + dp[i][j] * i * j) % MOD;
            dp[i + 1][j + 1] += p;
            //! (i+1,j+1)に塗る
            dp[i + 1][j + 1] += (MOD + dp[i + 1][j] + dp[i][j + 1]) % MOD;
            dp[i + 1][j + 1] %= MOD;

        }
    }

#if false
    for (ll i = C - 1; i >= 0; --i) {
        REP(j, D) {
            cout << dp[i + 1][j + 1] << " ";
        }
        cout << endl;
    }
#endif

    cout << dp[C][D] << endl;

    return 0;
}
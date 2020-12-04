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

ll P[1005][1005];
ll dp[1005][1005];

int main() {
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    Combination cmb(N + 5);

    memset(P, 0, sizeof(P));
    for (ll i = A; i <= B; ++i) {
        P[i][0] = 1;
        for (ll j = 1; j <= D; ++j) {
            if (i * j > N)
                break;
            P[i][j] = ((P[i][j - 1] * cmb.get(i * j, i) % MOD) * cmb.modpow(j)) % MOD;
        }
    }

    memset(dp, 0, sizeof(dp));
    dp[A - 1][0] = 1;
    for (ll i = A; i <= B; ++i) {
        for (ll j = N; j >= 0; --j) {
            dp[i][j] = dp[i - 1][j];
            for (ll n = C; n <= D; ++n) {
                ll m = j - i * n;
                if (m < 0)
                    break;
                dp[i][j] += ((dp[i - 1][m] * cmb.get(N - m, i * n)) % MOD) * P[i][n];
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[B][N] << endl;
    return 0;
}
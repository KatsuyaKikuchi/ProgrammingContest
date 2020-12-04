#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 998244353;
const ll INF = (ll) 1e15;

pll A[300005];

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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;
    Combination cmb(N + 10);
    vector<ll> X;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
        X.push_back(A[i].first);
        X.push_back(A[i].second);
    }
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    REP(i, N) {
        A[i].first = lower_bound(X.begin(), X.end(), A[i].first) - X.begin();
        A[i].second = lower_bound(X.begin(), X.end(), A[i].second) - X.begin();
    }
    sort(A, A + N, [](pll a, pll b) { return a.first < b.first; });
    vector<ll> S(X.size() + 5, 0);
    ll ans = 0;
    ll last = 0;
    REP(i, N) {
        ll a = A[i].first;
        ll b = A[i].second + 1;
        while (last < a) {
            S[last + 1] += S[last];
            last++;
        }
        ans += cmb.get(S[a], K - 1);
        ans %= MOD;
        //cout << ans << endl;
        S[a]++;
        S[b]--;
    }
    cout << ans << endl;
    return 0;
}
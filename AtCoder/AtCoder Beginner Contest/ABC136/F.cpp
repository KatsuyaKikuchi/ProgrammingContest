#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 998244353;
const ll INF = (ll) 1e15;

pll X[200005];
ll P[200005];

struct BinaryIndexTree {
    BinaryIndexTree(int n)
            : mN(n) {
        mPow = 1;
        while (mPow < n)
            mPow <<= 1;
        node.resize(n + 1);
        REP(i, n + 1) {
            node[i] = 0;
        }
    }

    ~BinaryIndexTree() {
        node.resize(0);
    }

    //! 1-index get
    ll sum(int index) {
        ll sum = 0;
        for (int i = index; i > 0; i -= i & (-i))
            sum += node[i];
        return sum;
    }

    //! 1-index add
    void add(int index, ll value) {
        for (int i = index; i <= mN; i += i & (-i))
            node[i] += value;
    }

    int lowerBound(ll value) {
        if (value <= 0)
            return 0;
        int x = 0;
        for (int k = mPow; k > 0; k >>= 1) {
            if (x + k <= mN && node[x + k] < value) {
                value -= node[x + k];
                x += k;
            }
        }
        return x + 1;
    }

    vector<ll> node;
    ll mN;
    ll mPow;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> X[i].first >> X[i].second;
    }
    sort(X, X + N, [](pll a, pll b) { return a.first < b.first; });
    vector<ll> y;
    REP(i, N) {
        y.push_back(X[i].second);
    }
    sort(y.begin(), y.end());
    P[0] = 1;
    REP(i, N) {
        P[i + 1] = (P[i] * 2LL) % MOD;
    }

    ll ans = 0;
    BinaryIndexTree bit(N + 5);
    REP(i, N) {
        ll yi = lower_bound(y.begin(), y.end(), X[i].second) - y.begin();
        ll ld = bit.sum(yi);
        ll lt = i - ld;
        ll rd = yi - ld;
        ll rt = N - 1 - (ld + lt + rd);
        bit.add(yi + 1, 1);

        ll t[4] = {ld, lt, rt, rd};

        ans += P[N - 1] + (P[N - 1] - 1);
        REP(j, 4) {
            ll m = P[t[j] + t[(j + 1) % 4]] - 1 - (P[t[j]] - 1);
            ans = (ans + MOD - (m % MOD)) % MOD;
        }
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}
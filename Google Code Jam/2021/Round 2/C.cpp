#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = (ll) 1e6 + 10;

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

Combination cmb(100005);

void dfs(ll idx, vector<vector<ll>> &graph, vector<ll> &count) {
    count[idx] = 1;
    for (auto &nxt:graph[idx]) {
        dfs(nxt, graph, count);
        count[idx] += count[nxt];
    }
}

ll dfs2(ll idx, vector<vector<ll>> &graph, vector<ll> &count, ll size) {
    ll ret = cmb.get(size, count[idx]);
    size = count[idx] - 1;
    for (auto &nxt:graph[idx]) {
        ret = (ret * dfs2(nxt, graph, count, size)) % MOD;
        size -= count[nxt];
    }
    return ret;
}

ll solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    if (A[0] != 1)
        return 0;
    REP(i, N - 1) {
        if (A[i + 1] > A[i] + 1)
            return 0;
    }
    stack<ll> stk;
    vector<ll> P(N, -1);
    stk.push(0);
    FOR(i, N, 1) {
        while (A[i] < stk.size()) {
            stk.pop();
        }
        ll idx = stk.top();
        if (stk.size() == A[i]) {
            stk.pop();
            P[i] = P[idx];
            P[idx] = i;
        }
        else {
            P[i] = idx;
        }
        stk.push(i);
    }
    vector<vector<ll>> V(N);
    REP(i, N) {
        if (P[i] < 0)
            continue;
        V[P[i]].push_back(i);
    }

    ll p = -1;
    REP(i, N) {
        if (P[i] != -1)
            continue;
        if (p >= 0)
            return 0;
        p = i;
    }
    if (p < 0)
        return 0;

    vector<ll> child(N, 0);
    dfs(p, V, child);
    return dfs2(p, V, child, N);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll T;
    cin >> T;
    REP(i, T) {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }
    return 0;
}
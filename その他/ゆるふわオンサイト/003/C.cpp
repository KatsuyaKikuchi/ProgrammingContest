#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct LowestCommonAncestor {

    LowestCommonAncestor(int N, int root = 0)
            : mVertexNum(N),
              mRoot(root) {
        init();
    }

    void init() {
        for (int i = 0; i < static_cast<int>(mGraph.size()); ++i) {
            mGraph[i].clear();
        }
        mGraph.clear();
        for (int i = 0; i < static_cast<int>(mParent.size()); ++i) {
            mParent[i].clear();
        }
        mParent.clear();
        mDepth.clear();

        mGraph.resize(mVertexNum);
        mParent.resize(MAX_LOG_V, vector<int>(mVertexNum));
        mDepth.resize(mVertexNum);
        mMul.resize(mVertexNum);
    }

    void addEdge(int a, int b, ll cost = 1) {
        mGraph[a].push_back(pll(b, cost));
        mGraph[b].push_back(pll(a, cost));
    }

    void construct() {
        dfs(mRoot, -1, 0, 1);
        for (int k = 0; k + 1 < MAX_LOG_V; ++k) {
            for (int i = 0; i < mVertexNum; ++i) {
                if (mParent[k][i] < 0)
                    mParent[k + 1][i] = -1;
                else
                    mParent[k + 1][i] = mParent[k][mParent[k][i]];
            }
        }
    }

    int lca(int a, int b) {
        if (mDepth[a] > mDepth[b])
            swap(a, b);
        for (int k = 0; k < MAX_LOG_V; ++k) {
            if ((mDepth[b] - mDepth[a]) >> k & 1)
                b = mParent[k][b];;
        }
        if (a == b)
            return a;
        for (int k = MAX_LOG_V - 1; k >= 0; --k) {
            if (mParent[k][a] != mParent[k][b]) {
                a = mParent[k][a];
                b = mParent[k][b];
            }
        }
        return mParent[0][a];
    }

    void dfs(int v, int p, int d, ll m) {
        mParent[0][v] = p;
        mDepth[v] = d;
        mMul[v] = m;
        for (int i = 0; i < static_cast<int>(mGraph[v].size()); ++i) {
            int n = mGraph[v][i].first;
            if (n == p)
                continue;
            ll cost = mGraph[v][i].second;
            dfs(n, v, d + 1, (m * cost) % MOD);
        }
    }

    int length(int a, int b) {
        int p = lca(a, b);
        return mDepth[a] + mDepth[b] - 2 * mDepth[p];
    }

    ll mul(int a, int b) {
        int p = lca(a, b);

        ll mul = modpow(mMul[p]);
        ll ma = (mMul[a] * mul) % MOD;
        ll mb = (mMul[b] * mul) % MOD;
        return ma * mb % MOD;
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

    vector<vector<pll>> mGraph;
    vector<vector<int>> mParent;
    vector<int> mDepth;
    vector<ll> mMul;
    int mVertexNum;
    int mRoot;
    const int MAX_LOG_V = 50;
};

int main() {
    ll N;
    cin >> N;
    LowestCommonAncestor lca(N);
    REP(i, N - 1) {
        ll u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        lca.addEdge(u, v, c);
    }
    lca.construct();
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll m, p, x;
        cin >> m >> p >> x;
        m--;
        p--;
        cout << (lca.mul(m, p) * x) % MOD << endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

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
    }

    void addEdge(int a, int b) {
        mGraph[a].push_back(b);
        mGraph[b].push_back(a);
    }

    void construct() {
        //! 根付き木に変換
        dfs(mRoot, -1, 0);
        //! 2^k回辿った親をキャッシュ
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
        //! aとbの深さが同じになるまで親をたどる
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

    void dfs(int v, int p, int d) {
        mParent[0][v] = p;
        mDepth[v] = d;
        for (int i = 0; i < static_cast<int>(mGraph[v].size()); ++i) {
            int n = mGraph[v][i];
            if (n == p)
                continue;
            dfs(n, v, d + 1);
        }
    }

    int length(int a, int b) {
        int p = lca(a, b);
        return mDepth[a] + mDepth[b] - 2 * mDepth[p];
    }

    vector<vector<int>> mGraph;
    vector<vector<int>> mParent;
    vector<int> mDepth;
    int mVertexNum;
    int mRoot;
    const int MAX_LOG_V = 50;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> tmp;
    REP(i, N) {
        cin >> A[i];
        tmp.push_back(A[i]);
    }
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    vector<ll> cnt(tmp.size(), 0);
    REP(i, N) {
        A[i] = lower_bound(tmp.begin(), tmp.end(), A[i]) - tmp.begin();
        cnt[A[i]]++;
    }
    LowestCommonAncestor tree(N);
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        tree.addEdge(a, b);
    }
    tree.construct();
    REP(i, cnt.size()) {
        if (cnt[i] >= 3) {
            cout << 0 << endl;
            return 0;
        }
    }

    vector<ll> T(N, 0);
    vector<ll> X(tmp.size(), -1);
    vector<ll> Y(N, false);
    REP(i, N) {
        if (X[A[i]] < 0) {
            X[A[i]] = i;
            continue;
        }

        ll a = i, b = X[A[i]];
        ll v = tree.lca(a, b);
        T[0]--;
        if (a != v && b != v) {
            T[v]++;
            T[a]--;
            T[b]--;
        }
        else if (v == a) {
            T[a]++;
            T[b]--;
        }
        else {
            T[b]++;
            T[a]--;
        }
        Y[a] = true;
        Y[b] = true;
    }

    ll ans = 0;
    queue<pll> q;
    q.push(pll(0, 0));
    vector<bool> seen(N, false);
    while (!q.empty()) {
        pll t = q.front();
        q.pop();
        seen[t.first] = true;
        ll cst = t.second + T[t.first];
        if (cst >= 0 && !Y[t.first])
            ans++;
        REP(i, tree.mGraph[t.first].size()) {
            ll nxt = tree.mGraph[t.first][i];
            if (seen[nxt])
                continue;
            q.push(pll(nxt, cst));
        }
    }

    cout << ans << endl;
    return 0;
}
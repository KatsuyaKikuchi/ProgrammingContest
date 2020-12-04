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
    ll N;
    cin >> N;
    LowestCommonAncestor lca(N);
    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        lca.addEdge(a, b);
    }
    lca.construct();

    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll a, b, x, y, k;
        cin >> x >> y >> a >> b >> k;
        a--;
        b--;
        x--;
        y--;

        {
            ll l = lca.length(a, b);
            if (l <= k && (k - l) % 2 == 0) {
                cout << "YES" << endl;
                continue;
            }
        }

        ll xy = lca.length(x, y);
        if (xy % 2 == 0) {
            xy++;
            //! 奇数の閉路がある
            ll m0 = std::min(lca.length(a, x), lca.length(a, y));
            ll m1 = std::min(lca.length(b, x), lca.length(b, y));
            ll l = m0 + m1 + 1;
            if (l <= k && (k - l) % 2 == 0) {
                cout << "YES" << endl;
                continue;
            }

            {
                ll p = lca.lca(lca.lca(x, y), a);
                ll length = lca.length(a, p) + lca.length(p, b) + xy;
                if (length <= k && (k - length) % 2 == 0) {
                    cout << "YES" << endl;
                    continue;
                }
            }
            {
                ll p = lca.lca(lca.lca(x, y), b);
                ll length = lca.length(a, p) + lca.length(b, p) + xy;
                if (length <= k && (k - length) % 2 == 0) {
                    cout << "YES" << endl;
                    continue;
                }
            }
            {
                ll length = lca.length(a, x) + lca.length(b, x) + xy;
                if (length <= k && (k - length) % 2 == 0) {
                    cout << "YES" << endl;
                    continue;
                }
            }
            {
                ll length = lca.length(a, y) + lca.length(b, y) + xy;
                if (length <= k && (k - length) % 2 == 0) {
                    cout << "YES" << endl;
                    continue;
                }
            }
        }
        cout << "NO" << endl;
    }
    return 0;
}
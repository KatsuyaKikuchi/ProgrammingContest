#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct RootedTree {
    RootedTree(int n, int root = 0) :
            mRoot(root) {
        mVertexTbl.resize(n);
    }

    void addEdge(int a, int b, long long int cost = 1) {
        mVertexTbl[a].child.push_back(pair<int, long long int>(b, cost));
        mVertexTbl[b].child.push_back(pair<int, long long int>(a, cost));
    }

    void build() {
        queue<tuple<int, int, long long int>> q;
        q.push(make_tuple(mRoot, -1, 0));
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int index = get<0>(t);
            int parent = get<1>(t);
            long long int depth = get<2>(t);
            mVertexTbl[index].parent = parent;
            mVertexTbl[index].depth = depth;
            for (auto it = mVertexTbl[index].child.begin(); it != mVertexTbl[index].child.end();) {
                int nxt = (*it).first;
                if (nxt == parent) {
                    mVertexTbl[index].child.erase(it);
                    continue;
                }
                q.push(make_tuple(nxt, index, depth + (*it).second));
                ++it;
            }
        }
        dfs(mRoot);
        mVertexTbl[mRoot].value = 0;//! =identity
        solve(mRoot);
    }

    void dfs(int index) {
        int value = 0; //! = identity

        for (int i = 0; i < mVertexTbl[index].child.size(); ++i) {
            int cld = mVertexTbl[index].child[i].first;
            dfs(cld);
            value += mVertexTbl[cld].value;//! merge
        }
        mVertexTbl[index].value = value + 1;
    }

    void solve(int index) {
        int value = mVertexTbl[index].value + 1;//! identity
        vector<int> dp(mVertexTbl[index].child.size() + 1, 0);//! =identity

        for (int i = 0; i < mVertexTbl[index].child.size(); ++i) {
            int cld = mVertexTbl[index].child[i].first;
            mVertexTbl[index].value = std::max(mVertexTbl[index].value, mVertexTbl[cld].value);
            dp[i + 1] = mVertexTbl[cld].value + dp[i];//! merge
        }


        for (int i = mVertexTbl[index].child.size() - 1; i >= 0; --i) {
            int cld = mVertexTbl[index].child[i].first;

            int childValue = mVertexTbl[cld].value;
            mVertexTbl[cld].value = value + dp[i];//! merge
            solve(cld);
            value = value + childValue;//! merge
        }
    }

    struct Vertex {
        vector<pair<int, long long int>> child;
        long long int depth = 0;
        int parent = -1;
        int value = 0;//! 抽象化したい
    };

    int mRoot;
    vector<Vertex> mVertexTbl;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    RootedTree tree(N);
    REP(i, N - 1) {
        ll p;
        cin >> p;
        tree.addEdge(p, i + 1);
    }

    tree.build();

    REP(i, N) {
        cout << tree.mVertexTbl[i].value << endl;
    }
    return 0;
}
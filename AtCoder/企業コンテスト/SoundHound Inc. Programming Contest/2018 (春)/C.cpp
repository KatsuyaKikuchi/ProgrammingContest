#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Flow {
    explicit Flow(int n) {
        mVertices.resize(n);
        mDir.assign(n, 0);
        mIter.assign(n, 0);
    }

    void addEdge(int from, int to, long long int cap) {
        mVertices[from].edge.emplace_back(Edge{to, cap, static_cast<int>(mVertices[to].edge.size())});
        mVertices[to].edge.emplace_back(Edge{from, 0, static_cast<int>(mVertices[from].edge.size())});
    }

    long long int maxFlow(int s, int t) {
        long long int retValue = 0;
        while (true) {
            bfs(s);
            if (mDir[t] == MAX_VALUE)
                break;
            fill(mIter.begin(), mIter.end(), 0);
            long long int flow = 0;
            while ((flow = dfs(s, t, INF_VALUE)) > 0)
                retValue += flow;
        }
        return retValue;
    }

    void bfs(int s) {
        fill(mDir.begin(), mDir.end(), MAX_VALUE);
        queue<int> q;
        q.push(s);
        mDir[s] = 0;
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            int cost = mDir[t] + 1;
            for (const auto &e:mVertices[t].edge) {
                if (mDir[e.to] <= cost || e.capacity <= 0)
                    continue;
                mDir[e.to] = cost;
                q.push(e.to);
            }
        }
    }

    long long int dfs(int s, int t, long long int f) {
        if (s == t)
            return f;
        for (int &i = mIter[s]; i < mVertices[s].edge.size(); ++i) {
            Edge &e = mVertices[s].edge[i];
            if (e.capacity <= 0 || mDir[s] >= mDir[e.to])
                continue;
            long long int d = dfs(e.to, t, std::min(f, e.capacity));
            if (d > 0) {
                e.capacity -= d;
                mVertices[e.to].edge[e.rev].capacity += d;
                return d;
            }
        }
        return 0;
    }

    struct Edge {
        int to;
        long long int capacity;
        int rev;
    };
    struct Vertex {
        vector<Edge> edge;
    };
    vector<Vertex> mVertices;
    vector<int> mDir;
    vector<int> mIter;

    const int MAX_VALUE = 1e9;
    long long int INF_VALUE = (long long int) 1e15;
};

ll R, C;
string S[50];
bool U[50][50];

ll calc(ll h, ll w) {

}

int main() {
    cin >> R >> C;
    REP(i, R) {
        cin >> S[i];
    }

    memset(U, 0, sizeof(U));
    ll ans = 0;
    REP(i, R) {
        REP(j, C) {
            if (U[i][j])
                continue;
            ans += calc(i, j);
        }
    }
    cout << ans << endl;
    return 0;
}
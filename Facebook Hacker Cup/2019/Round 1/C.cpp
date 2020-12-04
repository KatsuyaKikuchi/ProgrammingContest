#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

//#define DEBUG 1
#ifdef DEBUG
#define OUT cout
#define IN cin
#else
#define OUT ws
#define IN rs
#endif

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

struct Data {
    ll x, a, b;
};

ll solve(std::ifstream &rs) {
    ll N, H;
    IN >> N >> H;
    vector<Data> D(N);
    REP(i, N) {
        IN >> D[i].x >> D[i].a >> D[i].b;
    }
    REP(i, N) {
        if (D[i].a == 0 && D[i].b == H)
            return -1;
    }
    sort(D.begin(), D.end(), [](Data a, Data b) { return a.x < b.x; });
    Flow f(N + 2);
    REP(i, N) {
        vector<pll> v;
        FOR(j, N, i + 1) {
            ll under = std::max(D[i].a, D[j].a);
            ll top = std::min(D[i].b, D[j].b);
            if (under > top)
                continue;
            if (under == top) {
                f.addEdge(i, j, 0);
                f.addEdge(j, i, 0);
                continue;
            }

            stack<pll> s;
            s.push(pll(under, top));

            while (true) {
                bool update = false;
                stack<pll> ts;

                while (!s.empty()) {
                    pll t = s.top();
                    s.pop();
                    bool u = false;
                    for (auto &p:v) {
                        ll len = std::min(p.second, t.second) - std::max(p.first, t.first);
                        if (len <= 0)
                            continue;
                        update = true;
                        if (p.second < t.second) {
                            ts.push(pll(p.second, t.second));
                        }
                        if (p.first > t.first) {
                            ts.push(pll(t.first, p.first));
                        }
                        u = true;
                        break;
                    }
                    if (!u)
                        ts.push(t);
                }

                swap(ts, s);
                if (!update)
                    break;
            }

            while (!s.empty()) {
                pll t = s.top();
                s.pop();
                v.push_back(t);
                ll len = t.second - t.first;
                f.addEdge(i, j, len);
                f.addEdge(j, i, len);
            }
        }
    }
    REP(i, N) {
        if (D[i].a == 0)
            f.addEdge(N, i, INF);
        if (D[i].b == H)
            f.addEdge(i, N + 1, INF);
    }

    return f.maxFlow(N, N + 1);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin.tie(0);
    ios::sync_with_stdio(false);

    std::string rFile = "../Facebook Hacker Cup/2019/Round 1/C.txt";
    std::ifstream rs;
    rs.open(rFile, std::ios::in);

    string wFile = "../Facebook Hacker Cup/2019/Round 1/C_ans.txt";
    std::ofstream ws;
    ws.open(wFile, std::ios::out);

    ll Q;
    IN >> Q;
    REP(i, Q) {
        OUT << "Case #" << i + 1 << ": " << solve(rs) << endl;
    }
    return 0;
}
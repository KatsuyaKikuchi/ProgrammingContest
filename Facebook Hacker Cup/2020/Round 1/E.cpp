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
    }

    struct Vertex {
        vector<pair<int, long long int>> child;
        long long int depth = 0;
        long long int count = 0;
        int num = 0;
        int childNum = 1;
        int parent = -1;
    };

    int mRoot;
    vector<Vertex> mVertexTbl;
};

void solve(std::ifstream &rs, std::ofstream &ws) {
    ll N, K;
    IN >> N >> K;
    string S;
    IN >> S;
    vector<ll> E(N);
    E[0] = -1;
    REP(i, K) {
        IN >> E[i + 1];
    }
    ll a, b, c;
    IN >> a >> b >> c;
    FOR(i, N, K) {
        E[i + 1] = (a * E[i - 1] + b * E[i] + c) % (i + 1) + 1;
    }

    RootedTree tree(N);
    FOR(i, N, 1) {
        tree.addEdge(i, E[i] - 1);
    }
    tree.build();

    vector<pll> v;
    queue<ll> q;
    REP(i, N) {
        if (tree.mVertexTbl[i].child.size() == 0)
            q.push(i);
    }

    while (!q.empty()) {
        ll t = q.front();
        q.pop();
        ll cnt = tree.mVertexTbl[t].count + 1;
        if (S[t] == '#')
            cnt = 0;

        ll p = tree.mVertexTbl[t].parent;
        if (p >= 0) {
            tree.mVertexTbl[p].count += cnt;
            tree.mVertexTbl[p].num++;
            tree.mVertexTbl[p].childNum += tree.mVertexTbl[t].childNum;
            if (tree.mVertexTbl[p].num == tree.mVertexTbl[p].child.size()) {
                q.push(p);
            }
        }

        if (S[t] == '*' && (p < 0 || S[p] == '#'))
            v.push_back(pll(t, cnt));
    }

#if false
    REP(i, v.size()) {
        cout << v[i].first << " " << v[i].second << endl;
    }
    cout << "ans" << endl;
    cout << "------------------------" << endl;
    REP(i, v.size()) {
        cout << v[i].second << endl;
    }
    cout << endl;
#endif

    if (v.size() == 0) {
        ll count = 0;
        REP(i, N) {
            if (tree.mVertexTbl[i].parent < 0)
                continue;
            ll n = tree.mVertexTbl[i].childNum;
            count += n * (N - n);
        }

        OUT << 0 << " " << count << endl;
        return;
    }
    if (v.size() == 1) {
        ll pn = v[0].second;
        ll count = 0;
        pn = pn * (pn - 1) / 2;

        queue<ll> q0;
        q0.push(v[0].first);
        while (!q0.empty()) {
            ll t = q0.front();
            q0.pop();
            ll p = tree.mVertexTbl[t].parent;
            if (p >= 0 && S[p] == '#') {
                //ll n = tree.mVertexTbl[t].childNum;
                // count += n * (N - n);
            }
            REP(i, tree.mVertexTbl[t].child.size()) {
                ll cld = tree.mVertexTbl[t].child[i].first;
                if (S[cld] == '*') {
                    q0.push(cld);
                    tree.mVertexTbl[t].num--;
                    continue;
                }

                // ll n = tree.mVertexTbl[cld].childNum;
                // count += n * (N - n);
            }
        }

        queue<ll> q2;
        REP(i, N) {
            if (S[i] == '#')
                continue;
            if (tree.mVertexTbl[i].num == tree.mVertexTbl[i].child.size())
                q2.push(i);
            tree.mVertexTbl[i].childNum = 1;
        }

        while (!q2.empty()) {
            ll t = q2.front();
            q2.pop();
            ll p = tree.mVertexTbl[t].parent;
            if (p < 0 || S[p] == '#')
                continue;

            tree.mVertexTbl[p].num++;
            tree.mVertexTbl[p].childNum += tree.mVertexTbl[t].childNum;
            if (tree.mVertexTbl[p].num == tree.mVertexTbl[p].child.size())
                q2.push(p);

            ll n = tree.mVertexTbl[t].childNum;
            count += n * (v[0].second - n);
        }


        REP(i, N) {
            ll p = tree.mVertexTbl[i].parent;
            if (p < 0)
                continue;
            if (S[p] == '*' && S[i] == '*')
                continue;
            ll x = tree.mVertexTbl[i].childNum;
            count += x * (N - x);
        }
        OUT << pn << " " << count << endl;
        return;
    }

    if (v[0].second == v[1].second) {
        vector<pll> v0;
        REP(i, v.size()) {
            if (v[i].second == v[0].second)
                v0.push_back(v[i]);
        }
        ll p = v[0].second * v[0].second;
        REP(i, v.size()) {
            p += v[i].second * (v[i].second - 1) / 2;
        }
        ll num = 0;
        REP(i, v0.size()) {
            num += v[0].second * v[0].second * (v0.size() - 1);
        }
#if false
        FOR(i, v.size(), 2) {
            ll x = v[i].second;
            p += x * (x - 1) / 2;
        }
#endif

        OUT << p << " " << num << endl;
        return;
    }

    {
        vector<pll> v0;
        REP(i, v.size()) {
            if (v[i].second == v[1].second)
                v0.push_back(v[i]);
        }
#if false
        ll p = v[0].second + v[1].second;
        p = p * (p - 1) / 2;
#endif
        ll num = v[0].second * v[1].second * v0.size();
        REP(i, v0.size()) {
            num += v[0].second * v[1].second;
        }
#if false
        FOR(i, v.size(), 2) {
            ll x = v[i].second;
            p += x * (x - 1) / 2;
        }
#endif
        ll p = 0;
        REP(i, v.size()) {
            p += v[i].second * (v[i].second - 1) / 2;
        }
        p += v[0].second * v[1].second;
        OUT << p << " " << num << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    std::string rFile = "../Facebook Hacker Cup/2020/Round 1/E.txt";
    std::ifstream rs;
    rs.open(rFile, std::ios::in);

    string wFile = "../Facebook Hacker Cup/2020/Round 1/E_ans.txt";
    std::ofstream ws;
    ws.open(wFile, std::ios::out);

    ll Q;
    IN >> Q;
    REP(i, Q) {
        OUT << "Case #" << i + 1 << ": ";
        solve(rs, ws);
    }
    return 0;
}
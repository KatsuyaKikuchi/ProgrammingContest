#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Vertex {
    vector<ll> node;
};

Vertex V[100005];
struct Query {
    ll v, d, c;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }
    ll Q;
    cin >> Q;
    vector<Query> query(Q);
    REP(i, Q) {
        cin >> query[i].v >> query[i].d >> query[i].c;
        query[i].v--;
    }
    reverse(query.begin(), query.end());
    vector<ll> ans(N, -1);
    vector<ll> dist(N, -1);
    REP(i, Q) {
        ll v = query[i].v;
        if (dist[v] >= query[i].d)
            continue;
        dist[v] = query[i].d;
        queue<pll> q;
        q.push(pll(v, query[i].d));
        ll color = query[i].c;
        if (ans[v] < 0)
            ans[v] = color;
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            ll d = t.second - 1;
            if (d < 0)
                continue;
            for (auto &nxt:V[t.first].node) {
                if (dist[nxt] >= d)
                    continue;
                dist[nxt] = d;
                if (ans[nxt] < 0)
                    ans[nxt] = color;
                q.push(pll(nxt, d));
            }
        }
    }
    REP(i, N) {
        if (ans[i] < 0)
            cout << 0 << endl;
        else
            cout << ans[i] << endl;
    }

    return 0;
}
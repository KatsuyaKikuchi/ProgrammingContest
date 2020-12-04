#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Vertex {
    vector<pll> node;
};
ll N, M;
Vertex V[100005];
bool U[100005];

bool solve() {
    ll mx = 0;
    REP(i, N) {
        if (V[i].node.size() % 2 == 1)
            return false;
        mx = std::max(static_cast<ll>(V[i].node.size()), mx);
    }

    if (mx == 2)
        return false;
    if (mx >= 6)
        return true;

    vector<ll> v;
    REP(i, N) {
        if (V[i].node.size() == 4)
            v.push_back(i);
    }

    if (v.size() > 2)
        return true;
    if (v.size() == 1)
        return false;

    REP(i, V[v[0]].node.size()) {
        if (V[v[0]].node[i].first == v[0])
            return true;

        queue<ll> q;
        memset(U, 0, sizeof(U));
        q.push(V[v[0]].node[i].first);
        U[V[v[0]].node[i].second] = true;
        while (!q.empty()) {
            ll t = q.front();
            q.pop();
            for (auto &n : V[t].node) {
                if (U[n.second])
                    continue;
                if (n.first == v[1])
                    continue;
                if (n.first == v[0])
                    return true;
                U[n.second] = true;
                q.push(n.first);
            }
        }
    }

    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.emplace_back(pll(b, i));
        V[b].node.emplace_back(pll(a, i));
    }

    if (solve())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
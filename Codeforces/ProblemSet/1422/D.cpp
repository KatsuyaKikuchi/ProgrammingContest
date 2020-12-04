#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;

struct Data {
    pll g;
    ll index;
};
struct Vertex {
    vector<pll> node;
};

Vertex V[100005];
ll A[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<Data> d(M + 1);
    ll s = M;
    pll g;
    cin >> d[s].g.first >> d[s].g.second >> g.first >> g.second;
    REP(i, M) {
        cin >> d[i].g.first >> d[i].g.second;
    }
    REP(i, d.size()) {
        d[i].index = i;
    }

    sort(d.begin(), d.end(), [](Data a, Data b) { return a.g.first < b.g.first; });
    REP(i, d.size() - 1) {
        ll a = d[i].index, b = d[i + 1].index;
        ll dist = abs(d[i].g.first - d[i + 1].g.first);
        V[a].node.push_back(pll(b, dist));
        V[b].node.push_back(pll(a, dist));
    }
    sort(d.begin(), d.end(), [](Data a, Data b) { return a.g.second < b.g.second; });
    REP(i, d.size() - 1) {
        ll a = d[i].index, b = d[i + 1].index;
        ll dist = abs(d[i].g.second - d[i + 1].g.second);
        V[a].node.push_back(pll(b, dist));
        V[b].node.push_back(pll(a, dist));
    }

    REP(i, d.size()) {
        A[i] = INF;
    }
    A[s] = 0;
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second > b.second; });
    q.push(pll(s, 0));
    while (!q.empty()) {
        pll t = q.top();
        q.pop();
        if (A[t.first] < t.second)
            continue;
        for (auto &n:V[t.first].node) {
            ll nxt = n.first;
            ll cost = n.second + t.second;
            if (A[nxt] <= cost)
                continue;
            A[nxt] = cost;
            q.push(pll(nxt, cost));
        }
    }

    ll ans = INF;
    REP(i, d.size()) {
        ll index = d[i].index;
        ans = std::min(ans, abs(d[i].g.first - g.first) + abs(d[i].g.second - g.second) + A[index]);
    }

    cout << ans << endl;

    return 0;
}
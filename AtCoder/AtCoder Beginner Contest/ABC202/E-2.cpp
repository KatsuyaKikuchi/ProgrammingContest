#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

vector<vector<ll>> V;
vector<vector<ll>> D;
vector<pll> T;

ll dfs(ll idx, ll depth, ll time) {
    pll t(time, INF);
    time++;
    for (auto &nxt:V[idx]) {
        time = dfs(nxt, depth + 1, time);
    }
    t.second = time;
    D[depth].push_back(t.first);
    T[idx] = t;
    return time + 1;
}

ll solve(ll u, ll d) {
    auto &depth = D[d];
    pll time = T[u];
    ll start = lower_bound(depth.begin(), depth.end(), time.first) - depth.begin();
    ll end = lower_bound(depth.begin(), depth.end(), time.second) - depth.begin();
    return std::max(0LL, end - start);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    V.resize(N);
    REP(i, N - 1) {
        ll p;
        cin >> p;
        p--;
        V[p].push_back(i + 1);
    }
    D.resize(N);
    T.resize(N);
    dfs(0, 0, 0);
    REP(i, N) {
        sort(D[i].begin(), D[i].end(), [](ll a, ll b) { return a < b; });
    }
    ll Q;
    cin >> Q;
    REP(i, Q) {
        ll u, d;
        cin >> u >> d;
        u--;
        cout << solve(u, d) << endl;
    }

    return 0;
}
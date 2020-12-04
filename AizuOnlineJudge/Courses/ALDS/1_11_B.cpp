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
    vector<ll> node;
};

ll N;
Vertex V[105];
pll ans[105];

void dfs(ll idx, ll &time) {
    ans[idx].first = time++;
    for (auto &nxt:V[idx].node) {
        if (ans[nxt].first > 0)
            continue;
        dfs(nxt, time);
    }
    ans[idx].second = time++;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N) {
        ll n, k;
        cin >> n >> k;
        n--;
        REP(j, k) {
            ll v;
            cin >> v;
            v--;
            V[n].node.push_back(v);
        }
    }
    REP(i, N) {
        ans[i] = pll(0, 0);
    }
    ll time = 1;
    REP(i, N) {
        if (ans[i].first > 0)
            continue;
        dfs(i, time);
    }
    REP(i, N) {
        cout << i + 1 << " " << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}
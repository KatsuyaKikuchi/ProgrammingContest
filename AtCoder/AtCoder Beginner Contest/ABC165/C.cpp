#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, M, Q;
struct Data {
    ll a, b, c, d;
};

Data D[55];

ll t = 0;

ll dfs(vector<ll> v) {
    t++;
    if (v.size() == N) {
        ll score = 0;
        REP(i, Q) {
            if (v[D[i].b] - v[D[i].a] == D[i].c)
                score += D[i].d;
        }
        return score;
    }
    ll m = 1;
    if (v.size() > 0)
        m = v[v.size() - 1];

    ll ret = 0;
    FOR(n, M + 1, m) {
        v.push_back(n);
        ret = std::max(ret, dfs(v));
        v.pop_back();
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> Q;
    REP(i, Q) {
        cin >> D[i].a >> D[i].b >> D[i].c >> D[i].d;
        D[i].a--;
        D[i].b--;
    }

    vector<ll> v;
    ll ans = dfs(v);
    cout << ans << endl;
    return 0;
}
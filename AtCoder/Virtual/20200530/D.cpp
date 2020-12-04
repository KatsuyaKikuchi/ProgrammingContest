#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    ll a, b, c, d;
};
ll N, M, Q;
Data D[55];

ll dfs(vector<ll> v) {
    if (v.size() == N) {
        ll sum = 0;
        REP(i, Q) {
            if (v[D[i].b] - v[D[i].a] == D[i].c)
                sum += D[i].d;
        }
        return sum;
    }

    ll s = 1;
    if (v.size() > 0)
        s = v.back();
    ll ret = 0;
    FOR(i, M + 1, s) {
        v.push_back(i);
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

    cout << dfs(vector<ll>()) << endl;
    return 0;
}
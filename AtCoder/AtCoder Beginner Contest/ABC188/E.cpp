#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];
struct Vertex {
    vector<ll> to, from;
    ll count = 0;
};

Vertex V[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].to.push_back(b);
        V[b].from.push_back(a);
    }
    ll ans = -INF;
    vector<ll> mn(N, INF);
    REP(i, N) {
        ans = std::max(ans, A[i] - mn[i]);
        mn[i] = std::min(mn[i], A[i]);
        REP(j, V[i].to.size()) {
            ll nxt = V[i].to[j];
            mn[nxt] = std::min(mn[nxt], mn[i]);
        }
    }


    cout << ans << endl;
    return 0;
}
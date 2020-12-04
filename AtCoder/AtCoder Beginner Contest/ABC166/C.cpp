#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll H[100005];
struct Vertex {
    vector<ll> node;
};

Vertex V[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> H[i];
    }
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    ll ans = 0;
    REP(i, N) {
        bool e = true;
        REP(j, V[i].node.size()) {
            ll n = V[i].node[j];
            if (H[n] >= H[i]) {
                e = false;
                break;
            }
        }
        if (e)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
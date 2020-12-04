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

Vertex V[205];
ll C[205];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, Q;
    cin >> N >> M >> Q;
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    REP(i, N) {
        cin >> C[i];
    }

    REP(_, Q) {
        ll q;
        cin >> q;
        if (q == 2) {
            ll x, y;
            cin >> x >> y;
            x--;
            cout << C[x] << endl;
            C[x] = y;
            continue;
        }

        ll x;
        cin >> x;
        x--;
        cout << C[x] << endl;
        for (auto &n:V[x].node) {
            C[n] = C[x];
        }
    }
    return 0;
}
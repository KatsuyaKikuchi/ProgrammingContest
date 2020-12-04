#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Edge {
    ll to;
    ll from;
    ll cost;
};
ll C[2505];
Edge E[5005];
bool U[2505];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, P;
    cin >> N >> M >> P;
    REP(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        E[i].from = a;
        E[i].to = b;
        E[i].cost = -(c - P);
    }

    REP(i, N) {
        C[i] = INF;
        U[i] = false;
    }
    C[0] = 0;
    U[N - 1] = true;

    REP(i, N + 5) {
        bool update = false;
        REP(j, M) {
            const auto &e = E[j];
            U[e.from] |= U[e.to];
            if (C[e.from] == INF)
                continue;
            ll cost = C[e.from] + e.cost;
            if (C[e.to] > cost) {
                C[e.to] = cost;
                update = true;
            }
        }
        if (!update)
            break;
    }

    bool inf = false;
    REP(i, M) {
        const auto &e = E[i];
        if (C[e.from] == INF)
            continue;
        ll cost = C[e.from] + e.cost;
        if (C[e.to] > cost && U[e.to])
            inf = true;
    }

    if (inf)
        cout << -1 << endl;
    else
        cout << std::max(0LL, -C[N - 1]) << endl;
    return 0;
}
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
    ll a;
    ll b;
    ll c;
};

Edge E[5005];
ll C[2505];
bool U[2505];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, P;
    cin >> N >> M >> P;
    REP(i, M) {
        cin >> E[i].a >> E[i].b >> E[i].c;
        E[i].a--;
        E[i].b--;
        E[i].c -= P;
        E[i].c *= -1;
    }
    REP(i, N) {
        C[i] = INF;
    }
    memset(U, 0, sizeof(U));
    C[0] = 0;
    U[N - 1] = true;

    REP(_, N + 5) {
        bool update = false;
        REP(i, M) {
            auto &e = E[i];
            if (U[e.b])
                U[e.a] = true;
            if (C[e.a] == INF)
                continue;
            ll cost = C[e.a] + e.c;
            if (C[e.b] <= cost)
                continue;
            update = true;
            C[e.b] = cost;
        }
        if (!update)
            break;
    }

    REP(i, M) {
        auto &e = E[i];
        if (C[e.a] == INF)
            continue;
        ll cost = C[e.a] + e.c;
        if (C[e.b] <= cost)
            continue;
        if (U[e.b]) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << std::max(0LL, -C[N - 1]) << endl;
    return 0;
}
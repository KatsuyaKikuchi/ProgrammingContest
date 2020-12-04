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

Edge E[5005];
ll C[2505];
bool U[2505];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, P;
    cin >> N >> M >> P;
    REP(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        E[i].to = b - 1;
        E[i].from = a - 1;
        E[i].cost = -(c - P);
    }

    REP(i, N) {
        C[i] = INF;
    }
    C[0] = 0;
    memset(U, 0, sizeof(U));
    queue<ll> q;
    q.push(N - 1);
    U[N - 1] = true;
    while (!q.empty()) {
        ll t = q.front();
        q.pop();
        REP(i, M) {
            if (E[i].to != t)
                continue;
            ll n = E[i].from;
            if (U[n])
                continue;
            U[n] = true;
            q.push(n);
        }
    }

    REP(_, N + 5) {
        bool update = false;
        REP(i, M) {
            const auto &e = E[i];
            if (C[e.from] == INF)
                continue;
            ll cost = C[e.from] + e.cost;
            if (C[e.to] > cost) {
                update = true;
                C[e.to] = cost;
            }
        }
        if (!update)
            break;
    }

    REP(i, M) {
        const auto &e = E[i];
        if (!U[e.to])
            continue;
        if (C[e.from] == INF)
            continue;
        ll cost = C[e.from] + e.cost;
        if (C[e.to] > cost) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << std::max(0LL, -C[N - 1]) << endl;
    return 0;
}
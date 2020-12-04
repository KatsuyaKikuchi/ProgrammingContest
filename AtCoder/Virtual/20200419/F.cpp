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
bool A[2505];
bool B[2505];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, P;
    cin >> N >> M >> P;
    REP(i, M) {
        cin >> E[i].from >> E[i].to >> E[i].cost;
        E[i].from--;
        E[i].to--;
        E[i].cost -= P;
    }
    REP(i, N) {
        C[i] = INF;
        A[i] = false;
        B[i] = false;
    }
    C[0] = 0;
    A[N - 1] = true;
    B[0] = true;

    REP(_, N + 5) {
        REP(i, M) {
            if (A[E[i].to])
                A[E[i].from] = true;
            if (B[E[i].from])
                B[E[i].to] = true;
        }
    }

    REP(_, N + 5) {
        bool update = false;
        REP(i, M) {
            ll c = C[E[i].from] - E[i].cost;
            if (c < C[E[i].to]) {
                update = true;
                C[E[i].to] = c;
            }
        }

        if (!update)
            break;
    }

    bool inf = false;
    REP(i, M) {
        ll c = C[E[i].from] - E[i].cost;
        if (c < C[E[i].to]) {
            if (A[E[i].to] && B[E[i].to]) {
                inf = true;
                break;
            }
        }
    }

    if (inf)
        cout << -1 << endl;
    else
        cout << std::max(0LL, -C[N - 1]) << endl;
    return 0;
}
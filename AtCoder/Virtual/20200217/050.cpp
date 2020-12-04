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
    ll a, b, c;
};

Edge E[2005];
ll S[1005];
ll U[1005];

int main() {
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        cin >> E[i].a >> E[i].b >> E[i].c;
        E[i].c *= -1;
        E[i].a--;
        E[i].b--;
    }

    memset(U, 0, sizeof(U));
    U[N - 1] = true;
    REP(i, N + 1) {
        REP(j, M) {
            ll a = E[j].a;
            ll b = E[j].b;
            if (U[b])
                U[a] = true;
        }
    }

    REP(i, N) {
        S[i] = INF;
    }
    S[0] = 0;
    REP(i, N + 1) {
        REP(j, M) {
            ll a = E[j].a;
            ll b = E[j].b;
            S[b] = std::min(S[b], S[a] + E[j].c);
        }
    }

    REP(i, M) {
        ll a = E[i].a;
        ll b = E[i].b;
        ll cost = E[i].c + S[a];
        if (S[b] > cost && U[b]) {
            cout << "inf" << endl;
            return 0;
        }
    }
    cout << -S[N - 1] << endl;
    return 0;
}
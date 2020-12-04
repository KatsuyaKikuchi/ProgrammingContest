#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(50)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    ll X;
    ll V;
    ll D;
};

Data D[2500];
double S[2500];

int main() {
    ll N, L;
    cin >> N >> L;
    cin >> D[0].V >> D[0].D;
    D[0].X = 0;
    REP(i, N) {
        cin >> D[i + 1].X >> D[i + 1].V >> D[i + 1].D;
    }
    D[N + 1].X = L;

    N = N + 2;
    sort(D, D + N, [](Data a, Data b) { return a.X < b.X; });
    REP(i, N) {
        S[i] = INF;
    }
    S[0] = 0;
    REP(i, N - 1) {
        ll x = D[i + 1].X;
        for (ll j = i; j >= 0; --j) {
            ll d = x - D[j].X;
            if (d > D[j].D)
                continue;
            S[i + 1] = std::min(S[i + 1], S[j] + (double) (d) / (double) (D[j].V));
        }
    }

    if (S[N - 1] == INF)
        cout << "impossible" << endl;
    else
        cout << OF64 << S[N - 1] << endl;
    return 0;
}
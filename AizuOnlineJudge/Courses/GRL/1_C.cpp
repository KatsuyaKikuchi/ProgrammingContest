#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[105][105];

int main() {
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        REP(j, N) {
            C[i][j] = INF;
        }
        C[i][i] = 0;
    }
    REP(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        C[a][b] = c;
    }

    REP(k, N) {
        REP(i, N) {
            REP(j, N) {
                if (C[i][k] == INF || C[k][j] == INF)
                    continue;
                C[i][j] = std::min(C[i][j], C[i][k] + C[k][j]);
            }
        }
    }

    bool cycle = false;
    REP(i, N) {
        if (C[i][i] < 0)
            cycle = true;
    }

    if (cycle)
        cout << "NEGATIVE CYCLE" << endl;
    else {
        REP(i, N) {
            REP(j, N) {
                if (C[i][j] == INF)
                    cout << "INF";
                else
                    cout << C[i][j];

                if (j < N - 1)
                    cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
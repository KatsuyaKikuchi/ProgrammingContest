#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, M;
ll L[405][405];
ll C[405][405];

void calc(ll start) {
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q(
            [](pll a, pll b) { return a.second > b.second; });
    q.push(pll(start, 0));
    while (!q.empty()) {
        pll t = q.top();
        q.pop();
        if (C[start][t.first] < t.second)
            continue;
        REP(i, N) {
            ll cost = L[t.first][i] + t.second;
            if (C[start][i] <= cost)
                continue;
            C[start][i] = cost;
            q.push(pll(i, cost));
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    REP(i, N) {
        REP(j, N) {
            L[i][j] = INF;
        }
        L[i][i] = 0;
    }
    REP(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        L[a][b] = L[b][a] = c;
    }
    REP(i, N) {
        REP(j, N) {
            C[i][j] = L[i][j];
        }
    }

    REP(k, N) {
        REP(i, N) {
            REP(j, N) {
                C[i][j] = std::min(C[i][j], C[i][k] + C[k][j]);
            }
        }
    }

    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        L[a][b] = L[b][a] = std::min(L[b][a], c);
        calc(a);
        calc(b);

        REP(i, N) {
            REP(j, N) {
                C[i][j] = std::min({C[i][j], C[i][a] + C[a][j], C[i][b] + C[b][j]});
            }
        }
#if false
        REP(i, N) {
            REP(j, N) {
                cout << C[i][j] << " ";
            }
            cout << endl;
        }
#endif
        ll sum = 0;
        REP(i, N) {
            FOR(j, N, i + 1) {
                sum += C[i][j];
            }
        }
        cout << sum << endl;
    }
    return 0;
}
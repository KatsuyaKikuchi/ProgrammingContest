#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

bool solve() {
    ll N, M;
    cin >> N >> M;
    vector<string> S(N);
    REP(i, N) {
        cin >> S[i];
    }
    REP(i, N) {
        REP(j, M) {
            if (S[i][j] != 'B')
                continue;

            REP(n, 4) {
                ll nx = x[n] + i, ny = y[n] + j;
                if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                    continue;
                if (S[nx][ny] == 'G')
                    return false;
                if (S[nx][ny] == '.')
                    S[nx][ny] = '#';
            }
        }
    }

    vector<vector<ll>> C(N, vector<ll>(M, INF));
    queue<pll> q;
    if (S[N - 1][M - 1] != '#') {
        C[N - 1][M - 1] = 0;
        q.push(pll(N - 1, M - 1));
    }
    while (!q.empty()) {
        pll t = q.front();
        q.pop();
        ll cost = C[t.first][t.second] + 1;
        REP(i, 4) {
            ll nx = x[i] + t.first, ny = y[i] + t.second;
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (S[nx][ny] == '#' || C[nx][ny] <= cost)
                continue;
            C[nx][ny] = cost;
            q.push(pll(nx, ny));
        }
    }

    REP(i, N) {
        REP(j, M) {
            if (S[i][j] == 'G' && C[i][j] == INF)
                return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        if (solve())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
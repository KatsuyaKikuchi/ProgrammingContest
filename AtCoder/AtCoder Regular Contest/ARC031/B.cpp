#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[15];
bool U[15][15];
ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

bool check() {
    memset(U, 0, sizeof(U));
    ll ret = 0;
    REP(i, 10) {
        REP(j, 10) {
            if (U[i][j])
                continue;
            if (S[i][j] == 'x')
                continue;
            ret++;
            U[i][j] = true;
            queue<pll> q;
            q.push(pll(i, j));
            while (!q.empty()) {
                pll t = q.front();
                q.pop();
                REP(k, 4) {
                    ll nx = x[k] + t.first, ny = y[k] + t.second;
                    if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10)
                        continue;
                    if (U[nx][ny] || S[nx][ny] == 'x')
                        continue;
                    U[nx][ny] = true;
                    q.push(pll(nx, ny));
                }
            }
        }
    }
    return ret <= 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    REP(i, 10) {
        cin >> S[i];
    }

    REP(i, 10) {
        REP(j, 10) {
            char c = S[i][j];
            S[i][j] = 'o';
            if (check()) {
                cout << "YES" << endl;
                return 0;
            }
            S[i][j] = c;
        }
    }
    cout << "NO" << endl;
    return 0;
}
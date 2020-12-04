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
ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};
bool U[15][15];

bool check(ll h, ll w) {
    memset(U, 0, sizeof(U));
    queue<pll> q;
    q.push(pll(h, w));
    U[h][w] = true;
    while (!q.empty()) {
        pll t = q.front();
        q.pop();
        REP(i, 4) {
            ll nx = t.first + x[i], ny = t.second + y[i];
            if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10)
                continue;
            if (S[nx][ny] == 'x')
                continue;
            if (U[nx][ny])
                continue;
            U[nx][ny] = true;
            q.push(pll(nx, ny));
        }
    }

    REP(i, 10) {
        REP(j, 10) {
            if (S[i][j] == 'o' && !U[i][j])
                return false;
        }
    }
    return true;
}

int main() {
    REP(i, 10) {
        cin >> S[i];
    }
    REP(i, 10) {
        REP(j, 10) {
            if (check(i, j)) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
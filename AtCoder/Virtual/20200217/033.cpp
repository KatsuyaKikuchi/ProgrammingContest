#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool X[20][20];
ll S[20][20];

int main() {
    ll H, W;
    cin >> H >> W;
    ll N;
    cin >> N;
    memset(X, 0, sizeof(X));
    REP(i, N) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        X[x][y] = true;
    }
    memset(S, 0, sizeof(S));
    S[0][0] = 1;
    REP(i, H) {
        REP(j, W) {
            if (X[i][j])
                continue;
            if (i - 1 >= 0)
                S[i][j] += S[i - 1][j];
            if (j - 1 >= 0)
                S[i][j] += S[i][j - 1];
        }
    }
    cout << S[H - 1][W - 1] << endl;
    return 0;
}
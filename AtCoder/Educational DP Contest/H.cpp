#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[1005];
ll x[2] = {0, 1};
ll y[2] = {1, 0};
ll A[1005][1005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    REP(i, H) {
        cin >> S[i];
    }
    A[0][0] = 1;
    REP(i, H) {
        REP(j, W) {
            if (S[i][j] == '#')
                continue;
            if (i > 0)
                A[i][j] += +A[i - 1][j];
            if (j > 0)
                A[i][j] += A[i][j - 1];
            A[i][j] %= MOD;
        }
    }

    cout << A[H - 1][W - 1] << endl;
    return 0;
}
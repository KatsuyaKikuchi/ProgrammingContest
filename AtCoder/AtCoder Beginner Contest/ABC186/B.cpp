#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[105][105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    ll s = 0;
    ll min = INF;
    REP(i, H) {
        REP(j, W) {
            cin >> A[i][j];
            s += A[i][j];
            min = std::min(min, A[i][j]);
        }
    }

    cout << s - min * H * W << endl;

    return 0;
}
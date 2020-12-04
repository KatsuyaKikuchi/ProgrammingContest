#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

char C[4] = {'N', 'S', 'E', 'W'};
ll x[4] = {0, 0, 1, -1};
ll y[4] = {1, -1, 0, 0};

void solve() {
    ll X, Y;
    string S;
    cin >> X >> Y >> S;
    ll N = S.length();
    ll ans = INF;
    if (X == 0 && Y == 0)
        ans = 0;
    REP(i, N) {
        REP(j, 4) {
            if (S[i] != C[j])
                continue;
            X += x[j];
            Y += y[j];
            break;
        }
        ll d = abs(X) + abs(Y);
        if (d <= i + 1)
            ans = std::min(ans, i + 1);
    }

    if (ans == INF)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(i, T) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}
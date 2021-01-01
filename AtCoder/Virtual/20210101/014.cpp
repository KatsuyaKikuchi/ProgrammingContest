#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll P[30], Q[30];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
    REP(i, N) {
        P[S[i] - 'A']++;
    }
    REP(i, M) {
        Q[T[i] - 'A']++;
    }
    ll ans = 0;
   // cout << ans << endl;
    REP(i, 30) {
        if (P[i] == Q[i]) {
            ans = std::max(ans, 1LL);
        }
        else if (Q[i] == 0) {
            ans = -1;
            break;
        }
        else {
            ans = std::max(ans, (P[i] + Q[i] - 1) / Q[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
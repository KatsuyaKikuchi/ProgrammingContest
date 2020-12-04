#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool U[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    ll R, S, P;
    cin >> N >> K >> R >> S >> P;
    string T;
    cin >> T;
    ll ans = 0;
    REP(i, N) {
        if (i - K >= 0 && T[i - K] == T[i] && U[i - K])
            continue;
        U[i] = true;
        if (T[i] == 'r')
            ans += P;
        if (T[i] == 's')
            ans += R;
        if (T[i] == 'p')
            ans += S;
    }
    cout << ans << endl;
    return 0;
}
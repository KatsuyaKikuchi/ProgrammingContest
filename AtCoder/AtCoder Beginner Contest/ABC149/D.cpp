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
    ll N, K, R, S, P;
    cin >> N >> K >> R >> S >> P;
    string T;
    cin >> T;

    memset(U, 0, sizeof(U));
    ll ans = 0;
    REP(i, N) {
        ll p = i - K;
        if (p >= 0 && T[i] == T[p] && U[p])
            continue;
        U[i] = true;
        if (T[i] == 'r')
            ans += P;
        else if (T[i] == 's')
            ans += R;
        else
            ans += S;
    }
    cout << ans << endl;
    return 0;
}
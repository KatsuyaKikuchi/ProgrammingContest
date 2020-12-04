#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
ll S[105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K, M, R;
    cin >> N >> K >> M >> R;
    REP(i, N - 1) {
        cin >> S[i];
    }
    sort(S, S + N - 1, greater<ll>());
    ll s = 0;
    REP(i, K) {
        s += S[i];
    }
    ll m = std::max(0LL, K * R - s);
    if (m > 0) {
        m = S[K - 1] + m;
    }
    if (m > M)
        m = -1;
    cout << m << endl;

    return 0;
}
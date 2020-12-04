#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll W[10005];

int main() {
    ll L, N;
    cin >> L >> N;
    REP(i, N) {
        cin >> W[i];
    }
    sort(W, W + N);
    ll sum = 0;
    ll ans = 0;
    REP(i, N) {
        sum += W[i];
        if (sum > L)
            break;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
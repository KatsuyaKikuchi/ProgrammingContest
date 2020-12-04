#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, A, B;
    cin >> N >> A >> B;
    ll ans = INF;
    if ((B - A) % 2 == 0) {
        ans = (B - A) / 2;
    }
    else {
        ans = std::min((B - A - 1) / 2 + A, (N - (A + (N - B + 1))) / 2 + (N - B + 1));
    }
    cout << ans << endl;
    return 0;
}
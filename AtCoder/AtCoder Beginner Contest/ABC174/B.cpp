#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, D;
    cin >> N >> D;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }

    ll ans = 0;
    REP(i, N) {
        ll d = A[i].first * A[i].first + A[i].second * A[i].second;
        if (d <= D * D)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
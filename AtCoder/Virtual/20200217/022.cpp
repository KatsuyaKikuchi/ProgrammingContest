#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    vector<ll> v(N + 1, INF);
    REP(i, N) {
        ll index = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
        v[index] = A[i];
    }
    ll ans = lower_bound(v.begin(), v.end(), INF) - v.begin();
    cout << ans << endl;
    return 0;
}
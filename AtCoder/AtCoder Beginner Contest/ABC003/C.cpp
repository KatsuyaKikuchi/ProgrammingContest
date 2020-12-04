#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll R[105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        cin >> R[i];
    }
    sort(R, R + N, greater<ll>());
    vector<ll> v;
    REP(i, K) {
        v.push_back(R[i]);
    }
    sort(v.begin(), v.end());
    double ans = 0;
    REP(i, K) {
        ans = (ans + v[i]) * 0.5;
    }
    cout << OF64 << ans << endl;
    return 0;
}
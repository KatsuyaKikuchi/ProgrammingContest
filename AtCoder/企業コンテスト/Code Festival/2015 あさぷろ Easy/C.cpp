#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K, M, R;
    cin >> N >> K >> M >> R;
    vector<ll> v;
    REP(i, N - 1) {
        ll s;
        cin >> s;
        v.push_back(s);
    }
    v.push_back(0);
    sort(v.begin(), v.end(), greater<ll>());
    ll sum = 0;
    REP(i, K) {
        sum += v[i];
    }
    if (sum >= R * K) {
        cout << 0 << endl;
        return 0;
    }
    sum -= v[K - 1];
    ll ans = R * K - sum;
    if (ans > M)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}
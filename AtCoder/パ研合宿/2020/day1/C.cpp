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
    ll N;
    cin >> N;
    map<string, ll> mp;
    REP(i, N) {
        ll k;
        cin >> k;
        REP(j, k) {
            string s;
            cin >> s;
            mp[s]++;
        }
    }
    ll ans = 0;
    for (auto t: mp) {
        if (t.second == N)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
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
    ll N;
    cin >> N;
    vector<ll> s;
    REP(i, N) {
        ll m;
        cin >> m;
        s.push_back(m);
    }
    sort(s.begin(),s.end());

    ll Q;
    cin >> Q;
    ll ans = 0;
    REP(i, Q) {
        ll q;
        cin >> q;

        ll n = *lower_bound(s.begin(), s.end(), q) ;
        if (q == n)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
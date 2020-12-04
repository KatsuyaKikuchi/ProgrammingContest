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
    vector<ll> v;
    REP(i, N) {
        REP(j, 6) {
            ll a;
            cin >> a;
            v.push_back(a);
        }
    }
    sort(v.begin(), v.end());
    return 0;
}
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
    ll N, K;
    cin >> N >> K;
    vector<ll> v(K);
    REP(i, K) {
        cin >> v[i];
    }

    REP(b, pow(2LL, K)) {
        ll x = 0;
        REP(j, K) {
            if ((b >> j) & 1)
                x |= (1LL << v[j]);
        }
        cout << x << ":";
        REP(j, K) {
            if ((b >> j) & 1)
                cout << " " << v[j];
        }
        cout << endl;
    }
    return 0;
}
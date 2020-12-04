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
    ll A, B;
    cin >> A >> B;
    REP(i, std::max(A, B) * 100) {
        ll n = i + 1;

        ll a = n * 0.08;
        ll b = n * 0.1;
        if (a == A && b == B) {
            cout << n << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
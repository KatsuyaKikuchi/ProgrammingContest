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
    ll N, A, B;
    cin >> N >> A >> B;
    if ((B - A) % 2 == 0) {
        cout << (B - A) / 2 << endl;
    }
    else {
        ll m = std::min((B - 1), (N - A));
        ll a = ((B - A) - 1) / 2 + A;
        ll b = (N - (A + (N - B + 1))) / 2 + (N - B + 1);
        cout << std::min(m, std::min(a, b)) << endl;
    }
    return 0;
}
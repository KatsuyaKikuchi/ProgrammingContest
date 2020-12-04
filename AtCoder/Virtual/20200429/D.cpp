#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll P[55];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, p;
    cin >> N >> p;
    ll odd = 0, even = 0;
    REP(i, N) {
        ll a;
        cin >> a;
        if (a % 2 == 0)
            even++;
        else
            odd++;
    }

    P[0] = 1;
    REP(i, N + 1) {
        P[i + 1] = P[i] * 2LL;
    }

    if (p == 0)
        cout << P[even] * (P[std::max(odd - 1, 0LL)]) << endl;
    else
        cout << P[even] * (P[odd] - P[std::max(odd - 1, 0LL)]) << endl;
    return 0;
}
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
    ll p = 0;
    ll s = 0;
    ll m = INF;
    REP(i, N) {
        cin >> A[i];
        if (A[i] < 0)
            p++;
        s += abs(A[i]);
        m = std::min(m, abs(A[i]));
    }

    if (p % 2 == 0)
        cout << s << endl;
    else
        cout << s - 2LL * m << endl;
    return 0;
}
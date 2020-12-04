#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll X, N;
    cin >> X >> N;
    REP(i, N) {
        cin >> A[i];
    }

    ll ans = -1;
    for (ll n = -1; n <= 101; ++n) {
        bool e = true;
        REP(i, N) {
            if (A[i] == n)
                e = false;
        }
        if (!e)
            continue;

        if (abs(X - n) < abs(X - ans))
            ans = n;
    }
    cout << ans << endl;
    return 0;
}
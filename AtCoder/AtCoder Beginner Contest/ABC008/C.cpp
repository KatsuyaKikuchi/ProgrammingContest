#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> C[i];
    }
    double ans = 0;
    REP(i, N) {
        ll n = 0;
        REP(j, N) {
            if (i == j)
                continue;
            if (C[i] % C[j] == 0)
                n++;
        }
        if (n % 2 == 0) {
            ans += (n * 0.5 + 1.0) / (n + 1.0);
        }
        else {
            ans += 0.5;
        }
    }

    cout << OF64 << ans << endl;
    return 0;
}
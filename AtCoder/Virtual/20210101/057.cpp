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
            if (C[i] % C[j] == 0)
                n++;
        }
        double p = (n - 1) / 2 + 1;
        ans += p / (double) n;
        //cout << OF64 << ans << endl;
    }

    cout << OF64 << ans << endl;
    return 0;
}
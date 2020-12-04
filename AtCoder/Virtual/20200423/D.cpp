#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[30];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    memset(C, 0, sizeof(C));
    REP(i, S.length()) {
        C[S[i] - 'a']++;
    }

    ll odd = 0;
    REP(i, 27) {
        if (C[i] % 2 == 1)
            odd++;
    }

    ll ans = 2 * (((S.length() - odd) / 2) / std::max(1LL, odd));
    if (odd > 0)
        ans++;
    cout << ans << endl;
    return 0;
}
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
    ll N = S.length();
    ll ans = N * (N + 1) / 2;
    REP(i, N) {
        C[S[i] - 'a']++;
    }

    REP(i, 26) {
        ans -= C[i] * (C[i] + 1) / 2;
    }
    cout << ans + 1 << endl;
    return 0;
}
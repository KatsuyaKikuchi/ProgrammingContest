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
    ll N;
    string S;
    cin >> N >> S;

    ll ans = 0;
    REP(i, N-2) {
        if (S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C')
            ans++;
    }
    cout << ans << endl;

    return 0;
}
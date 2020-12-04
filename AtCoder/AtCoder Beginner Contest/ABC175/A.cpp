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
    string S;
    cin >> S;
    ll ans = 0;
    if (S[0] == S[1] && S[1] == S[2] && S[0] == 'R')
        ans = 3;
    else if (S[1] == 'R' && (S[0] == S[1] || S[1] == S[2])) {
        ans = 2;
    }
    else {
        REP(i, 3) {
            if (S[i] == 'R')
                ans = 1;
        }
    }
    cout << ans << endl;
    return 0;
}
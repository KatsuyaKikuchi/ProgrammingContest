#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[5];

ll solve() {
    string S;
    cin >> S;
    ll N = S.length();
    ll ret = INF;
    memset(C, 0, sizeof(C));
    ll s = 0;
    REP(i, N) {
        C[S[i] - '1']++;
        while (C[0] > 0 && C[1] > 0 && C[2] > 0) {
            ret = std::min(ret, i - s + 1);
            C[S[s++] - '1']--;
        }
    }
    if (ret == INF)
        ret = 0;
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(_, T) {
        cout << solve() << endl;
    }
    return 0;
}
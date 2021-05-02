#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s = "ZONe";
    string S;
    cin >> S;
    ll ans = 0;
    REP(i, S.length()) {
        if (i + 4 > S.length())
            break;
        bool e = true;
        REP(j, 4) {
            if (s[j] != S[i + j])
                e = false;
        }
        if (e)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
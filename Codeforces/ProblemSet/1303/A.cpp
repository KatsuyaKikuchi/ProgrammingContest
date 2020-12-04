#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve(string &s) {
    ll ret = 0;
    ll n = 0;
    bool one = false;
    REP(i, s.length()) {
        if (s[i] == '1') {
            ret += n;
            n = 0;
            one = true;
        }
        else if (one) {
            n++;
        }
    }
    return ret;
}

int main() {
    ll Q;
    cin >> Q;
    REP(_, Q) {
        string S;
        cin >> S;
        cout << solve(S) << endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    string S;
    cin >> S;

    ll ret = INF;
    REP(i, S.length() + 1) {
        ll cnt = 0;
        REP(j, S.length()) {
            ll n = j >= i ? 1 : 0;
            if (S[j] - '0' != n)
                cnt++;
        }
        ret = std::min(ret, cnt);
    }
    REP(i, S.length() + 1) {
        ll cnt = 0;
        REP(j, S.length()) {
            ll n = j >= i ? 0 : 1;
            if (S[j] - '0' != n)
                cnt++;
        }
        ret = std::min(ret, cnt);
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}
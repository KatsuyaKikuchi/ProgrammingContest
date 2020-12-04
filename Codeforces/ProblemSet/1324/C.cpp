#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve(string &S) {
    ll ret = 1;
    ll N = S.length();
    ll s = 1;
    for (ll i = N - 1; i >= 0; --i) {
        if (S[i] == 'R') {
            ret = std::max(ret, s);
            s = 0;
        }
        s++;
    }
    ret = std::max(s, ret);
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        string S;
        cin >> S;
        cout << solve(S) << endl;
    }
    return 0;
}
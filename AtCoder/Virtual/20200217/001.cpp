#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll calc(string s, ll bit) {
    ll n = s.length();
    ll m = s[0] - '0';
    ll ret = 0;
    REP(i, s.length() - 1) {
        if ((bit >> i) & 1) {
            ret += m;
            m = 0;
        }
        m = m * 10 + s[i + 1] - '0';
    }
    return ret + m;
}

int main() {
    string S;
    cin >> S;
    ll N = S.length();
    ll ans = 0;
    REP(i, pow(2LL, N - 1)) {
        ans += calc(S, i);
    }
    cout << ans << endl;
    return 0;
}
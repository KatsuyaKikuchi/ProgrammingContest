#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll s_l(string s) {
    ll ret = 0;
    REP(i, s.length()) {
        ret *= 10LL;
        ret += s[i] - '0';
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S, T;
    cin >> S >> T;
    if (S.length() != T.length()) {
        string ans = "1";
        REP(i, S.length()) {
            ans.push_back('0');
        }
        cout << ans << endl;
    }
    else {
        ll ans = 0;
        REP(i, S.length()) {
            ans *= 10LL;
            ans += S[i] - '0';
            if (S[i] == T[i]) {
                continue;
            }
            FOR(_, S.length(), i + 1) {
                ans *= 10LL;
            }
            break;
        }
        ll a = s_l(S);
        ll p = 0;
        ll x = 0;
        while (ans + p < a || (ans + p) % 2 == 1) {
            p = pow(10LL, x++);
        }
        cout << ans + p << endl;
    }
    return 0;
}
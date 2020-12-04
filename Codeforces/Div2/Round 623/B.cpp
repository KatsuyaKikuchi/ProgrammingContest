#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve(ll a, ll b, ll p, string s) {
    ll N = s.length();
    ll c = 0;
    for (ll i = N - 2; i >= 0; --i) {
        if (s[i] != s[i + 1] || i == N - 2) {
            if (s[i] == 'A')
                c += a;
            else
                c += b;
        }
        if (c > p)
            return i + 2;
    }
    return 1;
}

int main() {
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll a, b, p;
        cin >> a >> b >> p;
        string S;
        cin >> S;
        cout << solve(a, b, p, S) << endl;
    }
    return 0;
}
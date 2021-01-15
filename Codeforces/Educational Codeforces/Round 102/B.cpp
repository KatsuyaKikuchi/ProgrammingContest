#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

string solve() {
    string S, T;
    cin >> S >> T;
    ll N = S.length(), M = T.length();
    ll g = N * M / gcd(N, M);
    string s = "";
    REP(_, g / N) {
        s += S;
    }
    string t = "";
    REP(_, g / M) {
        t += T;
    }
    if (s != t)
        return "-1";
    return s;
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
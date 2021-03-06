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
    string S;
    cin >> S;
    ll N = S.length();
    ll ans = 0;
    REP(i, N) {
        char a = S[i];
        char b = S[N - 1 - i];
        if (a == '(' && b == ')')
            continue;
        if (a == ')' && b == '(')
            continue;
        if (a != b || (a == '(' && a == b) || (a == ')' && a == b)) {
            ans++;
            S[i] = S[N - 1 - i] = 'a';
        }
    }

    cout << ans << endl;
    return 0;
}
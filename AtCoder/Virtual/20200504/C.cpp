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
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll a = 0, b = 0, c = 0;
    REP(i, S.length()) {
        if (S[i] == 'a')
            a++;
        if (S[i] == 'b')
            b++;
        if (S[i] == 'c')
            c++;
    }

    if (max({a, b, c}) - min({a, b, c}) < 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
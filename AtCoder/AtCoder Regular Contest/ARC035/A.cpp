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
    ll N = S.length();
    REP(i, N) {
        char c0 = S[i], c1 = S[N - 1 - i];
        if (c0 == c1 || c0 == '*' || c1 == '*')
            continue;
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}
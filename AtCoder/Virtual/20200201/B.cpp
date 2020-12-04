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
    ll N;
    string S;
    cin >> N >> S;
    ll x = 0;
    ll m = 0;
    REP(i, N) {
        if (S[i] == 'I')
            x++;
        if (S[i] == 'D')
            x--;
        m = std::max(m, x);
    }
    cout << m << endl;
    return 0;
}
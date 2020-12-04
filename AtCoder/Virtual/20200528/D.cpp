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
    ll A, B, X;
    cin >> A >> B >> X;
    ll b = B / X;
    ll a = (A - 1) / X;
    if (A == 0)
        a = -1;
    cout << b - a << endl;
    return 0;
}
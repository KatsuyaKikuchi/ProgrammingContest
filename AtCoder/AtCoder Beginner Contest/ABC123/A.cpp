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
    ll A, B, C, D, E, K;
    cin >> A >> B >> C >> D >> E >> K;
    if (E - A > K)
        cout << ":(" << endl;
    else
        cout << "Yay!" << endl;
    return 0;
}
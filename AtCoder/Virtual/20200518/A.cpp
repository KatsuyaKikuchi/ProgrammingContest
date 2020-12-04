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
    ll A, B;
    cin >> A >> B;
    A = abs(A);
    B = abs(B);
    if (A < B)
        cout << "Ant" << endl;
    else if (A > B)
        cout << "Bug" << endl;
    else
        cout << "Draw" << endl;
    return 0;
}
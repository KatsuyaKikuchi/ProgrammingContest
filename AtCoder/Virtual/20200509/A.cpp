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
    ll X, A, B;
    cin >> X >> A >> B;
    ll d = B - A;
    if (d <= 0)
        cout << "delicious";
    else if (d <= X)
        cout << "safe";
    else
        cout << "dangerous";
    cout << endl;
    return 0;
}
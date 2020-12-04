
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
    ll N;
    cin >> N;
    bool y = false;
    while (N > 0) {
        if (N % 10 == 7)
            y = true;
        N /= 10;
    }

    if (y)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
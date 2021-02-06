#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B, C;
    cin >> A >> B >> C;
    if (C == 0) {
        if (A > B)
            cout << "Takahashi" << endl;
        else
            cout << "Aoki" << endl;
    }
    else {
        if (B > A)
            cout << "Aoki" << endl;
        else
            cout << "Takahashi" << endl;
    }
    return 0;
}
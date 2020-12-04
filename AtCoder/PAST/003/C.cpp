#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, R, N;
    cin >> A >> R >> N;
    if (R == 1) {
        cout << A << endl;
        return 0;
    }

    REP(i, N - 1) {
        A *= R;
        if (A > INF) {
            cout << "large" << endl;
            return 0;
        }
    }
    cout << A << endl;
    return 0;
}
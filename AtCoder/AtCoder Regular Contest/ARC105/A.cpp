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
    ll A[4];
    ll S = 0;
    REP(i, 4) {
        cin >> A[i];
        S += A[i];
    }

    REP(i, pow(2, 4)) {
        ll s = 0;
        REP(b, 4) {
            if (((i >> b) & 1) == 1) {
                s += A[b];
            }
        }

        if (S - s == s) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
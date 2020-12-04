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
    ll S, P;
    cin >> S >> P;

    ll n = 1;
    while (n * n <= P) {
        if (P % n == 0) {
            ll m = P / n;
            if (n + m == S) {
                cout << "Yes" << endl;
                return 0;
            }
        }
        n++;
    }
    cout << "No" << endl;
    return 0;
}
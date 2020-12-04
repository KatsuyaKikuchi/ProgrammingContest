#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool U[105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B, C;
    cin >> A >> B >> C;
    ll p = A % B;

    ll t = p;
    while (!U[t]) {
        U[t] = true;
        if (C == t) {
            cout << "YES" << endl;
            return 0;
        }
        t = (t + p) % B;
    }
    cout << "NO" << endl;
    return 0;
}
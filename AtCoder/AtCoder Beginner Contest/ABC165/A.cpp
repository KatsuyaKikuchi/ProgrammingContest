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
    ll K, A, B;
    cin >> K >> A >> B;
    for (int i = A; i <= B; ++i) {
        if (i % K == 0) {
            cout << "OK" << endl;
            return 0;
        }
    }
    cout << "NG" << endl;
    return 0;
}
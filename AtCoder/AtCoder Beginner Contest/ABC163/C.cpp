#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;

    cin >> N;
    memset(C, 0, sizeof(C));
    REP(i, N - 1) {
        ll p;
        cin >> p;
        C[p - 1]++;
    }

    REP(i, N) {
        cout << C[i] << endl;
    }
    return 0;
}
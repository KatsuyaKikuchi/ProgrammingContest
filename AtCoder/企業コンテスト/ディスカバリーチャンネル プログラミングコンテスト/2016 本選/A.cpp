#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[105];
ll B[5] = {100000, 50000, 30000, 20000, 10000};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        ll a;
        cin >> a;
        A[a - 1] = i;
    }

    REP(i, N) {
        if (A[i] >= 5)
            cout << 0 << endl;
        else
            cout << B[A[i]] << endl;
    }
    return 0;
}
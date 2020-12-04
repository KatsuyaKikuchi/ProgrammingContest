#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, D;
    cin >> N >> D;
    A[0] = 0;
    REP(i, N) {
        ll a;
        cin >> a;
        A[i + 1] = A[i] + a;
    }
    REP(i, N) {
        A[i + 1] = std::max(A[i + 1], A[i] + D);
    }
    REP(i, N) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
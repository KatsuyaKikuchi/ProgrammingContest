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
ll B[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N + 1) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> B[i];
    }

    ll s = 0;
    REP(i, N) {
        ll b = std::min(A[i], B[i]);
        B[i] -= b;
        s += b;
        A[i] -= b;
        ll b1 = std::min(A[i + 1], B[i]);
        s += b1;
        A[i + 1] -= b1;
    }
    cout << s << endl;
    return 0;
}
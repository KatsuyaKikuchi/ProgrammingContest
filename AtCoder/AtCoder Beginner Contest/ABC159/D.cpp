#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];
ll B[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    memset(B, 0, sizeof(B));
    REP(i, N) {
        cin >> A[i];
        B[A[i] - 1]++;
    }

    ll ans = 0;
    REP(i, N) {
        ans += B[i] * (B[i] - 1) / 2;
    }

    REP(i, N) {
        ll t = ans;
        t -= std::max(0LL, B[A[i] - 1] - 1);
        cout << t << endl;
    }
    return 0;
}
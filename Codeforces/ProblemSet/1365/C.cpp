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
    REP(i, N) {
        ll a;
        cin >> a;
        a--;
        A[a] = i;
    }
    REP(i, N) {
        ll b;
        cin >> b;
        b--;
        ll d = (N - A[b] + i) % N;
        B[d]++;
    }

    ll ans = 0;
    REP(i, N) {
        ans = std::max(ans, B[i]);
    }
    cout << ans << endl;
    return 0;
}
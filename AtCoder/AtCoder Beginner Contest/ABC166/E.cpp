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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    map<ll, ll> M;
    ll ans = 0;
    M[-(A[0] + 1)] = 1;
    FOR(i, N, 1) {
        ll t = A[i] - (i + 1);
        ans += M[t];

        M[-(A[i] + (i + 1))]++;
    }
    cout << ans << endl;
    return 0;
}
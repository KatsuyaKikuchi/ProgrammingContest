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
    ll sum = 0;
    REP(i, N) {
        cin >> A[i];
        sum += A[i];
    }
    ll ans = 0;
    ll n = N / 2;
    {
        //! odd
        ll dif = 0;
        REP(i, n) {
            dif += A[1 + 2 * i];
        }
        for (ll i = 0; i < N; i += 2) {
            ans = std::max(ans, sum - dif);
            dif += A[i] - A[(i + 1) % N];
        }
    }
    {
        //! even
        ll dif = 0;
        REP(i, n) {
            dif += A[(2 + 2 * i) % N];
        }
        for (ll i = 1; i < N; i += 2) {
            ans = std::max(ans, sum - dif);
            dif += A[i] - A[(i + 1) % N];
        }
    }

    cout << ans << endl;
    return 0;
}
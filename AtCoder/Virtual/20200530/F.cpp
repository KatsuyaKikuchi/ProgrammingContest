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
ll L[100005];
ll R[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i];
    }
    memset(L, 0, sizeof(L));
    memset(R, 0, sizeof(R));
    ll ans = 0;
    {
        ll s = 0;
        REP(i, N) {
            L[i] = s;
            s += std::max(0LL, A[i]);
        }
    }
    {
        ll s = 0;
        for (ll i = N - 1; i >= 0; --i) {
            s += std::max(0LL, A[i]);
            R[i] = s;
        }
    }

    {
        ll s = 0;
        REP(i, K) {
            s += A[i];
        }
        REP(i, N) {
            if (i + K > N)
                break;
            ans = std::max(L[i] + R[i + K] + std::max(0LL, s), ans);
            s += A[i + K] - A[i];
        }
    }
    cout << ans << endl;
    return 0;
}
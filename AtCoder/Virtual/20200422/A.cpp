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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, X;
    cin >> N >> M >> X;
    REP(i, M) {
        cin >> A[i];
    }

    ll ans = INF;
    {
        ll s = 0;
        for (ll i = X; i < N; ++i) {
            REP(j, M) {
                if (A[j] == i)
                    s++;
            }
        }
        ans = std::min(ans, s);
    }
    {
        ll s = 0;
        for (ll i = X; i >= 0; --i) {
            REP(j, M) {
                if (A[j] == i)
                    s++;
            }
        }
        ans = std::min(ans, s);
    }
    cout << ans << endl;
    return 0;
}
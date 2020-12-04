#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll L[105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll ans = N;
    FOR(s, N, 1) {
        memset(L, 0, sizeof(L));
        REP(i, s) {
            ll m = 0;
            for (ll j = s; j < N; ++j) {
                ll t = std::max(m, L[j]);
                if (S[i] == S[j])
                    L[j] = std::max(L[j], m + 1);
                m = t;
            }
        }

        ll mx = 0;
        REP(i, N) {
            mx = std::max(L[i], mx);
        }
        ans = std::min(N - 2 * mx, ans);
    }
    cout << ans << endl;

    return 0;
}
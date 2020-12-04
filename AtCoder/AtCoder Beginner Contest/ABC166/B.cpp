#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll S[105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    memset(S, 0, sizeof(S));
    REP(i, K) {
        ll d;
        cin >> d;
        REP(j, d) {
            ll a;
            cin >> a;
            S[a - 1]++;
        }
    }

    ll ans = 0;
    REP(i, N) {
        if (S[i] == 0)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
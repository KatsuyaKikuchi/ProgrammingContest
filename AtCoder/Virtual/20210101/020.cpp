#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];
ll S[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    memset(S, 0, sizeof(S));
    for (ll i = N - 1; i >= 0; --i) {
        S[i] = A[i] + S[i + 1];
    }
    ll ans = INF;
    ll s = 0;
    REP(i, N - 1) {
        s += A[i];
        //cout << s << " " << S[i + 1] << endl;
        ans = std::min(ans, abs(s - S[i + 1]));
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll P[100005];
pll A[100005];
ll C[100005];
ll S[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        cin >> P[i];
        P[i]--;
    }
    REP(i, N - 1) {
        cin >> A[i].first >> A[i].second >> C[i];
    }
    memset(S, 0, sizeof(S));
    REP(i, M - 1) {
        ll s = P[i], g = P[i + 1];
        S[std::min(s, g)]++;
        S[std::max(s, g)]--;
    }

    REP(i, N) {
        S[i + 1] += S[i];
    }

    ll ans = 0;
    REP(i, N - 1) {
        ans += std::min(S[i] * A[i].first, S[i] * A[i].second + C[i]);
    }
    cout << ans << endl;

    return 0;
}
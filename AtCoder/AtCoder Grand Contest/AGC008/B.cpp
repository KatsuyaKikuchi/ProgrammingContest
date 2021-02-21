#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    ll ans = 0;
    vector<ll> S(N + 2, 0);
    for (ll i = N - 1; i >= 0; --i) {
        S[i] = S[i + 1] + std::max(0LL, A[i]);
    }
    ll s = 0;
    REP(i, K) {
        s += A[i];
    }
    ans = std::max(ans, std::max(s, 0LL) + S[K]);
    ll t = 0;
    FOR(i, N, K) {
        s += A[i] - A[i - K];
        t += std::max(0LL, A[i - K]);
        ans = std::max(ans, std::max(s, 0LL) + t + S[i + 1]);
    }
    cout << ans << endl;
    return 0;
}
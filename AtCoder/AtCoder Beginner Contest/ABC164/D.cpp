#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 2019;
const ll INF = (ll) 1e15;

ll P[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N = S.length();
    P[N - 1] = 1;
    FOR(i, N, 1) {
        P[N - i - 1] = (P[N - i] * 10LL) % MOD;
    }

    map<ll, ll> M;
    M[0]++;
    ll ans = 0;
    ll s = 0;
    REP(i, N) {
        s = (s * 10 + S[i] - '0') % MOD;
        ll m = s * P[i] % MOD;

        ans += M[m];
        M[m]++;
    }

    cout << ans << endl;
    return 0;
}
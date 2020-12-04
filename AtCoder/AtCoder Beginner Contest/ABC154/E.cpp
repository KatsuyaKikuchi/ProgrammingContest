#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 67280421310721;
const ll INF = (ll) 1e15;

ll cmb(ll n, ll r) {
    if (n < 0 || n < r || r < 0)
        return 0;
    ll t = 1, m = 1;
    REP(i, r) {
        t *= (n - i);
        m *= (i + 1);
    }
    return t / m;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    ll K;
    cin >> S >> K;
    ll ans = 0;
    ll N = S.length();
    ll n = 0;
    REP(i, N) {
        if (S[i] > '0')
            n++;
    }
    if (K == n)
        ans++;
    REP(i, N) {
        if (S[i] == '0')
            continue;
        ans += cmb(N - 1 - i, K) * pow(9, K);
        ans += cmb(N - 1 - i, K - 1) * pow(9, K - 1) * std::max(S[i] - '1', 0);
        K--;
    }
    cout << ans << endl;
    return 0;
}
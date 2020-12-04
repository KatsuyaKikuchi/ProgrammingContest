#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

pll A[100005];
pll dp[100005];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }

    dp[0] = A[0];
    FOR(i, N, 1) {
        dp[i].first = std::max(gcd(dp[i - 1].first, A[i].first), gcd(dp[i - 1].second, A[i].first));
        dp[i].second = std::max(gcd(dp[i - 1].first, A[i].second), gcd(dp[i - 1].second, A[i].second));
    }

    cout << std::max(dp[N - 1].first, dp[N - 1].second) << endl;
    return 0;
}
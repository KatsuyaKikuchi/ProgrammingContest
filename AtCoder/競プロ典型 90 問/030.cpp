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
    vector<ll> count(N + 5, 0);
    vector<bool> prime(N + 5, true);
    for (ll i = 2; i <= N; ++i) {
        if (!prime[i])
            continue;
        for (ll j = i; j <= N; j += i) {
            count[j]++;
            prime[j] = false;
        }
    }
    ll ans = 0;
    REP(i, N) {
        if (count[i + 1] >= K)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
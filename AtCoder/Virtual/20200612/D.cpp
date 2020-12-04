#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];
ll B[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, M) {
        cin >> B[i];
    }

    ll x = 0, y = 0;
    REP(i, N - 1) {
        ll d = A[i + 1] - A[i];
        ll p = (i + 1) * (N - (i + 1)) % MOD;
        x += d * p % MOD;
        x %= MOD;
    }
    REP(i, M) {
        ll d = B[i + 1] - B[i];
        ll p = (i + 1) * (M - (i + 1)) % MOD;
        y += d * p % MOD;
        y %= MOD;
    }
    cout << x * y % MOD << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll T[100005];
ll M[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> T[i];
    }

    M[0] = 1;
    REP(i, N) {
        M[i + 1] = M[i] * (i + 1) % MOD;
    }
    sort(T, T + N);
    ll s = 0;
    ll ans = 0;
    ll p = 0;
    ll mul = 1;
    REP(i, N) {
        s += T[i];
        ans += s;
        if (i > 0 && T[i] != T[i - 1]) {
            mul = mul * M[p] % MOD;
            p = 0;
        }
        p++;
    }
    cout << ans << endl;
    cout << mul * M[p] % MOD << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;

ll N, X;
ll A[55];

ll calc(ll index, ll value) {
    for (ll i = index; i >= 0; --i) {
        value %= A[i];
        if (value == 0)
            return index - i;
    }
    return 0;
}

ll dfs(ll index, ll value, ll p = INF) {
    if (index <= 0 || value == 0)
        return 0;
    ll m = (value + A[index] - 1) / A[index];
    ll ret = 0;
    if (m > 1) {
        ret += dfs(index - 1, value - A[index] * (m - 1));
    }

    ll diff = A[index] * m - value;
    if (diff > 0) {
        ret += calc(index - 1, diff);
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> X;
    REP(i, N) {
        cin >> A[i];
    }
    ll ans = 1 + dfs(N - 1, X);
    REP(i, N) {
        if (A[i] < X)
            continue;
        ll m = (X + A[i] - 1) / A[i];
        if (m == 0)
            ans += dfs(i - 1, X);
        break;
    }

    cout << ans << endl;
    return 0;
}
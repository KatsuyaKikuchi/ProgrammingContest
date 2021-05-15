#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = (ll) 1e6 + 5;

ll F[MAX];

ll solve(ll N) {
    ll ans = 1;
    FOR(n, N + 1, 3) {
        if (N % n != 0)
            continue;
        ll m = N / n - 1;
        ans = std::max(ans, F[m] + 1);
    }

    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    F[0] = F[1] = 0;
    FOR(i, MAX, 2) {
        F[i] = std::max(F[i], 1LL);
        FOR(j, i + 1, 2) {
            if (i * j >= MAX)
                break;
            F[i * j] = std::max(F[i * j], F[i - 1] + 1);
        }
    }
    ll T;
    cin >> T;
    REP(i, T) {
        ll N;
        cin >> N;
        cout << "Case #" << i + 1 << ": " << solve(N) << endl;
    }
    return 0;
}
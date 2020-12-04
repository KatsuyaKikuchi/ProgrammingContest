#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll N;
    cin >> N;
    vector<ll> A(N + 2);
    REP(i, N) {
        cin >> A[i];
    }
    vector<ll> dp0(N + 5, INF), dp1(N + 5, INF);
    dp1[0] = 0;
    REP(i, N) {
        {
            ll x = 0;
            if (A[i] == 1)
                x++;
            dp0[i + 1] = std::min(dp0[i + 1], dp1[i] + x);
            if (A[i + 1] == 1)
                x++;
            dp0[i + 2] = std::min(dp0[i + 2], dp1[i] + x);
        }

        dp1[i + 1] = std::min(dp1[i + 1], dp0[i]);
        dp1[i + 2] = std::min(dp1[i + 2], dp0[i]);
    }

    return std::min(dp0[N], dp1[N]);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}
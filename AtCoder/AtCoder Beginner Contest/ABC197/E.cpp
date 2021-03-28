#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e16;

ll dp[200005][5];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<vector<ll>> X(N);
    REP(i, N) {
        ll x, c;
        cin >> x >> c;
        c--;
        X[c].push_back(x);
    }

    vector<pll> T;
    REP(i, N) {
        if (X[i].size() == 0)
            continue;
        pll p(INF, -INF);
        REP(j, X[i].size()) {
            p.first = std::min(p.first, X[i][j]);
            p.second = std::max(p.second, X[i][j]);
        }
        T.push_back(p);
    }
    REP(i, T.size() + 3) {
        REP(j, 3) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    REP(i, T.size()) {
        ll lx = 0, rx = 0;
        if (i > 0) {
            lx = T[i - 1].first;
            rx = T[i - 1].second;
        }

        {
            //! lx->lx
            ll dist = abs(T[i].second - lx) + T[i].second - T[i].first;
            dp[i + 1][0] = std::min(dp[i + 1][0], dp[i][0] + dist);
        }
        {
            //! lx->rx
            ll dist = abs(T[i].first - lx) + T[i].second - T[i].first;
            dp[i + 1][1] = std::min(dp[i + 1][1], dp[i][0] + dist);
        }
        {
            //! rx->lx
            ll dist = abs(T[i].second - rx) + T[i].second - T[i].first;
            dp[i + 1][0] = std::min(dp[i + 1][0], dp[i][1] + dist);
        }
        {
            //! rx->rx
            ll dist = abs(T[i].first - rx) + T[i].second - T[i].first;
            dp[i + 1][1] = std::min(dp[i + 1][1], dp[i][1] + dist);
        }
    }

    ll ans = std::min(dp[T.size()][0] + abs(T[T.size() - 1].first), dp[T.size()][1] + abs(T[T.size() - 1].second));
    cout << ans << endl;
    return 0;
}
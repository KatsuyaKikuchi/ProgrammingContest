#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;

struct Edge {
    ll from;
    ll to;
    ll cost;
    ll time;
};

//! 頂点iにコインn枚でたどり着く最短時間
ll dp[55][10005];
pll A[55];
Edge E[205];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, S;
    cin >> N >> M >> S;
    ll sum = 0;
    REP(i, M) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        sum += c * 2;
        E[i * 2 + 0].to = E[i * 2 + 1].from = a;
        E[i * 2 + 0].from = E[i * 2 + 1].to = b;
        E[i * 2 + 0].cost = E[i * 2 + 1].cost = c;
        E[i * 2 + 0].time = E[i * 2 + 1].time = d;
    }

    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }

    REP(i, N) {
        REP(j, sum + 1) {
            dp[i][j] = INF;
        }
    }
    dp[0][std::min(S, sum)] = 0;
    S = sum;//std::min(S, sum);

    while (true) {
        bool update = false;
        REP(i, 2 * M) {
            const auto &e = E[i];
            for (ll cost = S; cost - e.cost >= 0; --cost) {
                if (dp[e.from][cost] == INF)
                    continue;
                ll c = cost - e.cost;
                ll t = dp[e.from][cost] + e.time;

                if (dp[e.to][c] > t) {
                    update = true;
                    dp[e.to][c] = t;
                }
            }
        }

        REP(i, N) {
            REP(j, S + 1) {
                ll c = j + A[i].first;
                if (c > S)
                    break;
                if (dp[i][c] > dp[i][j] + A[i].second) {
                    update = true;
                    dp[i][c] = dp[i][j] + A[i].second;
                }
            }
        }
#if false
        REP(i, N) {
            REP(j, S + 1) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
#endif
        if (!update)
            break;
    }

    REP(i, N - 1) {
        ll min = INF;
        REP(j, S + 1) {
            min = std::min(min, dp[i + 1][j]);
        }
        cout << min << endl;
    }
    return 0;
}
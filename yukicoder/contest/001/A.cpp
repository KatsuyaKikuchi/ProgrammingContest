#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    ll from;
    ll to;
    ll cost;
    ll time;
};

Data D[1505];
ll dp[55][305];

int main() {
    ll N, C, V;
    cin >> N >> C >> V;
    REP(i, V) {
        cin >> D[i].from;
        D[i].from--;
    }
    REP(i, V) {
        cin >> D[i].to;
        D[i].to--;
    }
    REP(i, V) {
        cin >> D[i].cost;
    }
    REP(i, V) {
        cin >> D[i].time;
    }

    REP(i, N) {
        REP(j, C + 1) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;

    while (true) {
        bool update = false;
        REP(i, V) {
            REP(j, C) {
                if (dp[D[i].from][j] == INF)
                    continue;
                ll cost = j + D[i].cost;
                if (cost > C)
                    continue;
                if (dp[D[i].to][cost] > dp[D[i].from][j] + D[i].time) {
                    dp[D[i].to][cost] = dp[D[i].from][j] + D[i].time;
                    update = true;
                }
            }
        }
        if (!update)
            break;
    }

    ll min = INF;
    REP(i, C + 1) {
        min = std::min(min, dp[N - 1][i]);
    }
    if (min == INF)
        cout << -1 << endl;
    else
        cout << min << endl;
    return 0;
}
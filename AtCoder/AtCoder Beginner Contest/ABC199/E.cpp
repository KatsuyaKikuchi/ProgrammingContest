#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    ll x, y, z;
};
Data D[105];


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        cin >> D[i].x >> D[i].y >> D[i].z;
        //D[i].x--;
    }

    ll MAX = (1LL << N);
    vector<bool> U(MAX, false);
    REP(bit, MAX) {
        vector<ll> count(N + 1, 0);
        ll cnt = 0;
        REP(i, N) {
            if ((bit >> i) & 1) {
                count[i + 1]++;
                cnt++;
            }
        }
        REP(i, N) {
            count[i + 1] += count[i];
        }

        U[bit] = true;
        REP(i, M) {
            if (D[i].x != cnt)
                continue;
            if (count[D[i].y] > D[i].z) {
                U[bit] = false;
                break;
            }
        }
    }
    vector<vector<ll>> dp(N + 2, vector<ll>(MAX, 0));
    dp[0][0] = 1;
    REP(i, N) {
        REP(bit, MAX) {
            if (dp[i][bit] == 0)
                continue;
            REP(j, N) {
                if (((bit >> j) & 1) == 1)
                    continue;
                ll nxt = (bit | (1LL << j));
                if (!U[nxt])
                    continue;
                dp[i + 1][nxt] += dp[i][bit];
            }
        }
    }

    cout << dp[N][MAX - 1] << endl;
    return 0;
}
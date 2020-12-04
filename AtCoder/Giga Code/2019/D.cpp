#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll H, W, K, V;
ll A[200][200];
ll S[200][200];

//! 面積sの区画をかえるか？
bool check(ll s) {
    REP(i, H) {
        ll h = i + 1;
        ll w = (s + i) / h;

        ll v = h * w * K;

        REP(n, H) {
            if (n + h > H)
                break;
            REP(m, W) {
                if (m + w > W)
                    break;

                ll cost = S[n + h][m + w] - (S[n + h][m] + S[n][m + w]) + S[n][m];

                if (cost + v <= V)
                    return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> H >> W >> K >> V;
    REP(i, H) {
        REP(j, W) {
            cin >> A[i][j];
        }
    }

    memset(S, 0, sizeof(S));
    REP(i, H) {
        REP(j, W) {
            S[i + 1][j + 1] = S[i + 1][j] + A[i][j];
        }
    }
    REP(j, W) {
        REP(i, H) {
            S[i + 1][j + 1] += S[i][j + 1];
        }
    }

    ll ok = 0, ng = H * W + 1;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }
    cout << ok << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll N, M;
    cin >> N >> M;
    vector<string> S(N);
    vector<vector<ll>> T(N, vector<ll>(M + 1, 0));
    REP(i, N) {
        cin >> S[i];
    }
    REP(i, N) {
        REP(j, M) {
            if (S[i][j] == '*')
                T[i][j + 1]++;
            T[i][j + 1] += T[i][j];
        }
    }

    ll ret = 0;
    REP(i, N) {
        REP(j, M) {
            REP(h, N) {
                if (i + h >= N)
                    break;
                ll w = h;
                if (j + w >= M || j - w < 0)
                    break;
                ll count = 1 + 2 * w;
                ll n = T[i + h][j + w + 1] - T[i + h][j - w];
                if (count != n)
                    break;
                ret++;
            }
            //cout << ret << endl;
        }
    }
    //cout << "---" << endl;
    return ret;
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
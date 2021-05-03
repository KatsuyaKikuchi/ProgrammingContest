#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll S[1005][1005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    memset(S, 0, sizeof(S));
    ll N;
    cin >> N;
    REP(i, N) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        S[a][b]++;
        S[c][d]++;
        S[a][d]--;
        S[c][b]--;
    }

    ll MAX = 1002;
    REP(i, MAX) {
        REP(j, MAX) {
            S[i][j + 1] += S[i][j];
        }
    }
    REP(j, MAX) {
        REP(i, MAX) {
            S[i + 1][j] += S[i][j];
        }
    }
    vector<ll> ans(N + 1, 0);
    REP(i, MAX) {
        REP(j, MAX) {
            ans[S[i][j]]++;
        }
    }
#if false
    REP(i, 5) {
        REP(j, 5) {
            cout << S[i][j] << " ";
        }
        cout << endl;
    }
#endif
    REP(i, N) {
        cout << ans[i + 1] << endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005][30];

ll dfs(string &S, ll t, ll f, ll e) {
    if (f == e) {
        return (S[f] - 'a') == t ? 0 : 1;
    }

    ll num = (e - (f - 1)) / 2;
    ll ret = INF;
    {
        //! prev
        ll ne = (f + e) / 2;
        ll s = num - (A[e][t] - A[ne][t]);
        ret = std::min(ret, s + dfs(S, t + 1, f, (f + e) / 2));
    }
    {
        //! aft
        ll nf = (f + e + 1) / 2;
        ll s = num - A[nf - 1][t];
        if (f > 0)
            s += A[f - 1][t];
        ret = std::min(ret, s + dfs(S, t + 1, (f + e + 1) / 2, e));
    }

    return ret;
}

ll solve() {
    ll N;
    cin >> N;
    string S;
    cin >> S;
    REP(i, N) {
        REP(j, 30) {
            A[i][j] = 0;
        }
        A[i][S[i] - 'a']++;
    }
    REP(i, N) {
        REP(j, 30) {
            A[i + 1][j] += A[i][j];
        }
    }

    return dfs(S, 0, 0, N - 1);
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
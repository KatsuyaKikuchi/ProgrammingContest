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
    ll N, M;
    cin >> N >> M;
    vector<string> S(N);
    REP(i, N) {
        cin >> S[i];
    }
    ll ret = 0;
    REP(i, N - 1) {
        if (S[i][M - 1] != 'D')
            ret++;
    }
    REP(i, M - 1) {
        if (S[N - 1][i] != 'R')
            ret++;
    }

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
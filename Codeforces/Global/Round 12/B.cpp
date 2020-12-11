#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll dist(pll a, pll b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

ll solve() {
    ll N, K;
    cin >> N >> K;
    vector<pll> A(N);
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }

    ll ret = INF;
    REP(i, N) {
        bool t = true;
        REP(j, N) {
            if (i == j)
                continue;
            ll d = dist(A[i], A[j]);
            t &= (d <= K);
        }
        if (t)
            return 1;
    }

    return -1;
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
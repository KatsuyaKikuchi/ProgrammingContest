#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool check(ll s, ll K, vector<ll> &P) {
    ll N = P.size();
    ll sum = P[0] + s;
    FOR(i, N, 1) {
        if (P[i] * 100LL > K * sum)
            return false;
        sum += P[i];
    }

    return true;
}

ll solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> P(N);
    REP(i, N) {
        cin >> P[i];
    }

    ll ret = INF, ng = -1;
    while (abs(ret - ng) > 1) {
        ll mid = (ret + ng) / 2;
        if (check(mid, K, P))
            ret = mid;
        else
            ng = mid;
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
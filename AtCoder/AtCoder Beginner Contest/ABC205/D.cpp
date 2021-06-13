#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 2e18;

vector<ll> A;

ll check(ll m) {
    ll N = A.size();
    ll ok = -1, ng = N;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (m >= A[mid])
            ok = mid;
        else
            ng = mid;
    }

    ll ret = m - (ok + 1);

    return ret;
}

ll calc(ll k) {
    ll ok = INF, ng = -1;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (check(mid) >= k)
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    A.resize(N);
    REP(i, N) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    REP(i, Q) {
        ll k;
        cin >> k;
        cout << calc(k) << endl;
    }
    return 0;
}
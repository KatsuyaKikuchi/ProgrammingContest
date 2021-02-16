#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 2LL * 1e9;

ll N, A, B;
ll H[100005];

bool check(ll m) {
    ll d = A - B;
    ll cnt = 0;
    REP(i, N) {
        ll t = H[i] - B * m;
        if (t > 0) {
            cnt += (t + d - 1) / d;
        }
    }
    return cnt <= m;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> A >> B;
    REP(i, N) {
        cin >> H[i];
    }
    ll ok = INF, ng = -1;
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
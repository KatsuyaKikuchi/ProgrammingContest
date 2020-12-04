#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;

bool check(ll mid, pll A, pll B, ll N, ll K) {
    ll d = std::max(0LL, A.second - B.first);
    ll mx = B.second - A.first;
    ll in = std::max(B.first - A.second, 0LL);
    ll sum = d * N;
    ll num = 0;
    ll ret = INF;
    REP(i, N) {
        ll s = std::min(mx - d, K - sum);
        num += s + in;
        sum += s;

        ret = std::min(ret, num + std::max(K - sum, 0LL) * 2LL);
    }

    return ret <= mid;
}

ll solve() {
    ll N, K;
    cin >> N >> K;
    ll l0, r0, l1, r1;
    cin >> l0 >> r0;
    cin >> l1 >> r1;
    if (l0 > l1)
        swap(l0, l1);
    if (r0 > r1)
        swap(r0, r1);
    pll A(l0, r0), B(l1, r1);

    ll ans = INF, ng = -1;
    while (abs(ans - ng) > 1) {
        ll mid = (ans + ng) / 2;
        if (check(mid, A, B, N, K))
            ans = mid;
        else
            ng = mid;
    }
    return ans;
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
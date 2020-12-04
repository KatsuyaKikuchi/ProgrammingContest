#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, A, R, M;
ll H[100005];

ll calc(ll x) {
    ll a = 0;
    ll r = 0;
    REP(i, N) {
        r += std::max(H[i] - x, 0LL);
        a += std::max(x - H[i], 0LL);
    }

    ll ret = 0;
    ll m = std::min(a, r);
    if (A + R > M) {
        ret += m * M;
        a -= m;
        r -= m;
    }
    ret += a * A + r * R;
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> A >> R >> M;
    ll mx = 0, mn = INF;
    REP(i, N) {
        cin >> H[i];
        mx = std::max(mx, H[i]);
        mn = std::min(mn, H[i]);
    }

    while (abs(mx - mn) >= 3) {
        ll d = (mx - mn) / 3;
        ll left = mn + d;
        ll right = mn + 2 * d;
        ll cl = calc(left);
        ll cr = calc(right);
        if (cl > cr)
            mn = left;
        else
            mx = right;
    }

    cout << std::min({calc(mx), calc(mn), calc((mx + mn) / 2)}) << endl;
    return 0;
}
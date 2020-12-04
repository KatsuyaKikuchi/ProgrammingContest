#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 3e18;

ll N;
ll P[5005];
ll C[5005];
ll S[5005];

ll calc(ll s, ll K) {
    memset(S, 0, sizeof(S));

    ll num = 0;
    ll index = s;
    do {
        ll p = P[index];
        S[num + 1] = C[p] + S[num];
        index = p;
        num++;
    } while (index != s);

    S[0] = S[num];

    ll ret = -INF;
    REP(i, std::min(num, K)) {
        ret = std::max(ret, S[(i + 1) % num]);
    }
    ll init = 0;
    if (S[0] > 0) {
        ll t = K / num;
        init = t * S[0];
    }
    if (init > 0)
        ret = std::max(ret, init);
    K %= num;
    REP(i, K) {
        ret = std::max(init + S[(i + 1) % num], ret);
    }

    if (init > 0) {
        init -= S[0];
        REP(i, num) {
            ret = std::max(init + S[(i + 1) % num], ret);
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K;
    cin >> N >> K;
    REP(i, N) {
        cin >> P[i];
        P[i]--;
    }
    REP(i, N) {
        cin >> C[i];
    }

    ll ans = -INF;
    REP(i, N) {
        ans = std::max(ans, calc(i, K));
    }

    cout << ans << endl;
    return 0;
}
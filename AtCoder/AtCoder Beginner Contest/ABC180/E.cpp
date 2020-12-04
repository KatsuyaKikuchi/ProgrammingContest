#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct vec3 {
    ll x;
    ll y;
    ll z;
};

ll S[20][1LL << 18];

ll cost(vec3 from, vec3 to) {
    ll ret = abs(to.x - from.x) + abs(to.y - from.y) + std::max(0LL, to.z - from.z);
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<vec3> v(N);
    REP(i, N) {
        cin >> v[i].x >> v[i].y >> v[i].z;
    }

    ll p = pow(2LL, N);
    REP(i, N) {
        REP(j, p) {
            S[i][j] = INF;
        }
    }

    S[0][1] = 0;
    REP(i, p) {
        REP(j, N) {
            if (((i >> j) & 1) == 0)
                continue;

            ll b = (i & (~(1LL << j)));
            REP(k, N) {
                if (((b >> k) & 1) == 0)
                    continue;
                ll cst = cost(v[k], v[j]) + S[k][b];
                S[j][i] = std::min(S[j][i], cst);
            }
        }
    }

    ll ans = INF;
    REP(i, N) {
        ans = std::min(ans, S[i][p - 1] + cost(v[i], v[0]));
    }
    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[105][105];

ll calc(ll a, ll b, ll c, ll d) {
    vector<ll> v = {a, b, c, d};
    ll ret = INF;
    REP(i, 4) {
        ll m = 0;
        REP(j, 4) {
            m += abs(v[i] - v[j]);
        }
        ret = std::min(m, ret);
    }
    return ret;
}

ll solve() {
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        REP(j, M) {
            cin >> A[i][j];
        }
    }
    ll ret = 0;
    REP(i, N) {
        ll a = i, b = N - 1 - i;
        if (a > b)
            break;
        REP(j, M) {
            ll c = j, d = M - 1 - j;
            if (c > d)
                break;

            ll t = calc(A[a][c], A[a][d], A[b][c], A[b][d]);
            if (a == b || c == d)
                t /= 2;
            ret += t;
        }
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
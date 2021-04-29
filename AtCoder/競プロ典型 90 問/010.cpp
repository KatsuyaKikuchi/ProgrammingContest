#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll S[2][100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    memset(S, 0, sizeof(S));
    REP(i, N) {
        ll c, t;
        cin >> c >> t;
        c--;
        S[c][i + 1] += t;
    }
    REP(i, N + 1) {
        S[0][i + 1] += S[0][i];
        S[1][i + 1] += S[1][i];
    }
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll l, r;
        cin >> l >> r;
        ll s0 = S[0][r] - S[0][l - 1];
        ll s1 = S[1][r] - S[1][l - 1];
        cout << s0 << " " << s1 << endl;
    }
    return 0;
}
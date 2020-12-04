#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll H, W, K;
string S[10];
string T[10];

ll solve(ll h, ll w) {
    REP(i, H) {
        T[i] = S[i];
    }
    REP(i, H) {
        REP(j, W) {
            if (((h >> i) & 1) == 1 || ((w >> j) & 1) == 1)
                T[i][j] = 'R';
        }
    }
    ll ret = 0;
    REP(i, H) {
        REP(j, W) {
            if (T[i][j] == '#')
                ret++;
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W >> K;
    REP(i, H) {
        cin >> S[i];
    }

    ll ans = 0;
    REP(h, pow(2, H)) {
        REP(w, pow(2, W)) {
            if (solve(h, w) == K)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
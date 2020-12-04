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
string S[15];

ll solve(ll b) {
    ll d = 1;
    REP(i, H) {
        if ((b >> i) & 1)
            d++;
    }
    vector<ll> v(d, 0);

    ll ret = d - 1;
    REP(w, W) {
        ll m = 0;
        ll index = 0;
        vector<ll> u(d, 0);
        REP(h, H) {
            if (S[h][w] == '1')
                m = std::max(m, (++u[index]) + v[index]);
            if ((b >> h) & 1)
                index++;
        }

        if (m > K) {
            REP(i, v.size()) {
                if (u[i] > K)
                    return INF;
                v[i] = 0;
            }
            ret++;
        }
        REP(i, u.size()) {
            v[i] += u[i];
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

    ll ans = INF;
    REP(b, pow(2, H - 1)) {
        ans = std::min(ans, solve(b));
    }
    cout << ans << endl;
    return 0;
}